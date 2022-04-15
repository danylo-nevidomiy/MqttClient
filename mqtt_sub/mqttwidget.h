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
    void virtual setName(const QString &newName);
    const QString &getTopic() const;
    void virtual setTopic(const QString &newTopic);
protected:
    QString name;
    QString topic;
    unsigned int row;
    unsigned int column;
signals:
//    virtual void valueChanged(QString topic, QString value) = 0;
};

#endif // MQTTWIDGET_H
