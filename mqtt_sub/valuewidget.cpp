#include "valuewidget.h"
#include "ui_valuewidget.h"

ValueWidget::ValueWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ValueWidget)
{
    ui->setupUi(this);
}

ValueWidget::~ValueWidget()
{
    delete ui;
}
