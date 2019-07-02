/********************************************************************************
** Form generated from reading UI file 'adddayworkdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDDAYWORKDIALOG_H
#define UI_ADDDAYWORKDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_AddDayWorkDialog
{
public:
    QLabel *label;
    QComboBox *comboBox;
    QDateEdit *dateEdit;
    QDateTimeEdit *dateTimeEdit;
    QLabel *label_2;
    QCalendarWidget *calendarWidget;
    QTextEdit *textEdit;
    QPushButton *PB_TEST;

    void setupUi(QDialog *AddDayWorkDialog)
    {
        if (AddDayWorkDialog->objectName().isEmpty())
            AddDayWorkDialog->setObjectName(QString::fromUtf8("AddDayWorkDialog"));
        AddDayWorkDialog->resize(549, 467);
        label = new QLabel(AddDayWorkDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(340, 60, 54, 12));
        comboBox = new QComboBox(AddDayWorkDialog);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(410, 60, 81, 22));
        dateEdit = new QDateEdit(AddDayWorkDialog);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setGeometry(QRect(370, 20, 118, 22));
        dateTimeEdit = new QDateTimeEdit(AddDayWorkDialog);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        dateTimeEdit->setGeometry(QRect(30, 20, 194, 22));
        label_2 = new QLabel(AddDayWorkDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 60, 54, 12));
        calendarWidget = new QCalendarWidget(AddDayWorkDialog);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        calendarWidget->setGeometry(QRect(130, 190, 248, 197));
        textEdit = new QTextEdit(AddDayWorkDialog);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(60, 50, 101, 21));
        PB_TEST = new QPushButton(AddDayWorkDialog);
        PB_TEST->setObjectName(QString::fromUtf8("PB_TEST"));
        PB_TEST->setGeometry(QRect(240, 20, 75, 23));

        retranslateUi(AddDayWorkDialog);

        QMetaObject::connectSlotsByName(AddDayWorkDialog);
    } // setupUi

    void retranslateUi(QDialog *AddDayWorkDialog)
    {
        AddDayWorkDialog->setWindowTitle(QApplication::translate("AddDayWorkDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("AddDayWorkDialog", "\345\221\230\345\267\245\344\277\241\346\201\257", nullptr));
        label_2->setText(QApplication::translate("AddDayWorkDialog", "\350\275\246\345\217\267", nullptr));
        PB_TEST->setText(QApplication::translate("AddDayWorkDialog", "TEST_fun", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddDayWorkDialog: public Ui_AddDayWorkDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDDAYWORKDIALOG_H
