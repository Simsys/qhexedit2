/*
* QHexEdit is a Hex Editor Widget for the Qt Framework
* Copyright (C) 2010-2025 Winfried Simon
*
* This library is free software; you can redistribute it and/or
* modify it under the terms of the GNU Lesser General Public
* License as published by the Free Software Foundation; either
* version 2.1 of the License, or (at your option) any later version.
*
* This library is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
* Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public
* License along with this library; if not, see
* https://www.gnu.org/licenses/
*/

#include <QApplication>
#include <QColorDialog>
#include <QFontDialog>

#include "optionsdialog.h"
#include "ui_optionsdialog.h"

OptionsDialog::OptionsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OptionsDialog)
{
    ui->setupUi(this);

    QPalette palette;
    QColor darkGray(53, 53, 53);
    QColor gray(128, 128, 128);
    QColor black(25, 25, 25);
    QColor blue(42, 130, 218);

    palette.setColor(QPalette::Window, darkGray);
    palette.setColor(QPalette::WindowText, Qt::white);
    palette.setColor(QPalette::Base, black);
    palette.setColor(QPalette::AlternateBase, darkGray);
    palette.setColor(QPalette::ToolTipBase, blue);
    palette.setColor(QPalette::ToolTipText, Qt::white);
    palette.setColor(QPalette::Text, Qt::white);
    palette.setColor(QPalette::Button, darkGray);
    palette.setColor(QPalette::ButtonText, Qt::white);
    palette.setColor(QPalette::Link, blue);
    palette.setColor(QPalette::Highlight, blue);
    palette.setColor(QPalette::HighlightedText, Qt::black);

    palette.setColor(QPalette::Active, QPalette::Button, gray.darker());
    palette.setColor(QPalette::Disabled, QPalette::ButtonText, gray);
    palette.setColor(QPalette::Disabled, QPalette::WindowText, gray);
    palette.setColor(QPalette::Disabled, QPalette::Text, gray);
    palette.setColor(QPalette::Disabled, QPalette::Light, darkGray);
    palette.setColor(QPalette::Light, darkGray);

    _darkMode = palette;
    _defaultMode = QApplication::palette();

    QSettings settings;
    if (settings.contains("Theme"))
        this->ui->cbPalette->setCurrentIndex(settings.value("Theme").toInt());
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

void OptionsDialog::on_pbWidgetFont_clicked()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, ui->leWidgetFont->font(), this);
    if (ok)
        ui->leWidgetFont->setFont(font);
}

void OptionsDialog::on_cbPalette_currentIndexChanged(int index)
{
    QSettings settings;
    settings.setValue("Theme", index);
    
    switch (index)
    {
        case 1:
            qApp->setPalette(_darkMode);
            break;
        default:
            qApp->setPalette(_defaultMode);
            break;
    }
}