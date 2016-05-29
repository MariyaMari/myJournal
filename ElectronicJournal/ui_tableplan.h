/********************************************************************************
** Form generated from reading UI file 'tableplan.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLEPLAN_H
#define UI_TABLEPLAN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TablePlan
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QTableView *tableView;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *label;

    void setupUi(QWidget *TablePlan)
    {
        if (TablePlan->objectName().isEmpty())
            TablePlan->setObjectName(QStringLiteral("TablePlan"));
        TablePlan->resize(386, 491);
        verticalLayoutWidget = new QWidget(TablePlan);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 50, 361, 371));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tableView = new QTableView(verticalLayoutWidget);
        tableView->setObjectName(QStringLiteral("tableView"));

        verticalLayout->addWidget(tableView);

        gridLayoutWidget = new QWidget(TablePlan);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 429, 361, 41));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(gridLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(gridLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 0, 1, 1, 1);

        pushButton_3 = new QPushButton(gridLayoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 0, 2, 1, 1);

        label = new QLabel(TablePlan);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(170, 20, 81, 21));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);

        retranslateUi(TablePlan);

        QMetaObject::connectSlotsByName(TablePlan);
    } // setupUi

    void retranslateUi(QWidget *TablePlan)
    {
        TablePlan->setWindowTitle(QApplication::translate("TablePlan", "Form", 0));
        pushButton->setText(QApplication::translate("TablePlan", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", 0));
        pushButton_2->setText(QApplication::translate("TablePlan", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", 0));
        pushButton_3->setText(QApplication::translate("TablePlan", "\320\237\320\276\320\264\321\202\320\262\320\265\321\200\320\264\320\270\321\202\321\214", 0));
        label->setText(QApplication::translate("TablePlan", "\320\237\320\273\320\260\320\275", 0));
    } // retranslateUi

};

namespace Ui {
    class TablePlan: public Ui_TablePlan {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLEPLAN_H
