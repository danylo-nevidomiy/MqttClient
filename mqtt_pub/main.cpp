#include "indicatorwidget.h"

#include <QApplication>
#include <QtMqtt/QMqttClient>
#include <QString>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Widget w;
    w.show();
    return a.exec();
}
