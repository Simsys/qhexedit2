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

    setPbHighlightingColor(settings.value("HighlightingColor", QColor(Qt::yellow).lighter(160)).value<QColor>());
    setPbAddressAreaColor(settings.value("AddressAreaColor", QColor(Qt::lightGray).lighter(110)).value<QColor>());
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
    settings.setValue("WidgetFont",ui->leWidgetFont->font());

    settings.setValue("AddressAreaWidth", ui->sbAddressAreaWidth->value());
}

void OptionsDialog::recect()
{
    QDialog::hide();
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

void OptionsDialog::on_pbWidgetFont_clicked()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, ui->leWidgetFont->font(), this);
    if (ok)
        ui->leWidgetFont->setFont(font);
}
