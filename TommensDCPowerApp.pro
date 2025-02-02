#-------------------------------------------------
#
# Project created by QtCreator 2019-04-26T10:31:51
#
#-------------------------------------------------

QT       += core gui sql serialport xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TommetDCPowerApp
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        Channel.cpp \
        Device.cpp \
        ModBusComInfo.cpp \
        ModbusCRC.cpp \
        ShortCutKeyList.cpp \
        WSDataBaseContol.cpp \
        basicsetdialog.cpp \
        main.cpp \
        mainwindow.cpp \
        writecomlogs.cpp

HEADERS += \
        Channel.h \
        Device.h \
        ModBusComInfo.h \
        ModbusCRC.h \
        ShortCutKeyList.h \
        WSDataBaseContol.h \
        basicsetdialog.h \
        mainwindow.h \
        writecomlogs.h

FORMS += \
        basicsetdialog.ui \
        mainwindow.ui
TRANSLATIONS += English.ts\
                Chinese.ts

RESOURCES += \
    etommensico.qrc
RC_ICONS =bitbug_favicon.ico
