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
#ifndef OPTIONSDIALOG_H
#define OPTIONSDIALOG_H

#include <QtCore>
#include <QDialog>

#include "../src/qhexedit.h"

namespace Ui {
    class OptionsDialog;
}

class OptionsDialog : public QDialog
{
    Q_OBJECT

public:
    OptionsDialog(QWidget *parent = 0);
    Ui::OptionsDialog *ui;
    void load(QHexEdit *hexedit);
    void save(QHexEdit *hexedit);

public slots:
    virtual void accept();

private slots:
    void on_pbHighlightingColor_clicked();
    void on_pbWidgetFont_clicked();
    void on_cbPalette_currentIndexChanged(int index);

private:
    void setColor(QWidget *widget, QColor color);

    QPalette _defaultMode;
    QPalette _darkMode;
};

#endif // OPTIONSDIALOG_H
