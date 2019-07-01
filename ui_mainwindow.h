/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionCar;
    QAction *actiondriver;
    QAction *actionCarsClass;
    QAction *actionCarsManag;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(574, 492);
        actionCar = new QAction(MainWindow);
        actionCar->setObjectName(QString::fromUtf8("actionCar"));
        actiondriver = new QAction(MainWindow);
        actiondriver->setObjectName(QString::fromUtf8("actiondriver"));
        actionCarsClass = new QAction(MainWindow);
        actionCarsClass->setObjectName(QString::fromUtf8("actionCarsClass"));
        actionCarsManag = new QAction(MainWindow);
        actionCarsManag->setObjectName(QString::fromUtf8("actionCarsManag"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 574, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        menu_4 = new QMenu(menuBar);
        menu_4->setObjectName(QString::fromUtf8("menu_4"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menuBar->addAction(menu_4->menuAction());
        menu_3->addAction(actionCarsClass);
        menu_3->addAction(actionCarsManag);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\347\237\277\350\275\246\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        actionCar->setText(QApplication::translate("MainWindow", "\347\237\277\350\275\246", nullptr));
        actiondriver->setText(QApplication::translate("MainWindow", "\345\217\270\346\234\272\347\256\241\347\220\206", nullptr));
        actionCarsClass->setText(QApplication::translate("MainWindow", "\347\261\273\345\236\213\347\256\241\347\220\206", nullptr));
        actionCarsManag->setText(QApplication::translate("MainWindow", "\350\275\246\350\276\206\347\256\241\347\220\206", nullptr));
        menu->setTitle(QApplication::translate("MainWindow", "\347\256\241\347\220\206", nullptr));
        menu_2->setTitle(QApplication::translate("MainWindow", "\346\227\245\345\270\270\347\256\241\347\220\206", nullptr));
        menu_3->setTitle(QApplication::translate("MainWindow", "\350\275\246\350\276\206\347\256\241\347\220\206", nullptr));
        menu_4->setTitle(QApplication::translate("MainWindow", "\344\272\272\345\221\230\347\256\241\347\220\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
