#include "mqttwidget.h"

MqttWidget::MqttWidget(QWidget *parent)
{

}

MqttWidget::MqttWidget(QString name, QString topic, QWidget *parent)
{
    setName(name);
    setTopic(topic);
}

const QString &MqttWidget::getTopic() const
{
    return topic;
}

void MqttWidget::setTopic(const QString &newTopic)
{
    topic = newTopic;
}

const QString &MqttWidget::getName() const
{
    return name;
}

void MqttWidget::setName(const QString &newName)
{
    name = newName;
}
