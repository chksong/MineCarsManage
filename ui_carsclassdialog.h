/********************************************************************************
** Form generated from reading UI file 'carsclassdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARSCLASSDIALOG_H
#define UI_CARSCLASSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CarsClassDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_CarClass;
    QPushButton *pushButton;
    QTableView *tableView;

    void setupUi(QDialog *CarsClassDialog)
    {
        if (CarsClassDialog->objectName().isEmpty())
            CarsClassDialog->setObjectName(QString::fromUtf8("CarsClassDialog"));
        CarsClassDialog->resize(526, 428);
        verticalLayout = new QVBoxLayout(CarsClassDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, -1, 4, -1);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(CarsClassDialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit_CarClass = new QLineEdit(CarsClassDialog);
        lineEdit_CarClass->setObjectName(QString::fromUtf8("lineEdit_CarClass"));

        horizontalLayout->addWidget(lineEdit_CarClass);

        pushButton = new QPushButton(CarsClassDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);

        tableView = new QTableView(CarsClassDialog);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout->addWidget(tableView);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 9);

        retranslateUi(CarsClassDialog);

        QMetaObject::connectSlotsByName(CarsClassDialog);
    } // setupUi

    void retranslateUi(QDialog *CarsClassDialog)
    {
        CarsClassDialog->setWindowTitle(QApplication::translate("CarsClassDialog", "\346\214\226\346\216\230\346\234\272\345\236\213\345\217\267\347\256\241\347\220\206", nullptr));
        label->setText(QApplication::translate("CarsClassDialog", "\346\214\226\346\216\230\346\234\272\345\236\213\345\217\267", nullptr));
        pushButton->setText(QApplication::translate("CarsClassDialog", "\346\267\273\345\212\240", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CarsClassDialog: public Ui_CarsClassDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARSCLASSDIALOG_H
