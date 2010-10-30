%Module qhexedit 0

%Import QtCore/QtCoremod.sip
%Import QtGui/QtGuimod.sip

class QHexEdit : QScrollArea
{
%TypeHeaderCode
#include "../src/qhexedit.h"
%End

public:
    explicit QHexEdit(QWidget *parent /TransferThis/ = 0);
    virtual ~QHexEdit();

    void setAddressOffset(int);
    int addressOffset();
    void setData(const QByteArray &);
    QByteArray data();
    void setHighlightingColor(const QColor &);
    QColor highlightingColor();

public slots:
    void setAddressWidth(int);
    void setAddressArea(bool);
    void setAsciiArea(bool);
    void setHighlighting(bool);
    void setOverwriteMode(bool);

signals:
    void currentAddress(int);
    void dataChanged();
    void overwriteModeChanged(bool);
};
