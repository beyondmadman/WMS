#-------------------------------------------------
#
# Project created by QtCreator 2020-03-23T13:46:40
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WMS
TEMPLATE = app


SOURCES += main.cpp\
        wmswidget.cpp \
    lbutton.cpp \
    ltitlebar.cpp \
    ltoolbar.cpp \
    lcontentwidget.cpp \
    lshadowwidget.cpp \
    llogindlg.cpp \
    lnavbutton.cpp \
    lhomepage.cpp \
    lcurve.cpp \
    lhistogram.cpp \
    ltime.cpp \
    lsupplierpage.cpp \
    ldatabase.cpp

HEADERS  += wmswidget.h \
    lbutton.h \
    ltitlebar.h \
    ltoolbar.h \
    lcontentwidget.h \
    lshadowwidget.h \
    llogindlg.h \
    lnavbutton.h \
    lhomepage.h \
    lcurve.h \
    lhistogram.h \
    ltime.h \
    lsupplierpage.h \
    ldatabase.h

FORMS    +=

RESOURCES += \
    res.qrc
