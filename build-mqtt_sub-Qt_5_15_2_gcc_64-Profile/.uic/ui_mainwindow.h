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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_sub;
    QLineEdit *topicLine;
    QLabel *messageLabel;
    QLabel *messageText;
    QLabel *sliderText;
    QLabel *sliderValue;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton_sub = new QPushButton(centralwidget);
        pushButton_sub->setObjectName(QString::fromUtf8("pushButton_sub"));
        pushButton_sub->setGeometry(QRect(10, 10, 80, 26));
        topicLine = new QLineEdit(centralwidget);
        topicLine->setObjectName(QString::fromUtf8("topicLine"));
        topicLine->setGeometry(QRect(110, 10, 113, 26));
        messageLabel = new QLabel(centralwidget);
        messageLabel->setObjectName(QString::fromUtf8("messageLabel"));
        messageLabel->setGeometry(QRect(20, 50, 70, 20));
        messageText = new QLabel(centralwidget);
        messageText->setObjectName(QString::fromUtf8("messageText"));
        messageText->setGeometry(QRect(120, 50, 81, 20));
        sliderText = new QLabel(centralwidget);
        sliderText->setObjectName(QString::fromUtf8("sliderText"));
        sliderText->setGeometry(QRect(20, 80, 70, 20));
        sliderValue = new QLabel(centralwidget);
        sliderValue->setObjectName(QString::fromUtf8("sliderValue"));
        sliderValue->setGeometry(QRect(120, 80, 81, 20));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
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
