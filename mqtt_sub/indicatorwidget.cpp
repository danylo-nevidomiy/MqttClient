#include "indicatorwidget.h"
#include "ui_indicatorwidget.h"
#include <iostream>

IndicatorWidget::IndicatorWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::IndicatorWidget)
{
    //    ui = new Ui::Widget();
    ui->setupUi(this);
    this->resize(400, 300);
//    this->setParent(parent);
    this->show();
    this->move(0, 200);

    ui->slider->setRange(0, 180);
    ui->slider->setVisible(false);
    arrow.load("/home/daniil/Repositories/qtmqtt/examples/mqtt/mqtt_sub/arrow-upper-right.png");
    Q_ASSERT(!arrow.isNull());
    clock.load("/home/daniil/Repositories/qtmqtt/examples/mqtt/mqtt_sub/pngegg.png");
    Q_ASSERT(!clock.isNull());

}

IndicatorWidget::~IndicatorWidget()
{
    delete ui;
}

void IndicatorWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this); // Create object of QPainter
    QRect target(50,0,clock.height(), clock.width());
    painter.drawImage(target, clock);
    painter.rotate(60);
    QTransform trans;
    trans.translate(this->width()/2, this->height()/2);
    trans.rotate(angle);
    trans.translate(0,0);
    painter.setTransform(trans);
    painter.drawImage(QPoint(0,0), arrow.scaledToHeight(100));
    painter.end();
}

void IndicatorWidget::setAngle(int angle)
{
    this->angle = angle+135;
    repaint();
}
/* If same radio button will be pressed,
 * then we execute the drawing new view of circle
 * */
void IndicatorWidget::on_radioButton_red_clicked()
{
    repaint();
}

void IndicatorWidget::on_radioButton_green_clicked()
{
    repaint();
}

void IndicatorWidget::on_radioButton_blue_clicked()
{
    repaint();
}

void IndicatorWidget::on_slider_valueChanged(int value)
{
    angle = value+135;
    //    std::cout << "angle = " << angle;
    repaint();
}

