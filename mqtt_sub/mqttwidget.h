#ifndef MQTTWIDGET_H
#define MQTTWIDGET_H

#include <QChartView>

using namespace QtCharts;

class MqttWidget : public QChartView
{
    Q_OBJECT
public:
    MqttWidget(QWidget *parent = nullptr);
    QString name;
};

#endif // MQTTWIDGET_H
