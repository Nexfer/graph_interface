#-------------------------------------------------
#
# Project created by QtCreator 2014-01-19T13:17:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cifers
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    cezar.cpp \
    vigenere.cpp \
    stegano.cpp \
    des.cpp

HEADERS  += mainwindow.h \
    cezar.h \
    vigenere.h \
    stegano.h \
    des.h \
    des.h

FORMS    += mainwindow.ui \
    cezar.ui \
    vigenere.ui \
    stegano.ui \
    des.ui
