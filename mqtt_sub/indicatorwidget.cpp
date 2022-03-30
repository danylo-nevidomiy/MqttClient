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
    this->setParent(parent);
    this->show();
    this->move(0, 200);

    ui->slider->setRange(0, 180);
    //    ui->label->setPixmap(QPixmap("/home/daniil/Repositories/qtmqtt/examples/mqtt/mqtt_sub/711dSgHSD9L.png"));
}

IndicatorWidget::~IndicatorWidget()
{
    delete ui;
}

void IndicatorWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this); // Create object of QPainter
//    painter.begin(this);
    // Set Brush
    painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));

    /* Check radio buttins
     * */

    painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));
    painter.drawEllipse(originX, originY, radius, radius);
    painter.setBrush(QBrush(Qt::white, Qt::SolidPattern));
    double newRadius = radius*0.5;
    painter.drawEllipse(originX+newRadius/2, originY+newRadius/2, newRadius, newRadius);
    int x = 175;
    int y = 125;
    QLineF line(x, y, 175.0, 50.0);
    line.setAngle(angle);
    painter.drawLine(line);
    int imageWidth = radius/2;
    int imageHeight = radius/2;

    QImage img("/home/daniil/Repositories/qtmqtt/examples/mqtt/mqtt_sub/arrow-upper-right.png");
//    QImage rotatedImg = img.transformed(QMatrix().rotate(angle));
//    rotatedImg.save("/home/daniil/Repositories/qtmqtt/examples/mqtt/mqtt_sub/rt1.png");
    Q_ASSERT(!img.isNull());
    QRect target(150,75,50,50);
    //      target.moveTo(0, 0);
    //      painter.rotate(60);
    QTransform trans;
    // Move to the center of the widget


trans.translate(this->width()/2-25, this->height()/2-25);
//     Do the rotation
    trans.rotate(angle);

trans.translate(0,0);
    // Move to the center of the image
//    trans.translate(-this->width()/2, -this->height()/2);


    painter.setTransform(trans);
    // Draw the image at (0,0), because everything is already handled by the transformation
    painter.drawImage(QPoint(0,0), img.scaledToHeight(50));
    //      painter.resetTransform();
    //      target.moveTo(150, 75);
//    painter.drawImage(target, img);
    //    QRect rect = QRect(originX, originY+radius/2, radius, radius/2);
    //    painter.fillRect(rect, Qt::white);
    //    if(ui->radioButton_red->isChecked()){
    //        // Draw red circle
    //        painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));
    //        painter.drawEllipse(originX, originY, radius, radius);
    //    } else if(ui->radioButton_green->isChecked()){
    //        // Draw green circle
    //        painter.setBrush(QBrush(Qt::green, Qt::SolidPattern));
    //        painter.drawEllipse(originX, originY, radius, radius);
    //    } else if(ui->radioButton_blue->isChecked()){
    //        // Draw blue circle
    //        painter.setBrush(QBrush(Qt::blue, Qt::SolidPattern));
    //        painter.drawEllipse(originX, originY, radius, radius);
    //    } else {
    //        // Draw white circle
    //        painter.setBrush(QBrush(Qt::white, Qt::SolidPattern));
    //        painter.drawEllipse(originX, originY, radius, radius);
    //    }
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

