QT += core
QT -= gui

CONFIG += c++11

TARGET = Menu
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += ../Src/ckeyread.cpp \
    ../Src/cmenuctrl.cpp \
    ../Src/cmenupage.cpp \
    ../Src/cwidget.cpp \
    ../Src/cwidgetmenu.cpp \
    ../Src/cwidgetnumber.cpp \
    ../Src/cwidgetstatus.cpp \
    ../Src/main.cpp

LIBS += -lncurses

HEADERS += ../Src/ckeyread.h \
    ../Src/cmenuctrl.h \
    ../Src/cmenupage.h \
    ../Src/cwidget.h \
    ../Src/cwidgetmenu.h \
    ../Src/cwidgetnumber.h \
    ../Src/cwidgetstatus.h
