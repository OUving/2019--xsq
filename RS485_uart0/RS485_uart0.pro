#-------------------------------------------------
#
# Project created by QtCreator 2019-04-08T10:39:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RS485_uart0
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    encode_and_decode.c \
    crc16.c \
    RS485_de.c \
    widget1.cpp \
    widget2.cpp \
    widget3.cpp \
    posix_qextserialport.cpp \
    qextserialbase.cpp \
    start_page.cpp \
    login_window.cpp \
    manual_adjust.cpp \
    widget4.cpp

HEADERS  += mainwindow.h \
    encode_and_decode.h \
    crc16.h \
    common.h \
    RS485_de.h \
    widget1.h \
    widget2.h \
    widget3.h \
    posix_qextserialport.h \
    qextserialbase.h \
    start_page.h \
    login_window.h \
    manual_adjust.h \
    widget4.h

FORMS    += mainwindow.ui \
    widget1.ui \
    widget2.ui \
    widget3.ui \
    start_page.ui \
    login_window.ui \
    manual_adjust.ui \
    widget4.ui
