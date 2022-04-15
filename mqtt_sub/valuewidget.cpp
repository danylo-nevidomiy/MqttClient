#include "valuewidget.h"
#include "ui_valuewidget.h"

ValueWidget::ValueWidget(QString name, QString topic, QWidget *parent) :
    QWidget(parent), MqttWidget(name, topic),
    ui(new Ui::ValueWidget)
{
    ui->setupUi(this);
    ui->label_name->setText(name);
}

ValueWidget::~ValueWidget()
{
    delete ui;
}

void ValueWidget::setValue(QString value)
{
    ui->label_value->setText(value);
}

void ValueWidget::setName(const QString &newName)
{
    ui->label_name->setText(newName);
}
