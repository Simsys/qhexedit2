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
#ifndef SEARCHDIALOG_H
#define SEARCHDIALOG_H

#include <QDialog>
#include <QtCore>
#include "../src/qhexedit.h"

namespace Ui {
    class SearchDialog;
}

class SearchDialog : public QDialog
{
    Q_OBJECT
public:
    explicit SearchDialog(QHexEdit *hexEdit, QWidget *parent = 0);
    ~SearchDialog();
    qint64 findNext();
    Ui::SearchDialog *ui;

private slots:
    void on_pbFind_clicked();
    void on_pbReplace_clicked();
    void on_pbReplaceAll_clicked();

private:
    QByteArray getContent(int comboIndex, const QString &input);
    qint64 replaceOccurrence(qint64 idx, const QByteArray &replaceBa);

    QHexEdit *_hexEdit;
    QByteArray _findBa;
};

#endif // SEARCHDIALOG_H
