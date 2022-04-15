#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtMqtt/QMqttClient>
#include <QVector>
#include <QMap>
//#include <indicator.h>
#include "indicatorwidget.h"
#include "chartwidget.h"
#include "addwidgetdialog.h"
#include "switcherwidget.h"
#include "inputwidget.h"
#include "valuewidget.h"
#include "tabcustomwidget.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    enum WGS{Indicator, Chart, Switcher, Input};
    Q_ENUMS(WGS)


private slots:

    void on_pushButton_sub_clicked();
    void on_actionAdd_triggered();
    void AddWidget(QString type, QString name, QString topic);
    void sendValue(QString topic, QString value);

    void on_tabWidget_currentChanged(int index);

//    void on_tabWidget_customContextMenuRequested(const QPoint &pos);

    void on_tabWidget_tabCloseRequested(int index);

private:
    Ui::MainWindow *ui;
    QMqttClient *cli;
    QVector<QString> subs;
//    Indicator   *indicator;
//        MyGraphicView   *myPicture;     // Наш кастомный виджет
    IndicatorWidget *widget;
    ChartWidget *chart;
    ChartWidget *chart1;
    IndicatorWidget *indicator;
    AddWidgetDialog *awd;
    QVector<MqttWidget*> widgets;
    void sliderSubscription();
    QStringList list = {"Indicator", "Chart", "Switcher", "Input", "Value"};
    QMenu *TabMenu;
    QMap<int, QUuid> TabsIdentifiers;
    QMap<QUuid, TabCustomWidget*> Tabs;
    unsigned int currentTab;
};
#endif // MAINWINDOW_H
