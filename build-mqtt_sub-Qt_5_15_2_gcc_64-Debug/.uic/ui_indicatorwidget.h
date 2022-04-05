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
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IndicatorWidget
{
public:
    QSlider *slider;

    void setupUi(QWidget *IndicatorWidget)
    {
        if (IndicatorWidget->objectName().isEmpty())
            IndicatorWidget->setObjectName(QString::fromUtf8("IndicatorWidget"));
        IndicatorWidget->resize(400, 300);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(IndicatorWidget->sizePolicy().hasHeightForWidth());
        IndicatorWidget->setSizePolicy(sizePolicy);
        IndicatorWidget->setMinimumSize(QSize(400, 300));
        slider = new QSlider(IndicatorWidget);
        slider->setObjectName(QString::fromUtf8("slider"));
        slider->setGeometry(QRect(10, 271, 381, 20));
        sizePolicy.setHeightForWidth(slider->sizePolicy().hasHeightForWidth());
        slider->setSizePolicy(sizePolicy);
        slider->setOrientation(Qt::Horizontal);

        retranslateUi(IndicatorWidget);

        QMetaObject::connectSlotsByName(IndicatorWidget);
    } // setupUi

    void retranslateUi(QWidget *IndicatorWidget)
    {
        IndicatorWidget->setWindowTitle(QCoreApplication::translate("IndicatorWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IndicatorWidget: public Ui_IndicatorWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INDICATORWIDGET_H
