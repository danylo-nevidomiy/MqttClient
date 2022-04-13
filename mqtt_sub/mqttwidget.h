#ifndef MQTTWIDGET_H
#define MQTTWIDGET_H

#include <QChartView>

using namespace QtCharts;

class MqttWidget
{
public:
    MqttWidget(QWidget *parent = nullptr);
    MqttWidget(QString name, QString topic, QWidget *parent = nullptr);
    void virtual setValue(QString value) = 0;
    const QString &getName() const;
    void setName(const QString &newName);
    const QString &getTopic() const;
    void setTopic(const QString &newTopic);
private:
    QString name;
    QString topic;
};

#endif // MQTTWIDGET_H
