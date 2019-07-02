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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddDayWorkDialog
{
public:
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QDateEdit *dateEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QComboBox *comboBox_2;
    QHBoxLayout *horizontalLayout_22;
    QHBoxLayout *horizontalLayout_20;
    QLabel *label_13;
    QLineEdit *lineEdit_4;
    QHBoxLayout *horizontalLayout_21;
    QLabel *label_14;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_5;
    QLineEdit *lineEdit_2;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_6;
    QComboBox *comboBox_3;
    QHBoxLayout *horizontalLayout_12;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_7;
    QSpinBox *spinBox;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_8;
    QSpinBox *spinBox_2;
    QHBoxLayout *horizontalLayout_13;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_9;
    QSpinBox *spinBox_3;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_10;
    QSpinBox *spinBox_4;
    QHBoxLayout *horizontalLayout_16;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_11;
    QSpinBox *spinBox_5;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_12;
    QSpinBox *spinBox_6;
    QHBoxLayout *horizontalLayout_23;
    QHBoxLayout *horizontalLayout_24;
    QLabel *label_15;
    QSpinBox *spinBox_7;
    QHBoxLayout *horizontalLayout_25;
    QLabel *label_16;
    QSpinBox *spinBox_8;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_28;
    QHBoxLayout *horizontalLayout_26;
    QLabel *label_17;
    QComboBox *comboBox_4;
    QHBoxLayout *horizontalLayout_27;
    QLabel *label_18;
    QComboBox *comboBox_5;
    QHBoxLayout *horizontalLayout_31;
    QHBoxLayout *horizontalLayout_30;
    QLabel *label_19;
    QLineEdit *lineEdit_3;
    QHBoxLayout *horizontalLayout_29;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_24;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_33;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label_20;
    QSpinBox *spinBox_9;
    QHBoxLayout *horizontalLayout_32;
    QLabel *label_21;
    QSpinBox *spinBox_10;
    QHBoxLayout *horizontalLayout_36;
    QHBoxLayout *horizontalLayout_34;
    QLabel *label_22;
    QDoubleSpinBox *doubleSpinBox;
    QHBoxLayout *horizontalLayout_35;
    QLabel *label_23;
    QDoubleSpinBox *doubleSpinBox_2;
    QTextEdit *textEdit;
    QPushButton *PB_TEST;

    void setupUi(QDialog *AddDayWorkDialog)
    {
        if (AddDayWorkDialog->objectName().isEmpty())
            AddDayWorkDialog->setObjectName(QString::fromUtf8("AddDayWorkDialog"));
        AddDayWorkDialog->resize(607, 641);
        verticalLayout_5 = new QVBoxLayout(AddDayWorkDialog);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        groupBox_2 = new QGroupBox(AddDayWorkDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(31);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        dateEdit = new QDateEdit(groupBox_2);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));

        horizontalLayout->addWidget(dateEdit);

        horizontalLayout->setStretch(0, 3);
        horizontalLayout->setStretch(1, 7);

        horizontalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        comboBox = new QComboBox(groupBox_2);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout_2->addWidget(comboBox);

        horizontalLayout_2->setStretch(0, 3);
        horizontalLayout_2->setStretch(1, 7);

        horizontalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(31);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_4->addWidget(label_2);

        lineEdit = new QLineEdit(groupBox_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_4->addWidget(lineEdit);

        horizontalLayout_4->setStretch(0, 3);
        horizontalLayout_4->setStretch(1, 7);

        horizontalLayout_6->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_5->addWidget(label_4);

        comboBox_2 = new QComboBox(groupBox_2);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setEditable(false);

        horizontalLayout_5->addWidget(comboBox_2);

        horizontalLayout_5->setStretch(0, 3);
        horizontalLayout_5->setStretch(1, 7);

        horizontalLayout_6->addLayout(horizontalLayout_5);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setSpacing(31);
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_20->addWidget(label_13);

        lineEdit_4 = new QLineEdit(groupBox_2);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        horizontalLayout_20->addWidget(lineEdit_4);


        horizontalLayout_22->addLayout(horizontalLayout_20);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setObjectName(QString::fromUtf8("horizontalLayout_21"));
        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_21->addWidget(label_14);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_21->addItem(horizontalSpacer);


        horizontalLayout_22->addLayout(horizontalLayout_21);

        horizontalLayout_22->setStretch(0, 1);
        horizontalLayout_22->setStretch(1, 1);

        verticalLayout_2->addLayout(horizontalLayout_22);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 1);
        verticalLayout_2->setStretch(2, 1);

        verticalLayout_5->addWidget(groupBox_2);

        groupBox = new QGroupBox(AddDayWorkDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(31);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_7->addWidget(label_5);

        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout_7->addWidget(lineEdit_2);

        horizontalLayout_7->setStretch(0, 1);
        horizontalLayout_7->setStretch(1, 1);

        horizontalLayout_9->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_8->addWidget(label_6);

        comboBox_3 = new QComboBox(groupBox);
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setEditable(true);

        horizontalLayout_8->addWidget(comboBox_3);


        horizontalLayout_9->addLayout(horizontalLayout_8);

        horizontalLayout_9->setStretch(0, 1);
        horizontalLayout_9->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(31);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_11->addWidget(label_7);

        spinBox = new QSpinBox(groupBox);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));

        horizontalLayout_11->addWidget(spinBox);


        horizontalLayout_12->addLayout(horizontalLayout_11);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_10->addWidget(label_8);

        spinBox_2 = new QSpinBox(groupBox);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));

        horizontalLayout_10->addWidget(spinBox_2);


        horizontalLayout_12->addLayout(horizontalLayout_10);


        verticalLayout->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(31);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_14->addWidget(label_9);

        spinBox_3 = new QSpinBox(groupBox);
        spinBox_3->setObjectName(QString::fromUtf8("spinBox_3"));

        horizontalLayout_14->addWidget(spinBox_3);


        horizontalLayout_13->addLayout(horizontalLayout_14);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_15->addWidget(label_10);

        spinBox_4 = new QSpinBox(groupBox);
        spinBox_4->setObjectName(QString::fromUtf8("spinBox_4"));

        horizontalLayout_15->addWidget(spinBox_4);


        horizontalLayout_13->addLayout(horizontalLayout_15);


        verticalLayout->addLayout(horizontalLayout_13);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(31);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_17->addWidget(label_11);

        spinBox_5 = new QSpinBox(groupBox);
        spinBox_5->setObjectName(QString::fromUtf8("spinBox_5"));

        horizontalLayout_17->addWidget(spinBox_5);


        horizontalLayout_16->addLayout(horizontalLayout_17);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_18->addWidget(label_12);

        spinBox_6 = new QSpinBox(groupBox);
        spinBox_6->setObjectName(QString::fromUtf8("spinBox_6"));

        horizontalLayout_18->addWidget(spinBox_6);


        horizontalLayout_16->addLayout(horizontalLayout_18);


        verticalLayout->addLayout(horizontalLayout_16);

        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setSpacing(31);
        horizontalLayout_23->setObjectName(QString::fromUtf8("horizontalLayout_23"));
        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setObjectName(QString::fromUtf8("horizontalLayout_24"));
        label_15 = new QLabel(groupBox);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        horizontalLayout_24->addWidget(label_15);

        spinBox_7 = new QSpinBox(groupBox);
        spinBox_7->setObjectName(QString::fromUtf8("spinBox_7"));

        horizontalLayout_24->addWidget(spinBox_7);


        horizontalLayout_23->addLayout(horizontalLayout_24);

        horizontalLayout_25 = new QHBoxLayout();
        horizontalLayout_25->setObjectName(QString::fromUtf8("horizontalLayout_25"));
        label_16 = new QLabel(groupBox);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        horizontalLayout_25->addWidget(label_16);

        spinBox_8 = new QSpinBox(groupBox);
        spinBox_8->setObjectName(QString::fromUtf8("spinBox_8"));

        horizontalLayout_25->addWidget(spinBox_8);


        horizontalLayout_23->addLayout(horizontalLayout_25);


        verticalLayout->addLayout(horizontalLayout_23);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 1);
        verticalLayout->setStretch(3, 1);
        verticalLayout->setStretch(4, 1);

        verticalLayout_5->addWidget(groupBox);

        groupBox_3 = new QGroupBox(AddDayWorkDialog);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayout_3 = new QVBoxLayout(groupBox_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_28 = new QHBoxLayout();
        horizontalLayout_28->setSpacing(31);
        horizontalLayout_28->setObjectName(QString::fromUtf8("horizontalLayout_28"));
        horizontalLayout_26 = new QHBoxLayout();
        horizontalLayout_26->setObjectName(QString::fromUtf8("horizontalLayout_26"));
        label_17 = new QLabel(groupBox_3);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        horizontalLayout_26->addWidget(label_17);

        comboBox_4 = new QComboBox(groupBox_3);
        comboBox_4->setObjectName(QString::fromUtf8("comboBox_4"));
        comboBox_4->setEditable(true);

        horizontalLayout_26->addWidget(comboBox_4);


        horizontalLayout_28->addLayout(horizontalLayout_26);

        horizontalLayout_27 = new QHBoxLayout();
        horizontalLayout_27->setObjectName(QString::fromUtf8("horizontalLayout_27"));
        label_18 = new QLabel(groupBox_3);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        horizontalLayout_27->addWidget(label_18);

        comboBox_5 = new QComboBox(groupBox_3);
        comboBox_5->setObjectName(QString::fromUtf8("comboBox_5"));

        horizontalLayout_27->addWidget(comboBox_5);


        horizontalLayout_28->addLayout(horizontalLayout_27);

        horizontalLayout_28->setStretch(0, 1);
        horizontalLayout_28->setStretch(1, 1);

        verticalLayout_3->addLayout(horizontalLayout_28);

        horizontalLayout_31 = new QHBoxLayout();
        horizontalLayout_31->setSpacing(31);
        horizontalLayout_31->setObjectName(QString::fromUtf8("horizontalLayout_31"));
        horizontalLayout_30 = new QHBoxLayout();
        horizontalLayout_30->setObjectName(QString::fromUtf8("horizontalLayout_30"));
        label_19 = new QLabel(groupBox_3);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        horizontalLayout_30->addWidget(label_19);

        lineEdit_3 = new QLineEdit(groupBox_3);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        horizontalLayout_30->addWidget(lineEdit_3);

        horizontalLayout_30->setStretch(0, 1);
        horizontalLayout_30->setStretch(1, 1);

        horizontalLayout_31->addLayout(horizontalLayout_30);

        horizontalLayout_29 = new QHBoxLayout();
        horizontalLayout_29->setObjectName(QString::fromUtf8("horizontalLayout_29"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_29->addItem(horizontalSpacer_2);

        label_24 = new QLabel(groupBox_3);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        horizontalLayout_29->addWidget(label_24);


        horizontalLayout_31->addLayout(horizontalLayout_29);

        horizontalLayout_31->setStretch(0, 1);
        horizontalLayout_31->setStretch(1, 1);

        verticalLayout_3->addLayout(horizontalLayout_31);


        verticalLayout_5->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(AddDayWorkDialog);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        verticalLayout_4 = new QVBoxLayout(groupBox_4);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_33 = new QHBoxLayout();
        horizontalLayout_33->setSpacing(31);
        horizontalLayout_33->setObjectName(QString::fromUtf8("horizontalLayout_33"));
        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        label_20 = new QLabel(groupBox_4);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        horizontalLayout_19->addWidget(label_20);

        spinBox_9 = new QSpinBox(groupBox_4);
        spinBox_9->setObjectName(QString::fromUtf8("spinBox_9"));

        horizontalLayout_19->addWidget(spinBox_9);


        horizontalLayout_33->addLayout(horizontalLayout_19);

        horizontalLayout_32 = new QHBoxLayout();
        horizontalLayout_32->setObjectName(QString::fromUtf8("horizontalLayout_32"));
        label_21 = new QLabel(groupBox_4);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        horizontalLayout_32->addWidget(label_21);

        spinBox_10 = new QSpinBox(groupBox_4);
        spinBox_10->setObjectName(QString::fromUtf8("spinBox_10"));

        horizontalLayout_32->addWidget(spinBox_10);


        horizontalLayout_33->addLayout(horizontalLayout_32);


        verticalLayout_4->addLayout(horizontalLayout_33);

        horizontalLayout_36 = new QHBoxLayout();
        horizontalLayout_36->setSpacing(31);
        horizontalLayout_36->setObjectName(QString::fromUtf8("horizontalLayout_36"));
        horizontalLayout_34 = new QHBoxLayout();
        horizontalLayout_34->setObjectName(QString::fromUtf8("horizontalLayout_34"));
        label_22 = new QLabel(groupBox_4);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        horizontalLayout_34->addWidget(label_22);

        doubleSpinBox = new QDoubleSpinBox(groupBox_4);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));

        horizontalLayout_34->addWidget(doubleSpinBox);


        horizontalLayout_36->addLayout(horizontalLayout_34);

        horizontalLayout_35 = new QHBoxLayout();
        horizontalLayout_35->setObjectName(QString::fromUtf8("horizontalLayout_35"));
        label_23 = new QLabel(groupBox_4);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        horizontalLayout_35->addWidget(label_23);

        doubleSpinBox_2 = new QDoubleSpinBox(groupBox_4);
        doubleSpinBox_2->setObjectName(QString::fromUtf8("doubleSpinBox_2"));

        horizontalLayout_35->addWidget(doubleSpinBox_2);


        horizontalLayout_36->addLayout(horizontalLayout_35);


        verticalLayout_4->addLayout(horizontalLayout_36);

        textEdit = new QTextEdit(groupBox_4);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout_4->addWidget(textEdit);

        verticalLayout_4->setStretch(0, 1);
        verticalLayout_4->setStretch(1, 1);
        verticalLayout_4->setStretch(2, 1);

        verticalLayout_5->addWidget(groupBox_4);

        PB_TEST = new QPushButton(AddDayWorkDialog);
        PB_TEST->setObjectName(QString::fromUtf8("PB_TEST"));

        verticalLayout_5->addWidget(PB_TEST);


        retranslateUi(AddDayWorkDialog);

        QMetaObject::connectSlotsByName(AddDayWorkDialog);
    } // setupUi

    void retranslateUi(QDialog *AddDayWorkDialog)
    {
        AddDayWorkDialog->setWindowTitle(QApplication::translate("AddDayWorkDialog", "Dialog", nullptr));
        groupBox_2->setTitle(QApplication::translate("AddDayWorkDialog", "\345\237\272\346\234\254\344\277\241\346\201\257", nullptr));
        label_3->setText(QApplication::translate("AddDayWorkDialog", "\345\267\245\344\275\234\346\227\245\346\234\237\357\274\232", nullptr));
        label->setText(QApplication::translate("AddDayWorkDialog", "\345\221\230\345\267\245\344\277\241\346\201\257", nullptr));
        label_2->setText(QApplication::translate("AddDayWorkDialog", "\350\275\246\345\217\267:", nullptr));
        label_4->setText(QApplication::translate("AddDayWorkDialog", "\345\223\201\347\211\214\345\236\213\345\217\267\357\274\232", nullptr));
        comboBox_2->setItemText(0, QApplication::translate("AddDayWorkDialog", "ffff", nullptr));
        comboBox_2->setItemText(1, QApplication::translate("AddDayWorkDialog", "ffff", nullptr));

        label_13->setText(QApplication::translate("AddDayWorkDialog", "\346\234\210\345\210\235\345\260\217\346\227\266\346\225\260:", nullptr));
        label_14->setText(QString());
        groupBox->setTitle(QApplication::translate("AddDayWorkDialog", "\346\227\245\350\243\205\347\237\277\351\207\217", nullptr));
        label_5->setText(QApplication::translate("AddDayWorkDialog", "\345\267\245\344\275\234\345\234\260\347\202\271", nullptr));
        label_6->setText(QApplication::translate("AddDayWorkDialog", "\345\267\245\344\275\234\347\261\273\345\236\213", nullptr));
        label_7->setText(QApplication::translate("AddDayWorkDialog", "\351\223\201\347\237\277\347\237\263\350\275\246\346\225\260\357\274\232", nullptr));
        label_8->setText(QApplication::translate("AddDayWorkDialog", "\351\223\201\347\237\277\347\237\263\345\220\250\346\225\260\357\274\232", nullptr));
        label_9->setText(QApplication::translate("AddDayWorkDialog", "\347\273\206\347\237\277\347\237\263\350\275\246\346\225\260\357\274\232", nullptr));
        label_10->setText(QApplication::translate("AddDayWorkDialog", "\347\273\206\347\237\277\347\237\263\345\220\250\346\225\260\357\274\232", nullptr));
        label_11->setText(QApplication::translate("AddDayWorkDialog", "\345\260\276\347\237\277\350\275\246\346\225\260\357\274\232", nullptr));
        label_12->setText(QApplication::translate("AddDayWorkDialog", "\345\260\276\347\237\277\345\220\250\346\225\260\357\274\232", nullptr));
        label_15->setText(QApplication::translate("AddDayWorkDialog", "\345\211\245\345\262\251\350\275\246\346\225\260\357\274\232", nullptr));
        label_16->setText(QApplication::translate("AddDayWorkDialog", "\345\211\245\345\262\251\345\220\250\346\225\260\357\274\232", nullptr));
        groupBox_3->setTitle(QApplication::translate("AddDayWorkDialog", "\346\227\245\345\267\245\346\227\266\346\225\260", nullptr));
        label_17->setText(QApplication::translate("AddDayWorkDialog", "\345\267\245\344\275\234\345\234\260\347\202\271", nullptr));
        label_18->setText(QApplication::translate("AddDayWorkDialog", "\345\267\245\344\275\234\347\261\273\345\236\213", nullptr));
        label_19->setText(QApplication::translate("AddDayWorkDialog", "\345\267\245\346\227\266\346\225\260", nullptr));
        label_24->setText(QApplication::translate("AddDayWorkDialog", "0", nullptr));
        groupBox_4->setTitle(QApplication::translate("AddDayWorkDialog", "\346\200\273\347\273\223\344\277\241\346\201\257", nullptr));
        label_20->setText(QApplication::translate("AddDayWorkDialog", "\346\234\254\346\227\245\345\267\245\344\275\234\346\227\266\351\225\277:", nullptr));
        label_21->setText(QApplication::translate("AddDayWorkDialog", "\346\237\264\346\262\271\347\224\250\351\207\217:", nullptr));
        label_22->setText(QApplication::translate("AddDayWorkDialog", "\346\235\220\346\226\231\350\264\271\357\274\232", nullptr));
        doubleSpinBox->setSuffix(QApplication::translate("AddDayWorkDialog", " \345\205\203", nullptr));
        label_23->setText(QApplication::translate("AddDayWorkDialog", "\344\277\256\347\220\206\350\264\271:", nullptr));
        doubleSpinBox_2->setSuffix(QApplication::translate("AddDayWorkDialog", " \345\205\203", nullptr));
        PB_TEST->setText(QApplication::translate("AddDayWorkDialog", "TEST_fun", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddDayWorkDialog: public Ui_AddDayWorkDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDDAYWORKDIALOG_H
