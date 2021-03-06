#ifndef CHARTWIDGET_H
#define CHARTWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QtCharts>
#include <mqttwidget.h>

using namespace QtCharts;

namespace Ui {
class ChartWidget;
}

class ChartWidget : public QChartView, public MqttWidget
{
    Q_OBJECT

public:
    explicit ChartWidget(QString name, QString topic, QWidget *parent = nullptr);
    ~ChartWidget();
    void addValue(double value);
    void setValue(QString value);
    void virtual setName(const QString &newName);

protected:
    /* Define method of base class
     * */
    //    void paintEvent(QPaintEvent *event);
    void showEvent(QShowEvent *event);
//    void show();

private:
    Ui::ChartWidget *ui;
    QVector<double> points;
    int maxValuesCount = 30;
    double maxValue = 0;
    double minValue = 0;
    QString title = "Simple areachart example";
    QString nameIS = "Value";
    QLinearGradient *gradient;
    QPen *pen;
    QLineSeries *series = new QLineSeries();
    QChart *chart = new QChart();
};

#endif // CHARTWIDGET_H
