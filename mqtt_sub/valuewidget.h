#ifndef VALUEWIDGET_H
#define VALUEWIDGET_H

#include <QWidget>
#include "mqttwidget.h"

namespace Ui {
class ValueWidget;
}

class ValueWidget : public QWidget, public MqttWidget
{
    Q_OBJECT

public:
    explicit ValueWidget(QString name, QString topic, QWidget *parent = nullptr);
    ~ValueWidget();

private:
    Ui::ValueWidget *ui;


    // MqttWidget interface
public:
    virtual void setValue(QString value);
    virtual void setName(const QString &newName);
};

#endif // VALUEWIDGET_H
