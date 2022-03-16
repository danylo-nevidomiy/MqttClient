#include "indicatorwidget.h"
#include "ui_indicatorwidget.h"

IndicatorWidget::IndicatorWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::IndicatorWidget)
{
//    ui = new Ui::Widget();
    ui->setupUi(this);
//    this->resize(500, 500);
//    this->setParent(parent);
//    this->show();
//    this->move(0, 200);
}

IndicatorWidget::~IndicatorWidget()
{
    delete ui;
}

void IndicatorWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this); // Create object of QPainter
    // Set Brush
    painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));

    /* Check radio buttins
     * */

    painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));
    painter.drawEllipse(originX, originY, radius, radius);
    painter.setBrush(QBrush(Qt::white, Qt::SolidPattern));
    double newRadius = radius*0.5;
    painter.drawEllipse(originX+newRadius/2, originY+newRadius/2, newRadius, newRadius);
    QLineF line(175.0, 125.0, 175.0, 50.0);
    line.setAngle(angle);
    painter.drawLine(line);
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
}

void IndicatorWidget::setAngle(int angle)
{
    this->angle = 180-angle;
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
