#include "chunks.h"
#include <limits.h>

#define NORMAL 0
#define HIGHLIGHTED 1

#define BUFFER_SIZE 0x10000
#define CHUNK_SIZE 0x1000
#define READ_CHUNK_MASK 0xfffffffffffff000

Chunks::Chunks(QIODevice &ioDevice)
{
    setIODevice(ioDevice);
}

Chunks::Chunks()
{
    QBuffer * buf = new QBuffer();
    setIODevice(*buf);
}

bool Chunks::insert(qint64 pos, char b)
{
    if ((pos < 0) || (pos > _size))
        return false;
    int chunkIdx;
    if (pos == _size)
        chunkIdx = getChunkIndex(pos-1);
    else
        chunkIdx = getChunkIndex(pos);
    qint64 posInBa = pos - _chunks[chunkIdx].absPos;
    _chunks[chunkIdx].data.insert(posInBa, b);
    _chunks[chunkIdx].dataChanged.insert(posInBa, char(1));
    for (int idx=chunkIdx+1; idx < _chunks.size(); idx++)
        _chunks[idx].absPos += 1;
    _size += 1;
    _pos = pos;
    return true;
}

bool Chunks::overwrite(qint64 pos, char b)
{
    if ((pos < 0) || (pos >= _size))
        return false;
    int chunkIdx = getChunkIndex(pos);
    qint64 posInBa = pos - _chunks[chunkIdx].absPos;
    _chunks[chunkIdx].data[(int)posInBa] = b;
    _chunks[chunkIdx].dataChanged[(int)posInBa] = char(1);
    _pos = pos;
    return true;
}

bool Chunks::removeAt(qint64 pos)
{
    if ((pos < 0) || (pos >= _size))
        return false;
    int chunkIdx = getChunkIndex(pos);
    qint64 posInBa = pos - _chunks[chunkIdx].absPos;
    _chunks[chunkIdx].data.remove(posInBa, 1);
    _chunks[chunkIdx].dataChanged.remove(posInBa, 1);
    for (int idx=chunkIdx+1; idx < _chunks.size(); idx++)
        _chunks[idx].absPos -= 1;
    _size -= 1;
    _pos = pos;
    return true;
}

QByteArray Chunks::data(qint64 pos, qint64 maxSize, QByteArray *highlighted)
{
    qint64 ioDelta = 0;
    int chunkIdx = 0;

    Chunk chunk;
    QByteArray buffer;

    if (highlighted)
        highlighted->clear();
    if ((maxSize - pos) > _size)
        maxSize = _size - pos;
    if (maxSize == -1)
        maxSize = _size;
    _ioDevice->open(QIODevice::ReadOnly);

    while (maxSize > 0)
    {
        chunk.absPos = std::numeric_limits<qint64>::max();
        bool chunksLoopOngoing = true;
        while ((chunkIdx < _chunks.count()) && chunksLoopOngoing)
        {
            chunk = _chunks[chunkIdx];
            if (chunk.absPos > pos)
                chunksLoopOngoing = false;
            else
            {
                chunkIdx += 1;
                ioDelta += CHUNK_SIZE - chunk.data.size();
                qint64 count;
                qint64 chunkOfs = pos - chunk.absPos;
                if (maxSize > ((qint64)chunk.data.size() - chunkOfs))
                    count = (qint64)chunk.data.size() - chunkOfs;
                else
                    count = maxSize;
                if (count > 0)
                {
                    buffer += chunk.data.mid(chunkOfs, (int)count);
                    maxSize -= count;
                    pos += count;
                    if (highlighted)
                        *highlighted += chunk.dataChanged.mid(chunkOfs, (int)count);
                }
            }
        }

        if (_ioDevice && (maxSize > 0) && (pos < chunk.absPos))
        {
            qint64 byteCount;
            QByteArray readBuffer;
            if ((chunk.absPos - pos) > maxSize)
                byteCount = maxSize;
            else
                byteCount = chunk.absPos - pos;

            maxSize -= byteCount;
            if ((pos + ioDelta) < _size)
            {
                _ioDevice->seek(pos + ioDelta);
                readBuffer = _ioDevice->read(byteCount);
                buffer += readBuffer;
                if (highlighted)
                    *highlighted += QByteArray(readBuffer.size(), NORMAL);
                pos += readBuffer.size();
            }
        }
    }
    _ioDevice->close();
    return buffer;
}

bool Chunks::data(QIODevice &iODevice, qint64 pos, qint64 count)
{
    if (count == -1)
        count = _size;
    bool ok = iODevice.open(QIODevice::WriteOnly);
    if (ok)
    {
        for (qint64 idx=pos; idx < count; idx += BUFFER_SIZE)
        {
            QByteArray ba = data(idx, BUFFER_SIZE);
            iODevice.write(ba);
        }
        iODevice.close();
    }
    return ok;
}

void Chunks::setDataChanged(qint64 pos, bool dataChanged)
{
    if ((pos < 0) || (pos >= _size))
        return;
    int chunkIdx = getChunkIndex(pos);
    qint64 posInBa = pos - _chunks[chunkIdx].absPos;
    _chunks[chunkIdx].dataChanged[(int)posInBa] = char(dataChanged);
}

bool Chunks::dataChanged(qint64 pos)
{
    QByteArray highlighted;
    data(pos, 1, &highlighted);
    return bool(highlighted.at(0));
}

char Chunks::operator[](qint64 pos)
{
    return data(pos, 1)[0];
}

qint64 Chunks::pos()
{
    return _pos;
}

bool Chunks::setIODevice(QIODevice &ioDevice)
{
    _ioDevice = &ioDevice;
    bool ok = _ioDevice->open(QIODevice::ReadOnly);
    if (ok)
    {
        _size = _ioDevice->size();
        _pos = 0;
        _ioDevice->close();
    }
    return ok;
}

qint64 Chunks::size()
{
    return _size;
}

int Chunks::getChunkIndex(qint64 absPos)
{
    int foundIdx = -1;
    int insertIdx = 0;
    qint64 ioDelta = 0;


    for (int idx=0; idx < _chunks.size(); idx++)
    {
        Chunk chunk = _chunks[idx];
        if ((absPos >= chunk.absPos) && (absPos < (chunk.absPos + chunk.data.size())))
        {
            foundIdx = idx;
            break;
        }
        if (absPos < chunk.absPos)
        {
            insertIdx = idx;
            break;
        }
        ioDelta += chunk.data.size() - CHUNK_SIZE;
        insertIdx = idx + 1;
    }

    if (foundIdx == -1)
    {
        Chunk newChunk;
        qint64 readAbsPos = absPos - ioDelta;
        qint64 readPos = (readAbsPos & READ_CHUNK_MASK);
        _ioDevice->open(QIODevice::ReadOnly);
        _ioDevice->seek(readPos);
        newChunk.data = _ioDevice->read(CHUNK_SIZE);
        _ioDevice->close();
        newChunk.absPos = absPos - (readAbsPos - readPos);
        newChunk.dataChanged = QByteArray(newChunk.data.size(), char(0));
        _chunks.insert(insertIdx, newChunk);
        foundIdx = insertIdx;
    }
    return foundIdx;
}


#ifdef MODUL_TEST
int Chunks::chunkSize()
{
    return _chunks.size();
}

#endif
