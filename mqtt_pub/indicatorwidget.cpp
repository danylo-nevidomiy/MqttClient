#include "indicatorwidget.h"
#include "ui_mainwindow.h"

#include <QtMqtt/QMqttClient>
#include <QtWidgets/QMessageBox>
#include <QString>

Widget::Widget(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    cli = new QMqttClient();
    cli->setHostname("185.217.198.251");
    cli->setPort(1883);
    cli->connectToHost();
//    cli->connectToHost();
    qDebug() << cli->state();
//    QString topic = "test";
//    auto subscription = cli->subscribe(topic);
//    cli->publish(topic, "Hello");
//    qDebug() << "subscription = " << subscription;
//    connect(cli, &QMqttClient::messageReceived, this, [this](const QByteArray &message, const QMqttTopicName &topic) {
//        const QString content = QDateTime::currentDateTime().toString()
//                    + QLatin1String(" Received Topic: ")
//                    + topic.name()
//                    + QLatin1String(" Message: ")
//                    + message
//                    + QLatin1Char('\n');
//        qDebug() << content;
//    });
    ui->horizontalSlider->setRange(0, 180);
    ui->topicLine->setText("test");
    ui->messageLine->setText("Hello");
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{

    QString topic = ui->topicLine->text();
    QString message = ui->messageLine->text();
//    auto subscription = cli->subscribe(topic);
    cli->publish(topic, message.toUtf8());
    qDebug() << "clicked";
//    if (cli->publish(topic, "Hello") == -1)
//        QMessageBox::critical(this, QLatin1String("Error"), QLatin1String("Could not publish message"));
}


void Widget::on_horizontalSlider_valueChanged(int value)
{
    QString topic = "slider";
    cli->publish(topic, QString::number(value).toUtf8());

}

