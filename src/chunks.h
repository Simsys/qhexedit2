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

#include <QObject>

class QIODevice;

struct Chunk
{
    QByteArray data;
    QByteArray dataChanged;
    qint64 absPos;
    int origLen;

    Chunk(qint64 pos = 0);
    Chunk(qint64 pos, const QByteArray & buffer);
    bool contains(qint64 pos) const;
    bool isUnchanged() const;
    void mergeWith(const QByteArray & buffer);
    bool mergeWith(const Chunk & chunk);

};

bool operator < (const Chunk & lhs, const Chunk & rhs);
bool operator < (const Chunk & chunk, qint64 pos);
bool operator < (qint64 pos, const Chunk & chunk);

class Chunks: public QObject
{
Q_OBJECT
public:
    // Constructors and file settings
    Chunks(QObject *parent = 0);
    Chunks(QIODevice &ioDevice, QObject *parent = 0);
    bool setIODevice(QIODevice &ioDevice);

    // Getting data out of Chunks
    QByteArray data(qint64 pos=0, qint64 count=-1, QByteArray *highlighted=0);
    bool write(QIODevice &iODevice, qint64 pos=0, qint64 count=-1);

    // Set and get highlighting infos
    void setDataChanged(qint64 pos, bool dataChanged);
    bool dataChanged(qint64 pos);

    // Search API
    qint64 indexOf(const QByteArray &ba, qint64 from);
    qint64 lastIndexOf(const QByteArray &ba, qint64 from);

    // Char manipulations
    bool insert(qint64 pos, char b);
    bool overwrite(qint64 pos, char b);
    bool removeAt(qint64 pos);

    // Utility functions
    char operator[](qint64 pos);
    qint64 pos();
    qint64 size();

private:
    int getChunkIndex(qint64 absPos);
    void addChunkData(qint64 & readPos, int & readSize, int & insertIdx, qint64 absPos, bool merge);
    QByteArray readData(qint64 readPos, qint64 maxSize);

    QIODevice * _ioDevice;
    qint64 _pos;
    qint64 _size;
    QList<Chunk> _chunks;

#ifdef MODUL_TEST
public:
    int chunkSize();
#endif
};

/** \endcond docNever */

#endif // CHUNKS_H
