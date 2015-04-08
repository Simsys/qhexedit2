/********************************************************************************
** Form generated from reading UI file 'searchdialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHDIALOG_H
#define UI_SEARCHDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SearchDialog
{
public:
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *gbFind;
    QHBoxLayout *horizontalLayout;
    QComboBox *cbFindFormat;
    QComboBox *cbFind;
    QGroupBox *gbReplace;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *cbReplaceFormat;
    QComboBox *cbReplace;
    QGroupBox *gbOptions;
    QVBoxLayout *verticalLayout_3;
    QCheckBox *cbBackwards;
    QCheckBox *cbPrompt;
    QVBoxLayout *verticalLayout;
    QPushButton *pbFind;
    QPushButton *pbReplace;
    QPushButton *pbReplaceAll;
    QPushButton *pbCancel;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *SearchDialog)
    {
        if (SearchDialog->objectName().isEmpty())
            SearchDialog->setObjectName(QString::fromUtf8("SearchDialog"));
        SearchDialog->resize(436, 223);
        horizontalLayout_3 = new QHBoxLayout(SearchDialog);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gbFind = new QGroupBox(SearchDialog);
        gbFind->setObjectName(QString::fromUtf8("gbFind"));
        horizontalLayout = new QHBoxLayout(gbFind);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        cbFindFormat = new QComboBox(gbFind);
        cbFindFormat->setObjectName(QString::fromUtf8("cbFindFormat"));

        horizontalLayout->addWidget(cbFindFormat);

        cbFind = new QComboBox(gbFind);
        cbFind->setObjectName(QString::fromUtf8("cbFind"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cbFind->sizePolicy().hasHeightForWidth());
        cbFind->setSizePolicy(sizePolicy);
        cbFind->setEditable(true);

        horizontalLayout->addWidget(cbFind);


        verticalLayout_2->addWidget(gbFind);

        gbReplace = new QGroupBox(SearchDialog);
        gbReplace->setObjectName(QString::fromUtf8("gbReplace"));
        horizontalLayout_2 = new QHBoxLayout(gbReplace);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        cbReplaceFormat = new QComboBox(gbReplace);
        cbReplaceFormat->setObjectName(QString::fromUtf8("cbReplaceFormat"));

        horizontalLayout_2->addWidget(cbReplaceFormat);

        cbReplace = new QComboBox(gbReplace);
        cbReplace->setObjectName(QString::fromUtf8("cbReplace"));
        sizePolicy.setHeightForWidth(cbReplace->sizePolicy().hasHeightForWidth());
        cbReplace->setSizePolicy(sizePolicy);
        cbReplace->setEditable(true);

        horizontalLayout_2->addWidget(cbReplace);


        verticalLayout_2->addWidget(gbReplace);

        gbOptions = new QGroupBox(SearchDialog);
        gbOptions->setObjectName(QString::fromUtf8("gbOptions"));
        verticalLayout_3 = new QVBoxLayout(gbOptions);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        cbBackwards = new QCheckBox(gbOptions);
        cbBackwards->setObjectName(QString::fromUtf8("cbBackwards"));

        verticalLayout_3->addWidget(cbBackwards);

        cbPrompt = new QCheckBox(gbOptions);
        cbPrompt->setObjectName(QString::fromUtf8("cbPrompt"));

        verticalLayout_3->addWidget(cbPrompt);


        verticalLayout_2->addWidget(gbOptions);


        horizontalLayout_3->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pbFind = new QPushButton(SearchDialog);
        pbFind->setObjectName(QString::fromUtf8("pbFind"));
        pbFind->setDefault(true);

        verticalLayout->addWidget(pbFind);

        pbReplace = new QPushButton(SearchDialog);
        pbReplace->setObjectName(QString::fromUtf8("pbReplace"));

        verticalLayout->addWidget(pbReplace);

        pbReplaceAll = new QPushButton(SearchDialog);
        pbReplaceAll->setObjectName(QString::fromUtf8("pbReplaceAll"));

        verticalLayout->addWidget(pbReplaceAll);

        pbCancel = new QPushButton(SearchDialog);
        pbCancel->setObjectName(QString::fromUtf8("pbCancel"));

        verticalLayout->addWidget(pbCancel);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_3->addLayout(verticalLayout);

        QWidget::setTabOrder(cbFind, cbReplace);
        QWidget::setTabOrder(cbReplace, cbFindFormat);
        QWidget::setTabOrder(cbFindFormat, cbReplaceFormat);
        QWidget::setTabOrder(cbReplaceFormat, cbBackwards);
        QWidget::setTabOrder(cbBackwards, cbPrompt);
        QWidget::setTabOrder(cbPrompt, pbFind);
        QWidget::setTabOrder(pbFind, pbReplace);
        QWidget::setTabOrder(pbReplace, pbReplaceAll);
        QWidget::setTabOrder(pbReplaceAll, pbCancel);

        retranslateUi(SearchDialog);
        QObject::connect(pbCancel, SIGNAL(clicked()), SearchDialog, SLOT(hide()));

        QMetaObject::connectSlotsByName(SearchDialog);
    } // setupUi

    void retranslateUi(QDialog *SearchDialog)
    {
        SearchDialog->setWindowTitle(QApplication::translate("SearchDialog", "QHexEdit - Find/Replace", 0, QApplication::UnicodeUTF8));
        gbFind->setTitle(QApplication::translate("SearchDialog", "Find", 0, QApplication::UnicodeUTF8));
        cbFindFormat->clear();
        cbFindFormat->insertItems(0, QStringList()
         << QApplication::translate("SearchDialog", "Hex", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SearchDialog", "UTF-8", 0, QApplication::UnicodeUTF8)
        );
        gbReplace->setTitle(QApplication::translate("SearchDialog", "Replace", 0, QApplication::UnicodeUTF8));
        cbReplaceFormat->clear();
        cbReplaceFormat->insertItems(0, QStringList()
         << QApplication::translate("SearchDialog", "Hex", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SearchDialog", "UTF-8", 0, QApplication::UnicodeUTF8)
        );
        gbOptions->setTitle(QApplication::translate("SearchDialog", "Options", 0, QApplication::UnicodeUTF8));
        cbBackwards->setText(QApplication::translate("SearchDialog", "&Backwards", 0, QApplication::UnicodeUTF8));
        cbPrompt->setText(QApplication::translate("SearchDialog", "&Prompt on replace", 0, QApplication::UnicodeUTF8));
        pbFind->setText(QApplication::translate("SearchDialog", "&Find", 0, QApplication::UnicodeUTF8));
        pbFind->setShortcut(QApplication::translate("SearchDialog", "F3", 0, QApplication::UnicodeUTF8));
        pbReplace->setText(QApplication::translate("SearchDialog", "&Replace", 0, QApplication::UnicodeUTF8));
        pbReplaceAll->setText(QApplication::translate("SearchDialog", "Replace &All", 0, QApplication::UnicodeUTF8));
        pbCancel->setText(QApplication::translate("SearchDialog", "&Close", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SearchDialog: public Ui_SearchDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHDIALOG_H
