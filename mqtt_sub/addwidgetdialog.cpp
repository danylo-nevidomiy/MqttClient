#include "addwidgetdialog.h"
#include "ui_addwidgetdialog.h"
#include "mainwindow.h"

AddWidgetDialog::AddWidgetDialog(QStringList list, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddWidgetDialog)
{
    ui->setupUi(this);

//    QMetaEnum MetaEnum = QMetaEnum::fromType<MainWindow::WGS>();
//    for(int i=0;i<MetaEnum.keyCount();i++)
//    {
//        list.append(MetaEnum.valueToKey(i));
//    }
//    list.append("Indicator");
//    list.append("Chart");
//    list.append("Switcher");
    ui->comboBox->addItems(list);
}

AddWidgetDialog::~AddWidgetDialog()
{
    delete ui;
}

void AddWidgetDialog::on_AddWidgetDialog_accepted()
{
    emit AddWidget(ui->comboBox->currentText(), ui->lineEditName->text(), ui->lineEditTopic->text());
}


void AddWidgetDialog::on_AddWidgetDialog_rejected()
{
    close();
}

