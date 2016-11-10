QT += core
QT -= gui

CONFIG += c++11

TARGET = Menu
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    ckeyread.cpp \
    cmenuctrl.cpp \
    cmenupage.cpp \
    cwidget.cpp \
    cwidgetstatus.cpp \
    cwidgetnumber.cpp

LIBS += -lncurses

HEADERS += \
    ckeyread.h \
    cmenuctrl.h \
    cmenupage.h \
    cwidget.h \
    cwidgetstatus.h \
    cwidgetnumber.h
