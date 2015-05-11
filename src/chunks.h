#ifndef JUNK_H
#define JUNK_H

#include <QtCore>

struct Chunk
{
    QByteArray data;
    QByteArray dataChanged;
    qint64 absPos;
};

class Chunks
{
public:
    Chunks();
    Chunks(QIODevice &ioDevice);

    QByteArray data(qint64 pos, qint64 count, QByteArray *highlighted=0);
    bool data(QIODevice &iODevice, qint64 pos=0, qint64 count=-1);

    void setDataChanged(qint64 pos, bool dataChanged);
    bool dataChanged(qint64 pos);

    bool removeAt(qint64 pos);
    bool insert(qint64 pos, char b);
    bool overwrite(qint64 pos, char b);
    char operator[](qint64 pos);
    qint64 pos();
    bool setIODevice(QIODevice &ioDevice);
    qint64 size();


private:
    int getChunkIndex(qint64 absPos);

    QIODevice * _ioDevice;
    qint64 _pos;
    qint64 _size;
    QList<Chunk> _chunks;

#ifdef MODUL_TEST
public:
    int chunkSize();
#endif
};

#endif // JUNK_H
