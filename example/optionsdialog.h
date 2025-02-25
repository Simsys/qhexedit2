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
