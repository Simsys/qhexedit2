#ifndef QHEXEDIT_P_H
#define QHEXEDIT_P_H

/** \cond docNever */


#include <QtGui>

class QHexEditPrivate : public QWidget
{
Q_OBJECT

public:
    QHexEditPrivate(QScrollArea *parent);

    void setAddressOffset(int offset);
    int addressOffset();

    void setData(QByteArray const &data);
    QByteArray data();

    void setAddressAreaColor(QColor const &color);
    QColor addressAreaColor();

    void setHighlightingColor(QColor const &color);
    QColor highlightingColor();

    void setSelectionColor(QColor const &color);
    QColor selectionColor();

    void setOverwriteMode(bool overwriteMode);
    bool overwriteMode();

    void insert(int index, const QByteArray & ba);
    void insert(int index, char ch);
    void remove(int index, int len=1);
    void replace(int index, const QByteArray & ba);
    void replace(int index, int length, const QByteArray & ba);

    void setAddressArea(bool addressArea);
    void setAddressWidth(int addressWidth);
    void setAsciiArea(bool asciiArea);
    void setHighlighting(bool mode);
    virtual void setFont(const QFont &font);

signals:
    void currentAddressChanged(int address);
    void currentSizeChanged(int size);
    void dataChanged();
    void overwriteModeChanged(bool state);

protected:
    void keyPressEvent(QKeyEvent * event);
    void mouseMoveEvent(QMouseEvent * event);
    void mousePressEvent(QMouseEvent * event);

    void paintEvent(QPaintEvent *event);

    int getCursorPos(QPoint pos);               // calc cursorpos from graphics position. DOES NOT STORE POSITION
    int getCursorPos();                         // get actual cursorpos
    void setCursorPos(int position);            // set cursorpos to position

    void resetSelection(int pos);
    void setSelection(int pos);                 // set min (if below init) or max (if greater init)
    int getSelectionBegin();
    int getSelectionEnd();


private slots:
    void updateCursor();

private:
    void adjust();

    QColor _addressAreaColor;
    QColor _highlightingColor;
    QColor _selectionColor;
    QByteArray _data;
    QByteArray _changedData;
    QScrollArea *_scrollArea;
    QTimer _cursorTimer;

    bool _blink;                            // true: then cursor blinks
    bool _addressArea;                      // left area of QHexEdit
    bool _asciiArea;                        // medium area
    bool _highlighting;                     // highlighting of changed bytes
    bool _overwriteMode;                    // true: then input overwrites existen bytes

    int _addressNumbers;                    // wanted width of address area
    int _realAddressNumbers;                // real width of address area (can be greater then wanted width)
    int _addressOffset;                     // will be added to the real addres inside bytearray
    int _charWidth, _charHeight;            // char dimensions (dpendend on font)
    int _cursorX, _cursorY;                 // graphics position of the cursor
    int _cursorPosition;                    // charakter positioin in stream (on byte ends in to steps)
    int _xPosAdr, _xPosHex, _xPosAscii;     // graphics x-position of the areas
    int _size;                              // size of data

    int _selectionBegin;                    // First selected char
    int _selectionEnd;                      // Last selected char
    int _selectionInit;                     // That's, where we pressed the mouse button
};

/** \endcond docNever */

#endif

