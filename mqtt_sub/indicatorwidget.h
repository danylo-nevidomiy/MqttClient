#ifndef INDICATORWIDGET_H
#define INDICATORWIDGET_H

#include <QWidget>
#include <QPainter>
#include "mqttwidget.h"

namespace Ui {
class IndicatorWidget;
}

class IndicatorWidget : public QWidget, public MqttWidget
{
    Q_OBJECT

public:
    explicit IndicatorWidget(QString name, QString topic, QWidget *parent = 0);
    ~IndicatorWidget();
    void setAngle(int angle);
    void setValue(QString value);

protected:
    /* Define method of base class
     * */
    void paintEvent(QPaintEvent *event);

private slots:

    void on_slider_valueChanged(int value);

private:
    Ui::IndicatorWidget *ui;
    QImage arrow;
    QImage clock;
    const int radius = 150;
    const int originX = 100;
    const int originY = 50;
    double angle = 180;

};

#endif // INDICATORWIDGET_H
