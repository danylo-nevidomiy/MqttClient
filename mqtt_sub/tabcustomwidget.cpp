#include "tabcustomwidget.h"

TabCustomWidget::TabCustomWidget(QString tabName)
{
    index = QUuid::createUuid();
    setTabName(tabName);
    TabWidget = new QWidget();
    boxLayout = new QVBoxLayout(TabWidget);
    area = new QScrollArea(TabWidget);
    WidgetsArea = new QWidget(area);
    layout = new QGridLayout(WidgetsArea);
    TabWidget->setLayout(boxLayout);
    boxLayout->addWidget(area);
    area->setWidget(WidgetsArea);
    TabWidget->setLayout(layout);
}

TabCustomWidget::~TabCustomWidget()
{
    delete layout;
    delete WidgetsArea;
    delete area;
    delete boxLayout;
    delete TabWidget;
}

QWidget *TabCustomWidget::getTabWidget() const
{
    return TabWidget;
}

QGridLayout *TabCustomWidget::getLayout() const
{
    return layout;
}

const QString &TabCustomWidget::getTabName() const
{
    return tabName;
}

void TabCustomWidget::setTabName(const QString &newTabName)
{
    tabName = newTabName;
}

const QUuid &TabCustomWidget::getIndex() const
{
    return index;
}

void TabCustomWidget::setIndex(const QUuid &newIndex)
{
    index = newIndex;
}

