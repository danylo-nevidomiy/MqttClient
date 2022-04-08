#include "addwidgetdialog.h"
#include "ui_addwidgetdialog.h"

AddWidgetDialog::AddWidgetDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddWidgetDialog)
{
    ui->setupUi(this);
    QStringList list;
    list.append("Indicator");
    list.append("Chart");
    ui->comboBox->addItems(list);
}

AddWidgetDialog::~AddWidgetDialog()
{
    delete ui;
}

void AddWidgetDialog::on_AddWidgetDialog_accepted()
{
    emit AddWidget(ui->comboBox->currentText());
}


void AddWidgetDialog::on_AddWidgetDialog_rejected()
{
    close();
}

