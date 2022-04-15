QT       += core gui network mqtt charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addwidgetdialog.cpp \
    chartwidget.cpp \
#    coordinatemapper.cpp \
    #indicator.cpp \
    indicatorwidget.cpp \
    inputwidget.cpp \
    main.cpp \
    mainwindow.cpp \
    mqttwidget.cpp \
    switcherwidget.cpp \
    valuewidget.cpp

HEADERS += \
    addwidgetdialog.h \
    chartwidget.h \
#    coordinatemapper.h \
    #indicator.h \
    indicatorwidget.h \
    inputwidget.h \
    mainwindow.h \
    mqttwidget.h \
    switcherwidget.h \
    valuewidget.h

FORMS += \
    addwidgetdialog.ui \
    chartwidget.ui \
    indicatorwidget.ui \
    inputwidget.ui \
    mainwindow.ui \
    switcherwidget.ui \
    valuewidget.ui

# Default rules for deployment.
#qnx: target.path = /tmp/$${TARGET}/bin
#else: unix:!android: target.path = /opt/$${TARGET}/bin
#!isEmpty(target.path): INSTALLS += target

target.path = $$[QT_INSTALL_EXAMPLES]/mqtt/mqtt_sub
INSTALLS += target
