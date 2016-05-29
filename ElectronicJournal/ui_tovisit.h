/********************************************************************************
** Form generated from reading UI file 'tovisit.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOVISIT_H
#define UI_TOVISIT_H

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

class Ui_ToVisit
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_4;
    QComboBox *comboBox;
    QLabel *label_5;
    QComboBox *comboBox_2;
    QLabel *label_2;
    QComboBox *comboBox_3;

    void setupUi(QWidget *ToVisit)
    {
        if (ToVisit->objectName().isEmpty())
            ToVisit->setObjectName(QStringLiteral("ToVisit"));
        ToVisit->resize(386, 491);
        label = new QLabel(ToVisit);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(150, 40, 91, 21));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        pushButton = new QPushButton(ToVisit);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(50, 400, 281, 51));
        verticalLayoutWidget = new QWidget(ToVisit);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(50, 90, 281, 291));
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

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);

        comboBox_3 = new QComboBox(verticalLayoutWidget);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));

        verticalLayout_2->addWidget(comboBox_3);


        retranslateUi(ToVisit);

        QMetaObject::connectSlotsByName(ToVisit);
    } // setupUi

    void retranslateUi(QWidget *ToVisit)
    {
        ToVisit->setWindowTitle(QApplication::translate("ToVisit", "Form", 0));
        label->setText(QApplication::translate("ToVisit", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265: ", 0));
        pushButton->setText(QApplication::translate("ToVisit", "\320\237\320\276\321\201\320\265\321\211\320\260\320\265\320\274\320\276\321\201\321\202\321\214", 0));
        label_4->setText(QApplication::translate("ToVisit", "\320\224\320\260\321\202\320\260:", 0));
        label_5->setText(QApplication::translate("ToVisit", "\320\224\320\270\321\201\321\206\320\270\320\277\320\273\320\270\320\275\320\260:", 0));
        label_2->setText(QApplication::translate("ToVisit", "\320\222\320\270\320\264 \321\200\320\260\320\261\320\276\321\202\321\213:", 0));
    } // retranslateUi

};

namespace Ui {
    class ToVisit: public Ui_ToVisit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOVISIT_H
