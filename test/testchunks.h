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
#ifndef TESTASBYTEARRAY_H
#define TESTASBYTEARRAY_H

#include <QBuffer>
#include <QByteArray>
#include <QString>
#include <QTextStream>

#include "../src/chunks.h"

class TestChunks
{
public:
    TestChunks(QTextStream &log, QString tName, int size, bool random=true, int saveFile=0x7fffffff);
    void insert(qint64 pos, char b);
    void overwrite(qint64 pos, char b);
    void removeAt(qint64 pos);
    void random(int count);
    void compare();


private:
    QByteArray _data, _highlighted, _copy;
    QBuffer _cData;
    Chunks _chunks;
    int _tCnt;
    QString _tName;
    int _saveFile;
    QTextStream *_log;
};

#endif // TESTASBYTEARRAY_H
