/********************************************************************************
** Form generated from reading UI file 'tolistworks.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOLISTWORKS_H
#define UI_TOLISTWORKS_H

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

class Ui_ToListWorks
{
public:
    QPushButton *pushButton;
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
    QLabel *label;

    void setupUi(QWidget *ToListWorks)
    {
        if (ToListWorks->objectName().isEmpty())
            ToListWorks->setObjectName(QStringLiteral("ToListWorks"));
        ToListWorks->resize(386, 491);
        pushButton = new QPushButton(ToListWorks);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(50, 410, 281, 51));
        verticalLayoutWidget = new QWidget(ToListWorks);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(50, 80, 281, 321));
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

        label = new QLabel(ToListWorks);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(150, 40, 91, 21));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);

        retranslateUi(ToListWorks);

        QMetaObject::connectSlotsByName(ToListWorks);
    } // setupUi

    void retranslateUi(QWidget *ToListWorks)
    {
        ToListWorks->setWindowTitle(QApplication::translate("ToListWorks", "Form", 0));
        pushButton->setText(QApplication::translate("ToListWorks", "\320\241\320\277\320\270\321\201\320\276\320\272 \321\200\320\260\320\261\320\276\321\202", 0));
        label_6->setText(QApplication::translate("ToListWorks", "\320\241\320\265\320\274\320\265\321\201\321\202\321\200:", 0));
        label_7->setText(QApplication::translate("ToListWorks", "\320\241\320\277\320\265\321\206\320\270\320\260\320\273\321\214\320\275\320\276\321\201\321\202\321\214:", 0));
        label_3->setText(QApplication::translate("ToListWorks", "\320\224\320\270\321\201\321\206\320\270\320\277\320\273\320\270\320\275\320\260:", 0));
        label_8->setText(QApplication::translate("ToListWorks", "\320\222\320\270\320\264 \321\200\320\260\320\261\320\276\321\202:", 0));
        label->setText(QApplication::translate("ToListWorks", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265: ", 0));
    } // retranslateUi

};

namespace Ui {
    class ToListWorks: public Ui_ToListWorks {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOLISTWORKS_H
