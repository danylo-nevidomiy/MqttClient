#ifndef INPUTWIDGET_H
#define INPUTWIDGET_H

#include <QWidget>
#include "mqttwidget.h"

namespace Ui {
class InputWidget;
}

class InputWidget : public QWidget, public MqttWidget
{
    Q_OBJECT

public:
    explicit InputWidget(QString name, QString topic, QWidget *parent = nullptr);
    ~InputWidget();

private:
    Ui::InputWidget *ui;

    // MqttWidget interface
public:
    virtual void setValue(QString value);
    virtual void setName(const QString &newName);
private slots:
    void on_pushButton_clicked();
    void on_valueLineEdit_returnPressed();

signals:
    void inputValueChanged(QString topic, QString value);

    // MqttWidget interface
signals:
    void valueChanged(QString topic, QString value);
};

#endif // INPUTWIDGET_H
