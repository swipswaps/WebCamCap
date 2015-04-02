#-------------------------------------------------
#
# Project created by QtCreator 2015-03-31T23:50:54
#
#-------------------------------------------------

greaterThan(QT_MAJOR_VERSION, 5): QT += widgets

QT += network widgets

TARGET = WebCamCapAPI
TEMPLATE = lib
CONFIG += staticlib
CONFIG += c++11

SOURCES += \
    controlpanel.cpp \
    myfifo.cpp \
    point.cpp \
    movement.cpp

HEADERS += \
    controlpanel.h \
    myfifo.h \
    point.h \
    movement.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

FORMS += \
    controlpanel.ui

QMAKE_CXXFLAGS += -std=c++11 -pedantic -Wall -Wextra