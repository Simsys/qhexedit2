/********************************************************************************
** Form generated from reading UI file 'optionsdialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONSDIALOG_H
#define UI_OPTIONSDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_OptionsDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *gbFlags;
    QGridLayout *gridLayout_2;
    QCheckBox *cbReadOnly;
    QCheckBox *cbHighlighting;
    QCheckBox *cbOverwriteMode;
    QCheckBox *cbAddressArea;
    QCheckBox *cbAsciiArea;
    QGroupBox *gbColors;
    QGridLayout *gridLayout;
    QPushButton *pbHighlightingColor;
    QLabel *lbHighlightingColor;
    QPushButton *pbAddressAreaColor;
    QLabel *lbAddressAreaColor;
    QLabel *lbSelectionColor;
    QPushButton *pbSelectionColor;
    QPushButton *pbWidgetFont;
    QLineEdit *leWidgetFont;
    QGroupBox *gbAddressAreaWidth;
    QGridLayout *gridLayout_3;
    QLabel *lbAddressAreaWidth;
    QSpinBox *sbAddressAreaWidth;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *OptionsDialog)
    {
        if (OptionsDialog->objectName().isEmpty())
            OptionsDialog->setObjectName(QString::fromUtf8("OptionsDialog"));
        OptionsDialog->resize(395, 362);
        verticalLayout = new QVBoxLayout(OptionsDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gbFlags = new QGroupBox(OptionsDialog);
        gbFlags->setObjectName(QString::fromUtf8("gbFlags"));
        gridLayout_2 = new QGridLayout(gbFlags);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        cbReadOnly = new QCheckBox(gbFlags);
        cbReadOnly->setObjectName(QString::fromUtf8("cbReadOnly"));

        gridLayout_2->addWidget(cbReadOnly, 3, 0, 1, 1);

        cbHighlighting = new QCheckBox(gbFlags);
        cbHighlighting->setObjectName(QString::fromUtf8("cbHighlighting"));

        gridLayout_2->addWidget(cbHighlighting, 2, 0, 1, 1);

        cbOverwriteMode = new QCheckBox(gbFlags);
        cbOverwriteMode->setObjectName(QString::fromUtf8("cbOverwriteMode"));

        gridLayout_2->addWidget(cbOverwriteMode, 1, 0, 1, 1);

        cbAddressArea = new QCheckBox(gbFlags);
        cbAddressArea->setObjectName(QString::fromUtf8("cbAddressArea"));

        gridLayout_2->addWidget(cbAddressArea, 1, 1, 1, 1);

        cbAsciiArea = new QCheckBox(gbFlags);
        cbAsciiArea->setObjectName(QString::fromUtf8("cbAsciiArea"));

        gridLayout_2->addWidget(cbAsciiArea, 2, 1, 1, 1);


        verticalLayout->addWidget(gbFlags);

        gbColors = new QGroupBox(OptionsDialog);
        gbColors->setObjectName(QString::fromUtf8("gbColors"));
        gridLayout = new QGridLayout(gbColors);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pbHighlightingColor = new QPushButton(gbColors);
        pbHighlightingColor->setObjectName(QString::fromUtf8("pbHighlightingColor"));

        gridLayout->addWidget(pbHighlightingColor, 0, 0, 1, 1);

        lbHighlightingColor = new QLabel(gbColors);
        lbHighlightingColor->setObjectName(QString::fromUtf8("lbHighlightingColor"));
        lbHighlightingColor->setMinimumSize(QSize(100, 0));
        lbHighlightingColor->setMaximumSize(QSize(16777215, 16777215));
        lbHighlightingColor->setFrameShape(QFrame::Panel);
        lbHighlightingColor->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(lbHighlightingColor, 0, 1, 1, 1);

        pbAddressAreaColor = new QPushButton(gbColors);
        pbAddressAreaColor->setObjectName(QString::fromUtf8("pbAddressAreaColor"));

        gridLayout->addWidget(pbAddressAreaColor, 1, 0, 2, 1);

        lbAddressAreaColor = new QLabel(gbColors);
        lbAddressAreaColor->setObjectName(QString::fromUtf8("lbAddressAreaColor"));
        lbAddressAreaColor->setMinimumSize(QSize(100, 0));
        lbAddressAreaColor->setMaximumSize(QSize(16777215, 16777215));
        lbAddressAreaColor->setFrameShape(QFrame::Panel);
        lbAddressAreaColor->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(lbAddressAreaColor, 1, 1, 2, 1);

        lbSelectionColor = new QLabel(gbColors);
        lbSelectionColor->setObjectName(QString::fromUtf8("lbSelectionColor"));
        lbSelectionColor->setMinimumSize(QSize(100, 0));
        lbSelectionColor->setMaximumSize(QSize(16777215, 16777215));
        lbSelectionColor->setFrameShape(QFrame::Panel);
        lbSelectionColor->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(lbSelectionColor, 3, 1, 1, 1);

        pbSelectionColor = new QPushButton(gbColors);
        pbSelectionColor->setObjectName(QString::fromUtf8("pbSelectionColor"));

        gridLayout->addWidget(pbSelectionColor, 3, 0, 1, 1);

        pbWidgetFont = new QPushButton(gbColors);
        pbWidgetFont->setObjectName(QString::fromUtf8("pbWidgetFont"));

        gridLayout->addWidget(pbWidgetFont, 4, 0, 1, 1);

        leWidgetFont = new QLineEdit(gbColors);
        leWidgetFont->setObjectName(QString::fromUtf8("leWidgetFont"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(leWidgetFont->sizePolicy().hasHeightForWidth());
        leWidgetFont->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("Courier New"));
        font.setPointSize(10);
        leWidgetFont->setFont(font);

        gridLayout->addWidget(leWidgetFont, 4, 1, 1, 1);


        verticalLayout->addWidget(gbColors);

        gbAddressAreaWidth = new QGroupBox(OptionsDialog);
        gbAddressAreaWidth->setObjectName(QString::fromUtf8("gbAddressAreaWidth"));
        gridLayout_3 = new QGridLayout(gbAddressAreaWidth);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        lbAddressAreaWidth = new QLabel(gbAddressAreaWidth);
        lbAddressAreaWidth->setObjectName(QString::fromUtf8("lbAddressAreaWidth"));

        gridLayout_3->addWidget(lbAddressAreaWidth, 0, 0, 1, 1);

        sbAddressAreaWidth = new QSpinBox(gbAddressAreaWidth);
        sbAddressAreaWidth->setObjectName(QString::fromUtf8("sbAddressAreaWidth"));
        sbAddressAreaWidth->setMinimum(1);
        sbAddressAreaWidth->setMaximum(6);
        sbAddressAreaWidth->setValue(4);

        gridLayout_3->addWidget(sbAddressAreaWidth, 0, 1, 1, 1);


        verticalLayout->addWidget(gbAddressAreaWidth);

        verticalSpacer = new QSpacerItem(20, 28, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(OptionsDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);

        QWidget::setTabOrder(pbHighlightingColor, pbAddressAreaColor);
        QWidget::setTabOrder(pbAddressAreaColor, buttonBox);

        retranslateUi(OptionsDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), OptionsDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), OptionsDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(OptionsDialog);
    } // setupUi

    void retranslateUi(QDialog *OptionsDialog)
    {
        OptionsDialog->setWindowTitle(QApplication::translate("OptionsDialog", "QHexEdit - Options", 0, QApplication::UnicodeUTF8));
        gbFlags->setTitle(QApplication::translate("OptionsDialog", "Flags", 0, QApplication::UnicodeUTF8));
        cbReadOnly->setText(QApplication::translate("OptionsDialog", "ReadOnly", 0, QApplication::UnicodeUTF8));
        cbHighlighting->setText(QApplication::translate("OptionsDialog", "Higlighting", 0, QApplication::UnicodeUTF8));
        cbOverwriteMode->setText(QApplication::translate("OptionsDialog", "Overwrite Mode", 0, QApplication::UnicodeUTF8));
        cbAddressArea->setText(QApplication::translate("OptionsDialog", "Address Area", 0, QApplication::UnicodeUTF8));
        cbAsciiArea->setText(QApplication::translate("OptionsDialog", "Ascii Area", 0, QApplication::UnicodeUTF8));
        gbColors->setTitle(QApplication::translate("OptionsDialog", "Colors and Fonts", 0, QApplication::UnicodeUTF8));
        pbHighlightingColor->setText(QApplication::translate("OptionsDialog", "Highlighting Color", 0, QApplication::UnicodeUTF8));
        lbHighlightingColor->setText(QString());
        pbAddressAreaColor->setText(QApplication::translate("OptionsDialog", "Address Area Color", 0, QApplication::UnicodeUTF8));
        lbAddressAreaColor->setText(QString());
        lbSelectionColor->setText(QString());
        pbSelectionColor->setText(QApplication::translate("OptionsDialog", "Selection Color", 0, QApplication::UnicodeUTF8));
        pbWidgetFont->setText(QApplication::translate("OptionsDialog", "Widget Font", 0, QApplication::UnicodeUTF8));
        leWidgetFont->setText(QApplication::translate("OptionsDialog", "01 23 45 67 89 ab cd ef", 0, QApplication::UnicodeUTF8));
        gbAddressAreaWidth->setTitle(QApplication::translate("OptionsDialog", "Address Area", 0, QApplication::UnicodeUTF8));
        lbAddressAreaWidth->setText(QApplication::translate("OptionsDialog", "Address Area Width", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class OptionsDialog: public Ui_OptionsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONSDIALOG_H
