/********************************************************************************
** Form generated from reading UI file 'formstudents.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMSTUDENTS_H
#define UI_FORMSTUDENTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormStudents
{
public:
    QLabel *label;
    QTableView *tableView;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QPushButton *pushButton_3;

    void setupUi(QWidget *FormStudents)
    {
        if (FormStudents->objectName().isEmpty())
            FormStudents->setObjectName(QStringLiteral("FormStudents"));
        FormStudents->resize(386, 491);
        label = new QLabel(FormStudents);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(160, 20, 101, 31));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        tableView = new QTableView(FormStudents);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(10, 50, 361, 371));
        gridLayoutWidget = new QWidget(FormStudents);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 429, 361, 51));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_2 = new QPushButton(gridLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 0, 1, 1, 1);

        pushButton = new QPushButton(gridLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);

        pushButton_3 = new QPushButton(gridLayoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 0, 2, 1, 1);


        retranslateUi(FormStudents);

        QMetaObject::connectSlotsByName(FormStudents);
    } // setupUi

    void retranslateUi(QWidget *FormStudents)
    {
        FormStudents->setWindowTitle(QApplication::translate("FormStudents", "Form", 0));
        label->setText(QApplication::translate("FormStudents", "\320\241\321\202\321\203\320\264\320\265\320\275\321\202\321\213", 0));
        pushButton_2->setText(QApplication::translate("FormStudents", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", 0));
        pushButton->setText(QApplication::translate("FormStudents", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", 0));
        pushButton_3->setText(QApplication::translate("FormStudents", "\320\237\320\276\320\264\321\202\320\262\320\265\321\200\320\264\320\270\321\202\321\214", 0));
    } // retranslateUi

};

namespace Ui {
    class FormStudents: public Ui_FormStudents {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMSTUDENTS_H
