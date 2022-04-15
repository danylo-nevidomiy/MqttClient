#include "switcherwidget.h"
#include "ui_switcherwidget.h"

SwitcherWidget::SwitcherWidget(QString name, QString topic, QWidget *parent) :
    QWidget(parent), MqttWidget(name, topic),
    ui(new Ui::Switcher)
{
    ui->setupUi(this);
    ui->label_name->setText(name);
    QPalette p(palette());
    p.setColor(QPalette::Background, Qt::black);
    setPalette(p);
}

SwitcherWidget::~SwitcherWidget()
{
    delete ui;
}

void SwitcherWidget::setValue(QString value)
{
    unsigned int s = value.toUInt();
    if(s == 0)
    {

    }
}

void SwitcherWidget::on_button_switch_clicked()
{
    if(state){
        emit valueChanged(topic, QString::number(0));
        ui->button_switch->setText("ON");
    }else{
        emit valueChanged(topic, QString::number(1));
        ui->button_switch->setText("OFF");
    }
    state = !state;

}

