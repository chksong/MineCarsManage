#-------------------------------------------------
#
# Project created by QtCreator 2019-06-30T11:14:04
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MineCarsManage
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

CONFIG += c++11



SOURCES += \
        HTableview/HHeaderItemDelegate.cpp \
        HTableview/HHeaderModel.cpp \
        HTableview/HHeaderView.cpp \
        HTableview/TcTabelModel.cpp \
        HTableview/TcTableView.cpp \
        HTableview/TcTableWidget.cpp \
        adddayworkdialog.cpp \
        carsclassdialog.cpp \
        carsmanagedialog.cpp \
        dialoghelp.cpp \
        main.cpp \
        mainwindow.cpp \
        mysqldbhelp.cpp \
        peopledialog.cpp

HEADERS += \
        HTableview/HHeaderItemDelegate.h \
        HTableview/HHeaderModel.h \
        HTableview/HHeaderView.h \
        HTableview/TcTabelModel.h \
        HTableview/TcTableView.h \
        HTableview/TcTableWidget.h \
        adddayworkdialog.h \
        carsclassdialog.h \
        carsmanagedialog.h \
        dialoghelp.h \
        mainwindow.h \
        mysqldbhelp.h \
        peopledialog.h

FORMS += \
        HTableview/TcTableWidget.ui \
        adddayworkdialog.ui \
        carsclassdialog.ui \
        carsmanagedialog.ui \
        dialoghelp.ui \
        mainwindow.ui \
        peopledialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
