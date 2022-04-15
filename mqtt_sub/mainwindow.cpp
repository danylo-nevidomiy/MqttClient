#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtMqtt/QMqttClient>
#include <QtWidgets/QMessageBox>
#include <QString>
#include <QLayout>
#include <QColor>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    QString newTab = "default";
    int index = 0;
    TabCustomWidget *defaultTab = new TabCustomWidget(newTab);
    Tabs.insert(defaultTab->getIndex(), defaultTab);
    TabsIdentifiers.insert(index, defaultTab->getIndex());
    currentTab = index;
    indicator = new IndicatorWidget("i", "indicator", ui->scrollAreaWidgetContents_2);
    widget = new IndicatorWidget("2", "indicator", ui->scrollAreaWidgetContents_2);
    chart = new ChartWidget("c", "chart", ui->scrollAreaWidgetContents_2);
    chart1 = new ChartWidget("zzz", "zzz", ui->scrollAreaWidgetContents_2);
    widgets.append(indicator);
    widgets.append(chart);
    widgets.append(widget);
    widgets.append(chart1);
    //    ui->scrollArea->setParent(this);
    //    ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    //    ui->scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    //    ui->scrollArea->setWidgetResizable( true );
    //    ui->scrollArea->setGeometry( 0, 0, 1000, 1000 );
    //    ui->scrollArea->setWidget(ui->scrollAreaWidgetContents);

    //    auto p = ui->scrollAreaWidgetContents_2->palette();
    //    p.setColor(ui->scrollAreaWidgetContents_2->backgroundRole(), Qt::red);
    //    ui->scrollAreaWidgetContents_2->setPalette(p);

    ui->gridLayout = new QGridLayout(ui->scrollAreaWidgetContents_2);
    ui->gridLayout->addWidget(widget);
    ui->gridLayout->addWidget(chart);
    ui->gridLayout->addWidget(indicator, 0,1);
    ui->gridLayout->addWidget(chart1);
    ui->tabWidget->setTabText(ui->tabWidget->count()-1, "+");
    ui->tabWidget->tabBar()->tabButton(ui->tabWidget->count()-1, QTabBar::RightSide)->resize(0, 0);
//    currentTab = ui->tabWidget->findChild<QTabBar *>;
    //    ui->scrollAreaWidgetContents->setWidgetResizable(true);
    cli = new QMqttClient();
    //    chart->move(400, 200);
    //    ui->gridLayout->addWidget(chart);
    //    ui->gridLayout->addWidget(widget);
    //    ui->widget_2->setBackgroundRole(QPalette::Dark);
    cli->setHostname("localhost");
    cli->setPort(1883);
    cli->connectToHost();
    ui->topicLine->setText("test");
    connect(cli, &QMqttClient::messageReceived, this, [this](const QByteArray &message, const QMqttTopicName &topic) {
        const QString content = QDateTime::currentDateTime().toString()
                + QLatin1String(" Received Topic: ")
                + topic.name()
                + QLatin1String(" Message: ")
                + message
                + QLatin1Char('\n');
        qDebug() << content;
        for(auto i : widgets)
        {
            if(QString::compare(topic.name(), i->getTopic()) == 0)
            {
                i->setValue(message);
            }
        }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_sub_clicked()
{
    sliderSubscription();
    QString topic = ui->topicLine->text();
    auto subscription = cli->subscribe(topic);
    subs.append(topic);
    //    if (!subscription) {
    //        QMessageBox::critical(this, QLatin1String("Error"), QLatin1String("Could not subscribe. Is there a valid connection?"));
    //        return;
    //    }
    qDebug() << "subscription = " << subscription;
}
void MainWindow::on_actionAdd_triggered()
{
    awd = new AddWidgetDialog(list);
    connect(awd, SIGNAL(AddWidget(QString, QString, QString)), this, SLOT(AddWidget(QString, QString, QString)));
    awd->show();
}

void MainWindow::AddWidget(QString type, QString name, QString topic)
{

    QUuid cur = TabsIdentifiers[currentTab];
    TabCustomWidget *tcw = Tabs[cur];
    qDebug() << "Adding...";
        if(QString::compare(type, QString::fromStdString("Indicator")) == 0)
        {
            IndicatorWidget *i = new IndicatorWidget(name, topic);
            widgets.append(i);
            tcw->getLayout()->addWidget(i);
        }else if(QString::compare(type, QString::fromStdString("Chart")) == 0)
        {
            ChartWidget *c = new ChartWidget(name, topic, ui->scrollAreaWidgetContents_2);
            widgets.append(c);
            tcw->getLayout()->addWidget(c);

        }else if(QString::compare(type, QString::fromStdString("Switcher")) == 0)
        {
            SwitcherWidget *s = new SwitcherWidget(name, topic);
            widgets.append(s);
            tcw->getLayout()->addWidget(s);
            connect(s, SIGNAL(inputValueChanged(QString, QString)), this, SLOT(sendValue(QString, QString)));
        }else if(QString::compare(type, QString::fromStdString("Input")) == 0)
        {
            InputWidget *ip = new InputWidget(name, topic);
            widgets.append(ip);
            tcw->getLayout()->addWidget(ip);
            connect(ip, SIGNAL(valueChanged(QString, QString)), this, SLOT(sendValue(QString, QString)));
        }else if(QString::compare(type, QString::fromStdString("Value")) == 0)
        {
            ValueWidget *v = new ValueWidget(name, topic);
            widgets.append(v);
            tcw->getLayout()->addWidget(v);
        }


    cli->subscribe(topic);
}

void MainWindow::sendValue(QString topic, QString value)
{
    cli->publish(topic, value.toUtf8());
}
void MainWindow::sliderSubscription()
{
    QString slider = QString::fromStdString("slider");
    auto subscription = cli->subscribe(slider);
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    if(index == ui->tabWidget->count()-1)
    {
        unsigned int newTab = ui->tabWidget->count()-1;
        QString tabName = "Tab" + QString::number(newTab);
        TabCustomWidget *tcw = new TabCustomWidget(tabName);
        Tabs.insert(tcw->getIndex(), tcw);
        TabsIdentifiers.insert(newTab, tcw->getIndex());
        currentTab = newTab;
        ui->tabWidget->insertTab(newTab, tcw->getTabWidget(), tabName);
        ui->tabWidget->setCurrentIndex(ui->tabWidget->count()-2);
    }else{
        currentTab = index;
    }
    qDebug() << ui->tabWidget->count();
    qDebug() << "index = " << index;
}


//void MainWindow::on_tabWidget_customContextMenuRequested(const QPoint &pos)
//{
//    TabMenu->addAction("Item 1");
//}


void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    qDebug() << "removing index = " << index;
    QUuid cur = TabsIdentifiers[index];
    for(int i=0;i<widgets.length();i++)
    {
        if(widgets.at(i)->getTabIndex() == cur)
        {
            delete widgets.at(i);
            widgets.remove(i);
        }
    }
    for(int i=index;i<ui->tabWidget->count();i++)
    {
        QUuid tmp = TabsIdentifiers[i];
        TabsIdentifiers.remove(i);
        TabsIdentifiers.insert(i-1, TabsIdentifiers[i]);

    }
    Tabs.remove(cur);
    ui->tabWidget->removeTab(index);
}

