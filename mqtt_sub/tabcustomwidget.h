#ifndef TABCUSTOMWIDGET_H
#define TABCUSTOMWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QUuid>

class TabCustomWidget
{
public:
    TabCustomWidget(QString tabName);
    ~TabCustomWidget();
    QWidget *getTabWidget() const;
    QGridLayout *getLayout() const;

    const QString &getTabName() const;
    void setTabName(const QString &newTabName);

    const QUuid &getIndex() const;
    void setIndex(const QUuid &newIndex);

private:
    QUuid index;
    QString tabName;
    QWidget *TabWidget;
    QVBoxLayout *boxLayout = new QVBoxLayout();
    QScrollArea *area = new QScrollArea();
    QWidget *WidgetsArea = new QWidget();
    QGridLayout *layout = new QGridLayout();
};

#endif // TABCUSTOMWIDGET_H
