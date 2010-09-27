#ifndef QHEXEDIT_H
#define QHEXEDIT_H

#include <QtGui>
#include "qhexedit_p.h"

/** \mainpage
QHexEdit is a binary editor widget for Qt.

\version Version 0.3.1
\image html hexedit.png
*/


/*!  QHexEdit is a binary editor widget.
QHexEdit is a hex editor widget written in C++ for the Qt (Qt4) framework.
It is a simple editor for binary data, just like QPlainTextEdit is for text data.
QHexEdit inherits the functionality of QScrollArea.

QHexEdit takes the data of a QByteArray (setData()) and shows it to you.
You can use the mouse or the keyboard to navigate inside the widget. If you hit
the keys (0..9, a..f) you will change the data. Changed data is highlighted and
can be accessed via data().

There are some limitations: no inserting, only overwriting is supported. The size
of data has to be below 10 megabytes, otherwise the scroll sliders ard not shown.
Copy and paste functionality is also a subject of a later release.
*/
        class QHexEdit : public QScrollArea
{
    Q_OBJECT
    Q_PROPERTY(QByteArray data READ data WRITE setData)
    Q_PROPERTY(int addressOffset READ addressOffset WRITE setAddressOffset)

public:
    QHexEdit(QWidget *parent = 0);

    /*! Loads the data into the widget.
    \param data A QByteArray containing the data to edit.
    */
    void setData(QByteArray const &data);
    /*! Givs the (edited) data back. */
    QByteArray data();

    /*! Set the font of the widget. Please use fixed width fonts like Mono or Courier.*/
    void setFont(const QFont &);

    /*! A offset in the address area (left side) is sometimes usefull, whe you show
      only a segment of a complete memory picture.
      \param offset The offset to add to the address.
    */
    void setAddressOffset(int offset);

    /*! Read the offset back. */
    int addressOffset();

public slots:

    /*! Set the minimum width of the address area.
      \param addressWidth Width in characters.
      */
    void setAddressWidth(int addressWidth);

    /*! Switch the address area on or off.
      \param addressArea true (show it), false (hide it).
      */
    void setAddressArea(bool addressArea);

    /*! Switch the address area on or off.
      \param addressArea 0 (hide), all other values show it.
      */
    void setAddressArea(int addressArea);

    /*! Switch the ascii area on or off.
      \param asciiArea true (show it), false (hide it).
      */
    void setAsciiArea(bool asciiArea);

    /*! Switch the ascii area on or off.
      \param asciiArea true (show it), false (hide it).
      */
    void setAsciiArea(int asciiArea);

signals:

    /*! Contains the address, where the cursor is located. */
    void currentAddress(int address);

    /*! The signalis emited every time, the data is changed. */
    void dataChanged();

    /** \cond docNever */
private:
    QHexEditPrivate *qHexEdit_p;
    QHBoxLayout *layout;
    QScrollArea *scrollArea;
    /** \endcond docNever */
};

#endif

