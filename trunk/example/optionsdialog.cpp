#include "optionsdialog.h"
#include "ui_optionsdialog.h"

OptionsDialog::OptionsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OptionsDialog)
{
    ui->setupUi(this);
    readSettings();
    writeSettings();
}

OptionsDialog::~OptionsDialog()
{
    delete ui;
}

void OptionsDialog::accept()
{
    writeSettings();
    emit accepted();
    QDialog::hide();
}

void OptionsDialog::readSettings()
{
    QSettings settings;

    ui->cbAddressArea->setChecked(settings.value("AddressArea", true).toBool());
    ui->cbAsciiArea->setChecked(settings.value("AsciiArea", true).toBool());
    ui->cbHighlighting->setChecked(settings.value("Highlighting", true).toBool());
    ui->cbOverwriteMode->setChecked(settings.value("OverwriteMode", true).toBool());

    setPbHighlightingColor(settings.value("HighlightingColor", QColor(0xff, 0xff, 0x99, 0xff)).value<QColor>());
    setPbAddressAreaColor(settings.value("AddressAreaColor", QColor(0xd4, 0xd4, 0xd4, 0xff)).value<QColor>());
    setPbSelectionColor(settings.value("SelectionColor", QColor(0x6d, 0x9e, 0xff, 0xff)).value<QColor>());
    ui->leWidgetFont->setFont(settings.value("WidgetFont", QFont("Courier", 10)).value<QFont>());

    ui->sbAddressAreaWidth->setValue(settings.value("AddressAreaWidth", 4).toInt());
}

void OptionsDialog::writeSettings()
{
    QSettings settings;
    settings.setValue("AddressArea", ui->cbAddressArea->isChecked());
    settings.setValue("AsciiArea", ui->cbAsciiArea->isChecked());
    settings.setValue("Highlighting", ui->cbHighlighting->isChecked());
    settings.setValue("OverwriteMode", ui->cbOverwriteMode->isChecked());

    settings.setValue("HighlightingColor", ui->lbHighlightingColor->palette().color(QPalette::Background));
    settings.setValue("AddressAreaColor", ui->lbAddressAreaColor->palette().color(QPalette::Background));
    settings.setValue("SelectionColor", ui->lbSelectionColor->palette().color(QPalette::Background));
    settings.setValue("WidgetFont",ui->leWidgetFont->font());

    settings.setValue("AddressAreaWidth", ui->sbAddressAreaWidth->value());
}

void OptionsDialog::setPbHighlightingColor(const QColor &color)
{
    QPalette palette = ui->lbHighlightingColor->palette();
    palette.setColor(QPalette::Background, color);
    ui->lbHighlightingColor->setPalette(palette);
    ui->lbHighlightingColor->setAutoFillBackground(true);
}

void OptionsDialog::setPbAddressAreaColor(const QColor &color)
{
    QPalette palette = ui->lbAddressAreaColor->palette();
    palette.setColor(QPalette::Background, color);
    ui->lbAddressAreaColor->setPalette(palette);
    ui->lbAddressAreaColor->setAutoFillBackground(true);
}

void OptionsDialog::setPbSelectionColor(const QColor &color)
{
    QPalette palette = ui->lbSelectionColor->palette();
    palette.setColor(QPalette::Background, color);
    ui->lbSelectionColor->setPalette(palette);
    ui->lbSelectionColor->setAutoFillBackground(true);
}

void OptionsDialog::on_pbHighlightingColor_clicked()
{
    QColor color = QColorDialog::getColor(ui->lbHighlightingColor->palette().color(QPalette::Background), this);
    setPbHighlightingColor(color);
}

void OptionsDialog::on_pbAddressAreaColor_clicked()
{
    QColor color = QColorDialog::getColor(ui->lbAddressAreaColor->palette().color(QPalette::Background), this);
    setPbAddressAreaColor(color);
}

void OptionsDialog::on_pbSelectionColor_clicked()
{
    QColor color = QColorDialog::getColor(ui->lbSelectionColor->palette().color(QPalette::Background), this);
    setPbSelectionColor(color);
}

void OptionsDialog::on_pbWidgetFont_clicked()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, ui->leWidgetFont->font(), this);
    if (ok)
        ui->leWidgetFont->setFont(font);
}
