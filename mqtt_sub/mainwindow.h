#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtMqtt/QMqttClient>
#include <QVector>
//#include <indicator.h>
#include "indicatorwidget.h"
#include "chartwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_sub_clicked();

private:
    Ui::MainWindow *ui;
    QMqttClient *cli;
    QVector<QString> subs;
//    Indicator   *indicator;
//        MyGraphicView   *myPicture;     // Наш кастомный виджет
    IndicatorWidget *widget;
    ChartWidget *chart;
    void sliderSubscription();
};
#endif // MAINWINDOW_H