#include "chartwidget.h"
#include "ui_chartwidget.h"

ChartWidget::ChartWidget(QString name, QString topic, QWidget *parent) :
    QChartView(parent), MqttWidget(name, topic),
    ui(new Ui::ChartWidget)
{
    ui->setupUi(this);
    this->setParent(parent);
    this->show();
//        this->setFixedWidth(200);
//        this->setFixedHeight(200);
    this->move(400, 200);
    gradient = new QLinearGradient(QPointF(0, 0), QPointF(0, 1));
    gradient->setColorAt(0.0, 0x3cc63c);
    gradient->setColorAt(1.0, 0x26f626);
    gradient->setCoordinateMode(QGradient::ObjectBoundingMode);
    pen = new QPen(0x059605);
    pen->setWidth(3);
    chart->setTitle(name);

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
    qDebug() << "size = " << points.size();
    for(int i=0;i<points.size();i++)
    {
        qDebug() << "points.at(i) = " << points.at(i);
        *series << QPointF(i, points.at(i));
    }
    series->setName(nameIS);
    series->setPen(*pen);
    series->setBrush(*gradient);
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->axes(Qt::Horizontal).first()->setRange(0, 30);
    chart->axes(Qt::Vertical).first()->setRange(0, 30);
//    chart->axes(Qt::Horizontal).first()->setRange(0, maxValuesCount);
//    chart->axes(Qt::Vertical).first()->setRange(qRound(minValue), qRound(maxValue));
}
//void ChartWidget::show()
//{
//    series->clear();
//    qDebug() << "size = " << points.size();
//    for(int i=0;i<points.size();i++)
//    {
//        qDebug() << "points.at(i) = " << points.at(i);
//        *series << QPointF(i, points.at(i));
//    }

//    series->setName(name);
//    series->setPen(*pen);
//    series->setBrush(*gradient);
//    chart->addSeries(series);
//    chart->createDefaultAxes();
////    chart->axes(Qt::Horizontal).first()->setRange(0, 30);
////    chart->axes(Qt::Vertical).first()->setRange(0, 30);
//    chart->axes(Qt::Horizontal).first()->setRange(0, maxValuesCount);
//    chart->axes(Qt::Vertical).first()->setRange(minValue, maxValue);
//    QChartView::show();
//}
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
    qDebug() << "value = " << value;
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
//    update();
//    hide();
    show();
}

void ChartWidget::setValue(QString value)
{
    addValue(value.toDouble());
}

void ChartWidget::setName(const QString &newName)
{
    MqttWidget::setName(newName);
    chart->setTitle(newName);
}
