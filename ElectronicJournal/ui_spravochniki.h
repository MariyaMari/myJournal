/********************************************************************************
** Form generated from reading UI file 'spravochniki.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPRAVOCHNIKI_H
#define UI_SPRAVOCHNIKI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Spravochniki
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QLabel *label;

    void setupUi(QWidget *Spravochniki)
    {
        if (Spravochniki->objectName().isEmpty())
            Spravochniki->setObjectName(QStringLiteral("Spravochniki"));
        Spravochniki->resize(386, 491);
        verticalLayoutWidget = new QWidget(Spravochniki);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(79, 109, 231, 331));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(verticalLayoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(verticalLayoutWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        verticalLayout->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(verticalLayoutWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        verticalLayout->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(verticalLayoutWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        verticalLayout->addWidget(pushButton_6);

        label = new QLabel(Spravochniki);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(140, 40, 121, 21));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);

        retranslateUi(Spravochniki);

        QMetaObject::connectSlotsByName(Spravochniki);
    } // setupUi

    void retranslateUi(QWidget *Spravochniki)
    {
        Spravochniki->setWindowTitle(QApplication::translate("Spravochniki", "Form", 0));
        pushButton->setText(QApplication::translate("Spravochniki", "\320\224\320\270\321\201\321\206\320\270\320\277\320\273\320\270\320\275\320\260", 0));
        pushButton_2->setText(QApplication::translate("Spravochniki", "\320\241\320\277\320\265\321\206\320\270\320\260\320\273\321\214\320\275\320\276\321\201\321\202\321\214", 0));
        pushButton_3->setText(QApplication::translate("Spravochniki", "\320\242\320\270\320\277 \321\200\320\260\320\261\320\276\321\202", 0));
        pushButton_4->setText(QApplication::translate("Spravochniki", "\320\244\320\260\320\272\321\203\320\273\321\214\321\202\320\265\321\202", 0));
        pushButton_5->setText(QApplication::translate("Spravochniki", "\320\241\321\202\321\203\320\264\320\265\320\275\321\202\321\213", 0));
        pushButton_6->setText(QApplication::translate("Spravochniki", "\320\223\321\200\321\203\320\277\320\277\320\260", 0));
        label->setText(QApplication::translate("Spravochniki", "\320\241\320\277\321\200\320\260\320\262\320\276\321\207\320\275\320\270\320\272\320\270", 0));
    } // retranslateUi

};

namespace Ui {
    class Spravochniki: public Ui_Spravochniki {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPRAVOCHNIKI_H
