#ifndef OPTIONSDIALOG_H
#define OPTIONSDIALOG_H

#include <QtCore>
#include <QtGui>

namespace Ui {
    class OptionsDialog;
}

class OptionsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit OptionsDialog(QWidget *parent = 0);
    ~OptionsDialog();
    Ui::OptionsDialog *ui;

signals:
    void accepted();

public slots:
    virtual void accept();
    virtual void recect();

private slots:
    void setPbAddressAreaColor(const QColor &color);
    void setPbHighlightingColor(const QColor &color);
    void on_pbHighlightingColor_clicked();
    void on_pbAddressAreaColor_clicked();

private:
    void readSettings();
    void writeSettings();
};

#endif // OPTIONSDIALOG_H
