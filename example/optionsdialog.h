#ifndef OPTIONSDIALOG_H
#define OPTIONSDIALOG_H

#include <QtCore>
#include <QDialog>

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
    void show();

public slots:
    virtual void accept();

private slots:
    void on_pbHighlightingColor_clicked();
    void on_pbAddressAreaColor_clicked();
    void on_pbSelectionColor_clicked();
    void on_pbWidgetFont_clicked();

private:

    typedef QMap<QString,QString> LanguageMap;
    const LanguageMap languages = std::map<QString,QString>{
        std::make_pair("DEFAULT", tr("<System Language>")),
        std::make_pair("en_EN", "English"),
        std::make_pair("de_DE", "Deutsch"),
        std::make_pair("cs_CZ", "Čeština"),
        std::make_pair("ru_RU", "Русский")
    };

    void readSettings();
    void writeSettings();
    void setColor(QWidget *widget, QColor color);

};

#endif // OPTIONSDIALOG_H
