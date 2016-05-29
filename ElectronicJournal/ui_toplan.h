/********************************************************************************
** Form generated from reading UI file 'toplan.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOPLAN_H
#define UI_TOPLAN_H

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

class Ui_ToPlan
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_4;
    QComboBox *comboBox;
    QLabel *label_5;
    QComboBox *comboBox_2;
    QPushButton *pushButton;
    QLabel *label;

    void setupUi(QWidget *ToPlan)
    {
        if (ToPlan->objectName().isEmpty())
            ToPlan->setObjectName(QStringLiteral("ToPlan"));
        ToPlan->resize(386, 491);
        verticalLayoutWidget = new QWidget(ToPlan);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(50, 120, 281, 191));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_2->addWidget(label_4);

        comboBox = new QComboBox(verticalLayoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        verticalLayout_2->addWidget(comboBox);

        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_2->addWidget(label_5);

        comboBox_2 = new QComboBox(verticalLayoutWidget);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));

        verticalLayout_2->addWidget(comboBox_2);

        pushButton = new QPushButton(ToPlan);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(50, 340, 281, 51));
        label = new QLabel(ToPlan);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(150, 60, 91, 21));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);

        retranslateUi(ToPlan);

        QMetaObject::connectSlotsByName(ToPlan);
    } // setupUi

    void retranslateUi(QWidget *ToPlan)
    {
        ToPlan->setWindowTitle(QApplication::translate("ToPlan", "Form", 0));
        label_4->setText(QApplication::translate("ToPlan", "\320\241\320\265\320\274\320\265\321\201\321\202\321\200:", 0));
        label_5->setText(QApplication::translate("ToPlan", "\320\241\320\277\320\265\321\206\320\270\320\260\320\273\321\214\320\275\320\276\321\201\321\202\321\214:", 0));
        pushButton->setText(QApplication::translate("ToPlan", "\320\237\320\273\320\260\320\275", 0));
        label->setText(QApplication::translate("ToPlan", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265: ", 0));
    } // retranslateUi

};

namespace Ui {
    class ToPlan: public Ui_ToPlan {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOPLAN_H
