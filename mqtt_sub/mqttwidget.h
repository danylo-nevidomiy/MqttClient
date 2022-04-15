#ifndef MQTTWIDGET_H
#define MQTTWIDGET_H

#include <QChartView>
#include <QUuid>

using namespace QtCharts;

class MqttWidget
{
public:
    MqttWidget(QWidget *parent = nullptr);
    virtual ~MqttWidget();
    MqttWidget(QString name, QString topic, QWidget *parent = nullptr);
    void virtual setValue(QString value) = 0;
    const QString &getName() const;
    void virtual setName(const QString &newName);
    const QString &getTopic() const;
    void virtual setTopic(const QString &newTopic);

    const QUuid &getTabIndex() const;
    void setTabIndex(const QUuid &newTabIndex);

protected:
    QString name;
    QString topic;
    QUuid tabIndex;
signals:
//    virtual void valueChanged(QString topic, QString value) = 0;
};

#endif // MQTTWIDGET_H
