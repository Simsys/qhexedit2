#ifndef QHEXEDIT_H
#define QHEXEDIT_H

#include <QtGui>
#include "qhexedit_p.h"

/** \mainpage
QHexEdit is a binary editor widget for Qt.

\version Version 0.3.3
\image html hexedit.png
*/


/*!  QHexEdit is a binary editor widget.
QHexEdit is a hex editor widget written in C++ for the Qt (Qt4) framework.
It is a simple editor for binary data, just like QPlainTextEdit is for text data.

QHexEdit takes the data of a QByteArray (setData()) and shows it. You can use the
mouse or the keyboard to navigate inside the widget. If you hit the keys (0..9, a..f)
you will change the data. Changed data is highlighted and can be accessed via data().

Normaly QHexEdit works in the overwrite Mode. You can set overwriteMode() to false and
insert data. In this case the size of data() increases. It is also possible to delete
the byte under the cursor, her the size of data decreases.

There are some limitations: The size of data has in general to be below 10 megabytes,
otherwise the scroll sliders ard not shown and you can't scroll any more. Copy and
paste functionality is perhaps a subject of a later release.
*/
        class QHexEdit : public QScrollArea
{
    Q_OBJECT
    /*! Property data holds the content of QHexEdit.
    */
    Q_PROPERTY(QByteArray data READ data WRITE setData)

    /*! Property addressOffset is added to the Numbers of the Address Area.
    A offset in the address area (left side) is sometimes usefull, whe you show
    only a segment of a complete memory picture.
    */
    Q_PROPERTY(int addressOffset READ addressOffset WRITE setAddressOffset)

public:
    /*! Creates an instance of QHexEdit.
    \param parent Parent widget of QHexEdit.
    */
    QHexEdit(QWidget *parent = 0);

    /*! Loads the data into the widget.
    \param data A QByteArray containing the data to edit.
    */
    void setData(QByteArray const &data);
    /*! Givs the (edited) data back. */
    QByteArray data();

    /*! Set the font of the widget. Please use fixed width fonts like Mono or Courier.*/
    void setFont(const QFont &);

    /*! Set the offset of address area.
    \param offset The offset to add to addresses.
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
      \param asciiArea 0 (hide), all other values show it.
      */
    void setAsciiArea(int asciiArea);

    /*! Switch the ascii area on or off.
      \param overwriteMode true (show it), false (hide it).
      */
    void setOverwriteMode(bool overwriteMode);

    /*! Switch the ascii area on or off.
      \param overwriteMode 0 (hide), all other values show it.
      */
    void setOverwriteMode(int overwriteMode);

signals:

    /*! Contains the address, where the cursor is located. */
    void currentAddress(int address);

    /*! The signal is emited every time, the data is changed. */
    void dataChanged();

    /** \cond docNever */
private:
    QHexEditPrivate *qHexEdit_p;
    QHBoxLayout *layout;
    QScrollArea *scrollArea;
    /** \endcond docNever */
};

#endif

