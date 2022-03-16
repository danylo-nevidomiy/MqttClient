#ifndef INDICATORWIDGET_H
#define INDICATORWIDGET_H

#include <QMainWindow>
#include <QtMqtt/QMqttClient>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Widget : public QMainWindow
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_clicked();

    void on_horizontalSlider_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    QMqttClient *cli;
};
#endif // INDICATORWIDGET_H
