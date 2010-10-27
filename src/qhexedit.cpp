#include <QtGui>

#include "qhexedit.h"


QHexEdit::QHexEdit(QWidget *parent) : QScrollArea(parent)
{
    qHexEdit_p = new QHexEditPrivate(this);
    setWidget(qHexEdit_p);
    setWidgetResizable(true);

    connect(qHexEdit_p, SIGNAL(dataChanged()), this, SIGNAL(dataChanged()));
    connect(qHexEdit_p, SIGNAL(currentAddress(int)), this, SIGNAL(currentAddress(int)));
}

void QHexEdit::setAddressOffset(int offset)
{
    qHexEdit_p->setAddressOffset(offset);
}

int QHexEdit::addressOffset()
{
    return addressOffset();
}

void QHexEdit::setData(const QByteArray &data)
{
    qHexEdit_p->setData(data);
}

QByteArray QHexEdit::data()
{
    return qHexEdit_p->data();
}

void QHexEdit::setFont(const QFont &font)
{
    qHexEdit_p->setFont(font);
}

void QHexEdit::setAddressArea(bool addressArea)
{
    qHexEdit_p->setAddressArea(addressArea);
}

void QHexEdit::setAddressArea(int addressArea)
{
    qHexEdit_p->setAddressArea(addressArea != 0);
}

void QHexEdit::setAddressWidth(int addressWidth)
{
    qHexEdit_p->setAddressWidth(addressWidth);
}

void QHexEdit::setAsciiArea(bool asciiArea)
{
    qHexEdit_p->setAsciiArea(asciiArea);
}

void QHexEdit::setAsciiArea(int asciiArea)
{
    qHexEdit_p->setAsciiArea(asciiArea != 0);
}

void QHexEdit::setOverwriteMode(bool overwriteMode)
{
    qHexEdit_p->setOverwriteMode(overwriteMode);
}

void QHexEdit::setOverwriteMode(int overwriteMode)
{
    qHexEdit_p->setOverwriteMode(overwriteMode != 0);
}
