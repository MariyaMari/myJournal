/********************************************************************************
** Form generated from reading UI file 'tablecompositiongroup.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLECOMPOSITIONGROUP_H
#define UI_TABLECOMPOSITIONGROUP_H

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

class Ui_TableCompositionGroup
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QTableView *tableView;
    QLabel *label;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QWidget *TableCompositionGroup)
    {
        if (TableCompositionGroup->objectName().isEmpty())
            TableCompositionGroup->setObjectName(QStringLiteral("TableCompositionGroup"));
        TableCompositionGroup->resize(386, 491);
        verticalLayoutWidget = new QWidget(TableCompositionGroup);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 50, 361, 371));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tableView = new QTableView(verticalLayoutWidget);
        tableView->setObjectName(QStringLiteral("tableView"));

        verticalLayout->addWidget(tableView);

        label = new QLabel(TableCompositionGroup);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(140, 20, 131, 21));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        gridLayoutWidget = new QWidget(TableCompositionGroup);
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


        retranslateUi(TableCompositionGroup);

        QMetaObject::connectSlotsByName(TableCompositionGroup);
    } // setupUi

    void retranslateUi(QWidget *TableCompositionGroup)
    {
        TableCompositionGroup->setWindowTitle(QApplication::translate("TableCompositionGroup", "Form", 0));
        label->setText(QApplication::translate("TableCompositionGroup", "\320\241\320\276\321\201\321\202\320\260\320\262 \320\263\321\200\321\203\320\277\320\277", 0));
        pushButton->setText(QApplication::translate("TableCompositionGroup", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", 0));
        pushButton_2->setText(QApplication::translate("TableCompositionGroup", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", 0));
        pushButton_3->setText(QApplication::translate("TableCompositionGroup", "\320\237\320\276\320\264\321\202\320\262\320\265\321\200\320\264\320\270\321\202\321\214", 0));
    } // retranslateUi

};

namespace Ui {
    class TableCompositionGroup: public Ui_TableCompositionGroup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLECOMPOSITIONGROUP_H
