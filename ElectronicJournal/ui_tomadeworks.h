/********************************************************************************
** Form generated from reading UI file 'tomadeworks.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOMADEWORKS_H
#define UI_TOMADEWORKS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ToMadeWorks
{
public:
    QLabel *label;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_6;
    QComboBox *comboBox;
    QLabel *label_7;
    QComboBox *comboBox_2;
    QLabel *label_3;
    QComboBox *comboBox_3;
    QLabel *label_8;
    QComboBox *comboBox_4;
    QPushButton *pushButton;

    void setupUi(QWidget *ToMadeWorks)
    {
        if (ToMadeWorks->objectName().isEmpty())
            ToMadeWorks->setObjectName(QStringLiteral("ToMadeWorks"));
        ToMadeWorks->resize(386, 491);
        label = new QLabel(ToMadeWorks);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(150, 30, 91, 21));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        verticalLayoutWidget = new QWidget(ToMadeWorks);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(50, 70, 281, 331));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_3->addWidget(label_6);

        comboBox = new QComboBox(verticalLayoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        verticalLayout_3->addWidget(comboBox);

        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout_3->addWidget(label_7);

        comboBox_2 = new QComboBox(verticalLayoutWidget);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));

        verticalLayout_3->addWidget(comboBox_2);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_3->addWidget(label_3);

        comboBox_3 = new QComboBox(verticalLayoutWidget);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));

        verticalLayout_3->addWidget(comboBox_3);

        label_8 = new QLabel(verticalLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        verticalLayout_3->addWidget(label_8);

        comboBox_4 = new QComboBox(verticalLayoutWidget);
        comboBox_4->setObjectName(QStringLiteral("comboBox_4"));

        verticalLayout_3->addWidget(comboBox_4);

        pushButton = new QPushButton(ToMadeWorks);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(50, 410, 281, 51));

        retranslateUi(ToMadeWorks);

        QMetaObject::connectSlotsByName(ToMadeWorks);
    } // setupUi

    void retranslateUi(QWidget *ToMadeWorks)
    {
        ToMadeWorks->setWindowTitle(QApplication::translate("ToMadeWorks", "Form", 0));
        label->setText(QApplication::translate("ToMadeWorks", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265: ", 0));
        label_6->setText(QApplication::translate("ToMadeWorks", "\320\224\320\260\321\202\320\260:", 0));
        label_7->setText(QApplication::translate("ToMadeWorks", "\320\223\321\200\321\203\320\277\320\277\320\260:", 0));
        label_3->setText(QApplication::translate("ToMadeWorks", "\320\224\320\270\321\201\321\206\320\270\320\277\320\273\320\270\320\275\320\260:", 0));
        label_8->setText(QApplication::translate("ToMadeWorks", "\320\222\320\270\320\264 \321\200\320\260\320\261\320\276\321\202:", 0));
        pushButton->setText(QApplication::translate("ToMadeWorks", "\320\241\320\264\320\260\320\275\320\275\321\213\320\265 \321\200\320\260\320\261\320\276\321\202\321\213", 0));
    } // retranslateUi

};

namespace Ui {
    class ToMadeWorks: public Ui_ToMadeWorks {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOMADEWORKS_H
