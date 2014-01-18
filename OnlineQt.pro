#-------------------------------------------------
#
# Project created by QtCreator 2014-01-06T12:24:59
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OnlineQt
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    application.cpp \
    chat/chatwidget.cpp \
    game/gameareawidget.cpp \
    network/tcpserverwidget.cpp \
    network/tcpclientwidget.cpp \
    game/boardcanvaswidget.cpp \
    game/gameobject.cpp \
    common.cpp \
    game/gameobjectgraphicitem.cpp


HEADERS  += mainwindow.h \
    application.h \
    chat/chatwidget.h \
    game/gameareawidget.h \
    network/tcpserverwidget.h \
    network/tcpclientwidget.h \
    game/boardcanvaswidget.h \
    game/gameobject.h \
    common.h \
    game/gameobjectgraphicitem.h

FORMS    += mainwindow.ui \
    chat/chatwidget.ui \
    game/gameareawidget.ui \
    network/tcpserverwidget.ui \
    network/tcpclientwidget.ui

RESOURCES += \
    resources.qrc

