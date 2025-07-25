/*
* QHexEdit is a Hex Editor Widget for the Qt Framework
* Copyright (C) 2010-2025 Winfried Simon
*
* This library is free software; you can redistribute it and/or
* modify it under the terms of the GNU Lesser General Public
* License as published by the Free Software Foundation; either
* version 2.1 of the License, or (at your option) any later version.
*
* This library is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
* Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public
* License along with this library; if not, see
* https://www.gnu.org/licenses/
*/
#include "commands.h"
#include <QUndoCommand>


// Helper class to store single byte commands
class CharCommand : public QUndoCommand
{
public:
    enum CCmd {insert, removeAt, overwrite};

    CharCommand(Chunks * chunks, CCmd cmd, qint64 charPos, char newChar,
                       QUndoCommand *parent=nullptr);

    void undo();
    void redo();
    bool mergeWith(const QUndoCommand *command);
    int id() const { return 1234; }

private:
    Chunks * _chunks;
    qint64 _charPos;
    bool _wasChanged;
    char _newChar;
    char _oldChar;
    CCmd _cmd;
};

CharCommand::CharCommand(Chunks * chunks, CCmd cmd, qint64 charPos, char newChar, QUndoCommand *parent)
    : QUndoCommand(parent)
    , _chunks(chunks)
    , _charPos(charPos)
    , _wasChanged(false)
    , _newChar(newChar)
    , _oldChar('\0')
    , _cmd(cmd)
{
}

bool CharCommand::mergeWith(const QUndoCommand *command)
{
    const CharCommand *nextCommand = static_cast<const CharCommand *>(command);
    bool result = false;

    if (_cmd != CharCommand::removeAt)
    {
        if (nextCommand->_cmd == overwrite)
            if (nextCommand->_charPos == _charPos)
            {
                _newChar = nextCommand->_newChar;
                result = true;
            }
    }
    return result;
}

void CharCommand::undo()
{
    switch (_cmd)
    {
        case insert:
            _chunks->removeAt(_charPos);
            break;
        case overwrite:
            _chunks->overwrite(_charPos, _oldChar);
            _chunks->setDataChanged(_charPos, _wasChanged);
            break;
        case removeAt:
            _chunks->insert(_charPos, _oldChar);
            _chunks->setDataChanged(_charPos, _wasChanged);
            break;
    }
}

void CharCommand::redo()
{
    switch (_cmd)
    {
        case insert:
            _chunks->insert(_charPos, _newChar);
            break;
        case overwrite:
            _oldChar = (*_chunks)[_charPos];
            _wasChanged = _chunks->dataChanged(_charPos);
            _chunks->overwrite(_charPos, _newChar);
            break;
        case removeAt:
            _oldChar = (*_chunks)[_charPos];
            _wasChanged = _chunks->dataChanged(_charPos);
            _chunks->removeAt(_charPos);
            break;
    }
}

UndoStack::UndoStack(Chunks * chunks, QObject * parent)
    : QUndoStack(parent)
{
    _chunks = chunks;
    this->setUndoLimit(1000);
}

void UndoStack::insert(qint64 pos, char c)
{
    if ((pos >= 0) && (pos <= _chunks->size()))
    {
        QUndoCommand *cc = new CharCommand(_chunks, CharCommand::insert, pos, c);
        this->push(cc);
    }
}

void UndoStack::insert(qint64 pos, const QByteArray &ba)
{
    if ((pos >= 0) && (pos <= _chunks->size()))
    {
        QString txt = QString(tr("Inserting %1 bytes")).arg(ba.size());
        beginMacro(txt);
        for (int idx=0; idx < ba.size(); idx++)
        {
            QUndoCommand *cc = new CharCommand(_chunks, CharCommand::insert, pos + idx, ba.at(idx));
            this->push(cc);
        }
        endMacro();
    }
}

void UndoStack::removeAt(qint64 pos, qint64 len)
{
    if ((pos >= 0) && (pos < _chunks->size()))
    {
        if (len==1)
        {
            QUndoCommand *cc = new CharCommand(_chunks, CharCommand::removeAt, pos, char(0));
            this->push(cc);
        }
        else
        {
            QString txt = QString(tr("Delete %1 chars")).arg(len);
            beginMacro(txt);
            for (qint64 cnt=0; cnt<len; cnt++)
            {
                QUndoCommand *cc = new CharCommand(_chunks, CharCommand::removeAt, pos, char(0));
                push(cc);
            }
            endMacro();
        }
    }
}

void UndoStack::overwrite(qint64 pos, char c)
{
    if ((pos >= 0) && (pos < _chunks->size()))
    {
        QUndoCommand *cc = new CharCommand(_chunks, CharCommand::overwrite, pos, c);
        this->push(cc);
    }
}

void UndoStack::overwrite(qint64 pos, int len, const QByteArray &ba)
{
    if ((pos >= 0) && (pos < _chunks->size()))
    {
        QString txt = QString(tr("Overwrite %1 chars")).arg(len);
        beginMacro(txt);
        removeAt(pos, len);
        insert(pos, ba);
        endMacro();
    }
}
