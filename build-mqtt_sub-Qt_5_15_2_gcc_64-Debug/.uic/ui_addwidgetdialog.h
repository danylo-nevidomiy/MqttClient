/********************************************************************************
** Form generated from reading UI file 'addwidgetdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDWIDGETDIALOG_H
#define UI_ADDWIDGETDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddWidgetDialog
{
public:
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QSpacerItem *verticalSpacer_2;
    QComboBox *comboBox;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;
    QWidget *page_2;
    QDialogButtonBox *buttonBox_2;

    void setupUi(QDialog *AddWidgetDialog)
    {
        if (AddWidgetDialog->objectName().isEmpty())
            AddWidgetDialog->setObjectName(QString::fromUtf8("AddWidgetDialog"));
        AddWidgetDialog->resize(400, 200);
        verticalLayout = new QVBoxLayout(AddWidgetDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        stackedWidget = new QStackedWidget(AddWidgetDialog);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        verticalLayout_2 = new QVBoxLayout(page);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(page);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(15);
        label->setFont(font);

        verticalLayout_2->addWidget(label);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        comboBox = new QComboBox(page);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        verticalLayout_2->addWidget(comboBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(page);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        buttonBox_2 = new QDialogButtonBox(page_2);
        buttonBox_2->setObjectName(QString::fromUtf8("buttonBox_2"));
        buttonBox_2->setGeometry(QRect(0, 250, 382, 26));
        buttonBox_2->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        stackedWidget->addWidget(page_2);

        verticalLayout->addWidget(stackedWidget);


        retranslateUi(AddWidgetDialog);
        QObject::connect(buttonBox, SIGNAL(rejected()), AddWidgetDialog, SLOT(reject()));
        QObject::connect(buttonBox, SIGNAL(accepted()), AddWidgetDialog, SLOT(accept()));

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(AddWidgetDialog);
    } // setupUi

    void retranslateUi(QDialog *AddWidgetDialog)
    {
        AddWidgetDialog->setWindowTitle(QCoreApplication::translate("AddWidgetDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("AddWidgetDialog", "Choose Widget Type:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddWidgetDialog: public Ui_AddWidgetDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDWIDGETDIALOG_H
