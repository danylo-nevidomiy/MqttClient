/********************************************************************************
** Form generated from reading UI file 'indicatorwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INDICATORWIDGET_H
#define UI_INDICATORWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IndicatorWidget
{
public:
    QSlider *slider;
    QLabel *label;

    void setupUi(QWidget *IndicatorWidget)
    {
        if (IndicatorWidget->objectName().isEmpty())
            IndicatorWidget->setObjectName(QString::fromUtf8("IndicatorWidget"));
        IndicatorWidget->resize(400, 300);
        slider = new QSlider(IndicatorWidget);
        slider->setObjectName(QString::fromUtf8("slider"));
        slider->setGeometry(QRect(10, 271, 381, 20));
        slider->setOrientation(Qt::Horizontal);
        label = new QLabel(IndicatorWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 58, 18));

        retranslateUi(IndicatorWidget);

        QMetaObject::connectSlotsByName(IndicatorWidget);
    } // setupUi

    void retranslateUi(QWidget *IndicatorWidget)
    {
        IndicatorWidget->setWindowTitle(QCoreApplication::translate("IndicatorWidget", "Form", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class IndicatorWidget: public Ui_IndicatorWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INDICATORWIDGET_H
