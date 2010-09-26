#include <QtGui>

#include "qhexedit.h"


QHexEdit::QHexEdit(QWidget *parent) : QWidget(parent)
{
    widgetLayout = new QHBoxLayout(this);
    setBackgroundRole(QPalette::Base);
    scrollArea = new QScrollArea;
    scrollArea->setWidgetResizable(true);

    qhexedit_p = new QHexEditPrivate(scrollArea);
    connect(qhexedit_p, SIGNAL(dataChanged()), this, SIGNAL(dataChanged()));
    connect(qhexedit_p, SIGNAL(currentAddress(int)), this, SIGNAL(currentAddress(int)));

    scrollArea->setWidget(qhexedit_p);
    widgetLayout->addWidget(scrollArea);
}

void QHexEdit::setAddressOffset(int offset)
{
    qhexedit_p->setAddressOffset(offset);
}

int QHexEdit::addressOffset()
{
    return addressOffset();
}

void QHexEdit::setData(const QByteArray &data)
{
    qhexedit_p->setData(data);
}

QByteArray QHexEdit::data()
{
    return qhexedit_p->data();
}

void QHexEdit::setFont(const QFont &font)
{
    qhexedit_p->setFont(font);
}

void QHexEdit::setAddressArea(bool addressArea)
{
    qhexedit_p->setAddressArea(addressArea);
}

void QHexEdit::setAddressArea(int addressArea)
{
    qhexedit_p->setAddressArea(addressArea != 0);
}

void QHexEdit::setAddressWidth(int addressWidth)
{
    qhexedit_p->setAddressWidth(addressWidth);
}

void QHexEdit::setAsciiArea(bool asciiArea)
{
    qhexedit_p->setAsciiArea(asciiArea);
}

void QHexEdit::setAsciiArea(int asciiArea)
{
    qhexedit_p->setAsciiArea(asciiArea != 0);
}
