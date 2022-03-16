/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IndicatorWidget
{
public:
    QRadioButton *radioButton_red;
    QRadioButton *radioButton_green;
    QRadioButton *radioButton_blue;

    void setupUi(QWidget *IndicatorWidget)
    {
        if (IndicatorWidget->objectName().isEmpty())
            IndicatorWidget->setObjectName(QString::fromUtf8("IndicatorWidget"));
        IndicatorWidget->resize(400, 300);
        radioButton_red = new QRadioButton(IndicatorWidget);
        radioButton_red->setObjectName(QString::fromUtf8("radioButton_red"));
        radioButton_red->setGeometry(QRect(0, 270, 102, 24));
        radioButton_green = new QRadioButton(IndicatorWidget);
        radioButton_green->setObjectName(QString::fromUtf8("radioButton_green"));
        radioButton_green->setGeometry(QRect(110, 270, 102, 24));
        radioButton_blue = new QRadioButton(IndicatorWidget);
        radioButton_blue->setObjectName(QString::fromUtf8("radioButton_blue"));
        radioButton_blue->setGeometry(QRect(240, 270, 102, 24));

        retranslateUi(IndicatorWidget);

        QMetaObject::connectSlotsByName(IndicatorWidget);
    } // setupUi

    void retranslateUi(QWidget *IndicatorWidget)
    {
        IndicatorWidget->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        radioButton_red->setText(QCoreApplication::translate("Form", "RadioButton", nullptr));
        radioButton_green->setText(QCoreApplication::translate("Form", "RadioButton", nullptr));
        radioButton_blue->setText(QCoreApplication::translate("Form", "RadioButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IndicatorWidget: public Ui_IndicatorWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
