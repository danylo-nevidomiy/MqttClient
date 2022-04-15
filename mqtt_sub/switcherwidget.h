#ifndef SWITCHERWIDGET_H
#define SWITCHERWIDGET_H

#include <QWidget>
#include "mqttwidget.h"

namespace Ui {
class Switcher;
}

class SwitcherWidget : public QWidget, public MqttWidget
{
    Q_OBJECT

public:
    explicit SwitcherWidget(QString name, QString topic, QWidget *parent = nullptr);
    ~SwitcherWidget();
    void virtual setValue(QString value);


private slots:
    void on_button_switch_clicked();
signals:
    void switchState(bool state);

private:
    Ui::Switcher *ui;
    bool state = false;

    // MqttWidget interface
signals:
    void valueChanged(QString topic, QString value);
};

#endif // SWITCHERWIDGET_H
