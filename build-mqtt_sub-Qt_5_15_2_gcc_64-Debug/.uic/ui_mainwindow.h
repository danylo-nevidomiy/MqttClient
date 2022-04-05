/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QWidget *toolsWidget;
    QFormLayout *formLayout;
    QPushButton *pushButton_sub;
    QLineEdit *topicLine;
    QLabel *messageLabel;
    QLabel *messageText;
    QLabel *sliderText;
    QLabel *sliderValue;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(808, 599);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, -1);
        toolsWidget = new QWidget(centralwidget);
        toolsWidget->setObjectName(QString::fromUtf8("toolsWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(toolsWidget->sizePolicy().hasHeightForWidth());
        toolsWidget->setSizePolicy(sizePolicy1);
        formLayout = new QFormLayout(toolsWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        pushButton_sub = new QPushButton(toolsWidget);
        pushButton_sub->setObjectName(QString::fromUtf8("pushButton_sub"));

        formLayout->setWidget(0, QFormLayout::LabelRole, pushButton_sub);

        topicLine = new QLineEdit(toolsWidget);
        topicLine->setObjectName(QString::fromUtf8("topicLine"));

        formLayout->setWidget(0, QFormLayout::FieldRole, topicLine);

        messageLabel = new QLabel(toolsWidget);
        messageLabel->setObjectName(QString::fromUtf8("messageLabel"));
        messageLabel->setLayoutDirection(Qt::LeftToRight);

        formLayout->setWidget(1, QFormLayout::LabelRole, messageLabel);

        messageText = new QLabel(toolsWidget);
        messageText->setObjectName(QString::fromUtf8("messageText"));

        formLayout->setWidget(1, QFormLayout::FieldRole, messageText);

        sliderText = new QLabel(toolsWidget);
        sliderText->setObjectName(QString::fromUtf8("sliderText"));
        sliderText->setLayoutDirection(Qt::LeftToRight);

        formLayout->setWidget(2, QFormLayout::LabelRole, sliderText);

        sliderValue = new QLabel(toolsWidget);
        sliderValue->setObjectName(QString::fromUtf8("sliderValue"));

        formLayout->setWidget(2, QFormLayout::FieldRole, sliderValue);


        verticalLayout->addWidget(toolsWidget);

        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        sizePolicy.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 806, 444));
        sizePolicy.setHeightForWidth(scrollAreaWidgetContents_2->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents_2->setSizePolicy(sizePolicy);
        gridLayoutWidget = new QWidget(scrollAreaWidgetContents_2);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(219, 139, 161, 81));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetMaximumSize);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea->setWidget(scrollAreaWidgetContents_2);

        verticalLayout->addWidget(scrollArea);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 808, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_sub->setText(QCoreApplication::translate("MainWindow", "sub", nullptr));
        messageLabel->setText(QCoreApplication::translate("MainWindow", "Message:", nullptr));
        messageText->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        sliderText->setText(QCoreApplication::translate("MainWindow", "Slider:", nullptr));
        sliderValue->setText(QCoreApplication::translate("MainWindow", "Value", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
