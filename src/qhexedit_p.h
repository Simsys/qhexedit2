#ifndef QHEXEDIT_P_H
#define QHEXEDIT_P_H

/** \cond docNever */


#include <QtGui>

class QHexEditPrivate : public QWidget
{
Q_OBJECT

public:
    QHexEditPrivate(QScrollArea *parent);
    virtual void setFont(const QFont &font);

    void setAddressOffset(int offset);
    int addressOffset();

    void setData(QByteArray const &data);
    QByteArray data();

    void setAddressArea(bool addressArea);
    void setAsciiArea(bool asciiArea);
    void setAddressWidth(int addressWidth);
    void setOverwriteMode(bool overwriteMode);

signals:
    void currentAddress(int address);
    void dataChanged();

protected:
    void keyPressEvent(QKeyEvent * event);
    void mousePressEvent(QMouseEvent * event);
    void paintEvent(QPaintEvent *event);
    void setCursorPos(QPoint pos);
    void setCursorPos(int position);

private slots:
    void updateCursor();

private:
    void adjust();

    QByteArray _data;
    QByteArray _originalData;
    QTimer _cursorTimer;
    QScrollArea *_scrollArea;

    bool _blink;
    bool _addressArea;
    bool _asciiArea;
    bool _overwriteMode;

    int _addressNumbers, _realAddressNumbers;
    int _addressOffset;
    int _charWidth, _charHeight;
    int _cursorX, _cursorY, _cursorWidth, _cursorHeight, _cursorPosition;
    int _xPosAdr, _xPosHex, _xPosAscii;
};

/** \endcond docNever */

#endif

