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
#ifndef CHUNKS_H
#define CHUNKS_H

/** \cond docNever */

/*! The Chunks class is the storage backend for QHexEdit.
 *
 * When QHexEdit loads data, Chunks access them using a QIODevice interface. When the app uses
 * a QByteArray interface, QBuffer is used to provide again a QIODevice like interface. No data
 * will be changed, therefore Chunks opens the QIODevice in QIODevice::ReadOnly mode. After every
 * access Chunks closes the QIODevice, that's why external applications can overwrite files while
 * QHexEdit shows them.
 *
 * When the the user starts to edit the data, Chunks creates a local copy of a chunk of data (4
 * kilobytes) and notes all changes there. Parallel to that chunk, there is a second chunk,
 * which keep track of which bytes are changed and which not.
 *
 */

#include <QtCore>

struct Chunk
{
    QByteArray data;
    QByteArray dataChanged;
    qint64 absPos;
};

class Chunks: public QObject
{
Q_OBJECT
public:
    // Constructors and file settings
    explicit Chunks(QObject *parent);
    Chunks(QIODevice &ioDevice, QObject *parent);
    bool setIODevice(QIODevice &ioDevice);

    // Getting data out of Chunks
    QByteArray data(qint64 pos=0, qint64 count=-1, QByteArray *highlighted=0) const;
    bool write(QIODevice &iODevice, qint64 pos=0, qint64 count=-1) const;

    // Set and get highlighting infos
    void setDataChanged(qint64 pos, bool dataChanged);
    bool dataChanged(qint64 pos) const;

    // Search API
    qint64 indexOf(const QByteArray &ba, qint64 from) const;
    qint64 lastIndexOf(const QByteArray &ba, qint64 from) const;

    // Char manipulations
    bool insert(qint64 pos, char b);
    bool overwrite(qint64 pos, char b);
    bool removeAt(qint64 pos);

    // Utility functions
    char operator[](qint64 pos) const;
    qint64 pos() const;
    qint64 size() const;


private:
    int getChunkIndex(qint64 absPos) const;

    QIODevice * _ioDevice;
    qint64 _pos;
    qint64 _size;
    mutable QList<Chunk> _chunks;

#ifdef MODUL_TEST
public:
    int chunkSize();
#endif
};

/** \endcond docNever */

#endif // CHUNKS_H
