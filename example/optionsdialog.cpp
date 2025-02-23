
#include <QColorDialog>
#include <QFontDialog>

#include "optionsdialog.h"
#include "ui_optionsdialog.h"

OptionsDialog::OptionsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OptionsDialog)
{
    ui->setupUi(this);
}

void OptionsDialog::accept()
{
    emit accepted();
    QDialog::hide();
}

void OptionsDialog::load(QHexEdit *hexedit)
{
    ui->cbAddressArea->setChecked(hexedit->addressArea());
    ui->cbAsciiArea->setChecked(hexedit->asciiArea());
    ui->cbHighlighting->setChecked(hexedit->highlighting());
    ui->cbOverwriteMode->setChecked(hexedit->overwriteMode());
    ui->cbReadOnly->setChecked(hexedit->isReadOnly());
    ui->cbDynamicBytesPerLine->setChecked(hexedit->dynamicBytesPerLine());

    setColor(ui->lbHighlightingColor, hexedit->highlightingColor());
    setColor(ui->lbAddressAreaColor, hexedit->addressAreaColor());
    setColor(ui->lbSelectionColor, hexedit->selectionColor());
    setColor(ui->lbAddressFontColor, hexedit->addressFontColor());
    setColor(ui->lbAsciiAreaColor, hexedit->asciiAreaColor());
    setColor(ui->lbAsciiFontColor, hexedit->asciiFontColor());
    setColor(ui->lbHexFontColor, hexedit->hexFontColor());

    ui->leWidgetFont->setFont(hexedit->font());
    ui->sbAddressAreaWidth->setValue(hexedit->addressWidth());
    ui->sbBytesPerLine->setValue(hexedit->bytesPerLine());
}

void OptionsDialog::save(QHexEdit *hexedit)
{
    hexedit->setAddressArea(ui->cbAddressArea->isChecked());
    hexedit->setAsciiArea(ui->cbAsciiArea->isChecked());
    hexedit->setHighlighting(ui->cbHighlighting->isChecked());
    hexedit->setOverwriteMode(ui->cbOverwriteMode->isChecked());
    hexedit->setReadOnly(ui->cbReadOnly->isChecked());
    hexedit->setDynamicBytesPerLine(ui->cbDynamicBytesPerLine->isChecked());

    hexedit->setHighlightingColor(ui->lbHighlightingColor->palette().color(QPalette::Window));
    hexedit->setAddressAreaColor(ui->lbAddressAreaColor->palette().color(QPalette::Window));
    hexedit->setSelectionColor(ui->lbSelectionColor->palette().color(QPalette::Window));
    hexedit->setAddressFontColor(ui->lbAddressFontColor->palette().color(QPalette::Window));
    hexedit->setAsciiAreaColor(ui->lbAsciiAreaColor->palette().color(QPalette::Window));
    hexedit->setAsciiFontColor(ui->lbAsciiFontColor->palette().color(QPalette::Window));
    hexedit->setHexFontColor(ui->lbHexFontColor->palette().color(QPalette::Window));
    hexedit->setFont(ui->leWidgetFont->font());

    hexedit->setAddressWidth(ui->sbAddressAreaWidth->value());
    hexedit->setBytesPerLine(ui->sbBytesPerLine->value());
}

void OptionsDialog::setColor(QWidget *widget, QColor color)
{
    QPalette palette = widget->palette();
    palette.setColor(QPalette::Window, color);
    widget->setPalette(palette);
    widget->setAutoFillBackground(true);
}

void OptionsDialog::on_pbHighlightingColor_clicked()
{
    QColor color = QColorDialog::getColor(ui->lbHighlightingColor->palette().color(QPalette::Window), this);
    if (color.isValid())
        setColor(ui->lbHighlightingColor, color);
}

void OptionsDialog::on_pbAddressAreaColor_clicked()
{
    QColor color = QColorDialog::getColor(ui->lbAddressAreaColor->palette().color(QPalette::Window), this);
    if (color.isValid())
        setColor(ui->lbAddressAreaColor, color);
}

void OptionsDialog::on_pbAddressFontColor_clicked()
{
    QColor color = QColorDialog::getColor(ui->lbAddressFontColor->palette().color(QPalette::WindowText), this);
    if (color.isValid())
        setColor(ui->lbAddressFontColor, color);
}

void OptionsDialog::on_pbAsciiAreaColor_clicked()
{
    QColor color = QColorDialog::getColor(ui->lbAsciiAreaColor->palette().color(QPalette::Window), this);
    if (color.isValid())
        setColor(ui->lbAsciiAreaColor, color);
}

void OptionsDialog::on_pbAsciiFontColor_clicked()
{
    QColor color = QColorDialog::getColor(ui->lbAsciiFontColor->palette().color(QPalette::WindowText), this);
    if (color.isValid())
        setColor(ui->lbAsciiFontColor, color);
}

void OptionsDialog::on_pbHexFontColor_clicked()
{
    QColor color = QColorDialog::getColor(ui->lbHexFontColor->palette().color(QPalette::WindowText), this);
    if (color.isValid())
        setColor(ui->lbHexFontColor, color);
}

void OptionsDialog::on_pbSelectionColor_clicked()
{
    QColor color = QColorDialog::getColor(ui->lbSelectionColor->palette().color(QPalette::Window), this);
    if (color.isValid())
        setColor(ui->lbSelectionColor, color);
}

void OptionsDialog::on_pbWidgetFont_clicked()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, ui->leWidgetFont->font(), this);
    if (ok)
        ui->leWidgetFont->setFont(font);
}
