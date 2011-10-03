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

    void setData(const QByteArray &);
    QByteArray data();
    void setAddressOffset(int);
    int addressOffset();
    void setAddressAreaColor(const QColor &);
    QColor addressAreaColor();
    void setHighlightingColor(const QColor &);
    QColor highlightingColor();
    void setSelectionColor(const QColor &);
    QColor selectionColor();
    void setOverwriteMode(bool);
    bool overwriteMode();
    void setReadOnly(bool);
    bool isReadOnly();
    void setFont(const QFont &);
    QFont font();

    void insert(int, QByteArray &);
    void insert(int, char);
    void remove(int, int);
    QString toReadableString();
    QString selectionToReadableString();

public slots:
    void redo();
    void setAddressWidth(int);
    void setAddressArea(bool);
    void setAsciiArea(bool);
    void setHighlighting(bool);
    void undo();

signals:
    void currentAddressChanged(int);
    void currentSizeChanged(int);
    void dataChanged();
    void overwriteModeChanged(bool);
};
