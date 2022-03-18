#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtMqtt/QMqttClient>
#include <QtWidgets/QMessageBox>
#include <QString>
#include <QLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    widget = new IndicatorWidget(this);

    chart = new ChartWidget(this);
    cli = new QMqttClient();
    cli->setHostname("185.217.198.251");
    cli->setPort(1883);
    cli->connectToHost();
    ui->topicLine->setText("test");
    connect(cli, &QMqttClient::messageReceived, this, [this](const QByteArray &message, const QMqttTopicName &topic) {
        const QString content = QDateTime::currentDateTime().toString()
                + QLatin1String(" Received Topic: ")
                + topic.name()
                + QLatin1String(" Message: ")
                + message
                + QLatin1Char('\n');
        qDebug() << content;
        //         ui->messageText->setText(message);
        if(QString::compare(topic.name(), QString::fromStdString("slider")) == 0)
        {
            ui->sliderValue->setText(message);
        }else if(QString::compare(topic.name(), QString::fromStdString("indicator")) == 0)
        {
            widget->setAngle(message.toInt());
        }else if(QString::compare(topic.name(), QString::fromStdString("chart")) == 0)
        {
            chart->addValue(message.toDouble());
        }
        else
        {
            for(auto i : subs)
            {
                if(QString::compare(topic.name(), i) == 0)
                {
                    ui->messageText->setText(message);
                }
            }

        }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_sub_clicked()
{
    sliderSubscription();
    QString topic = ui->topicLine->text();
    auto subscription = cli->subscribe(topic);
    subs.append(topic);
    //    if (!subscription) {
    //        QMessageBox::critical(this, QLatin1String("Error"), QLatin1String("Could not subscribe. Is there a valid connection?"));
    //        return;
    //    }
    qDebug() << "subscription = " << subscription;
}
void MainWindow::sliderSubscription()
{
    QString slider = QString::fromStdString("slider");
    auto subscription = cli->subscribe(slider);
}
