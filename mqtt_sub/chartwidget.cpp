#include "chartwidget.h"
#include "ui_chartwidget.h"

ChartWidget::ChartWidget(QWidget *parent) :
    QChartView(parent),
    ui(new Ui::ChartWidget)
{
    ui->setupUi(this);
    this->setParent(parent);
    this->show();
    this->move(0, 200);
    gradient = new QLinearGradient(QPointF(0, 0), QPointF(0, 1));
    gradient->setColorAt(0.0, 0x3cc63c);
    gradient->setColorAt(1.0, 0x26f626);
    gradient->setCoordinateMode(QGradient::ObjectBoundingMode);
    pen = new QPen(0x059605);
    pen->setWidth(3);
    chart->setTitle(title);
    series->setName(name);
    series->setPen(*pen);
    series->setBrush(*gradient);
    chart->axes(Qt::Horizontal).first()->setRange(0, 30);
    chart->axes(Qt::Vertical).first()->setRange(0, 10);
    chart->createDefaultAxes();
    chart->addSeries(series);
    this->setRenderHint(QPainter::Antialiasing);
    this->setChart(chart);

}

ChartWidget::~ChartWidget()
{
    delete ui;
}

//void ChartWidget::paintEvent(QPaintEvent *event)
//{
//    Q_UNUSED(event);
//    QPainter painter(this); // Create object of QPainter
//    // Set Brush
//    painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));
//    painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));
//    //    painter.drawEllipse(originX, originY, radius, radius);

//}
void ChartWidget::showEvent(QShowEvent *event)
{
    Q_UNUSED(event);
    series->clear();
    for(int i=0;i<points.size();i++)
    {
        *series << QPointF(i, points.at(i));
    }
//    *series << QPointF(1, 5) << QPointF(3, 7) << QPointF(7, 6) << QPointF(9, 7) << QPointF(12, 6)
//            << QPointF(16, 7) << QPointF(18, 5);

}
void ChartWidget::addValue(double value)
{
       if(value > maxValue)
       {
           maxValue = value;
       }else if(value < minValue)
       {
           minValue = value;
       }
    points.append(value);
    if(points.size() > maxValuesCount)
    {
        points.erase(points.begin());
        double min = points.at(0), max = points.at(0);
        for(auto i : points)
        {
           if(i > max)
           {
               max = i;
           }else if(i < min)
           {
               min = i;
           }
        }
        maxValue = max;
        minValue = min;
    }

    show();
}
