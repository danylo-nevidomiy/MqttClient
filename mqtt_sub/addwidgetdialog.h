#ifndef ADDWIDGETDIALOG_H
#define ADDWIDGETDIALOG_H

#include <QDialog>

namespace Ui {
class AddWidgetDialog;
}

class AddWidgetDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddWidgetDialog(QWidget *parent = nullptr);
    ~AddWidgetDialog();

private slots:
    void on_AddWidgetDialog_accepted();

    void on_AddWidgetDialog_rejected();

signals:
    void AddWidget(QString type, QString name, QString topic);
private:
    Ui::AddWidgetDialog *ui;
};

#endif // ADDWIDGETDIALOG_H
