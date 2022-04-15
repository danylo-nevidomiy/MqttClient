#include "inputwidget.h"
#include "ui_inputwidget.h"

InputWidget::InputWidget(QString name, QString topic, QWidget *parent) :
    QWidget(parent), MqttWidget(name, topic),
    ui(new Ui::InputWidget)
{
    ui->setupUi(this);
    ui->label_name->setText(name);
}

InputWidget::~InputWidget()
{
    delete ui;
}

void InputWidget::setValue(QString value)
{
    ui->valueLineEdit->setText(value);
}

void InputWidget::setName(const QString &newName)
{
    MqttWidget::setName(newName);
    ui->label_name->setText(newName);
}

void InputWidget::on_pushButton_clicked()
{
    emit valueChanged(topic, ui->valueLineEdit->text());
}


void InputWidget::on_valueLineEdit_returnPressed()
{
    emit valueChanged(topic, ui->valueLineEdit->text());
}

