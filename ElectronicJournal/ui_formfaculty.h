/********************************************************************************
** Form generated from reading UI file 'formfaculty.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMFACULTY_H
#define UI_FORMFACULTY_H

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

class Ui_FormFaculty
{
public:
    QLabel *label;
    QTableView *tableView;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QWidget *FormFaculty)
    {
        if (FormFaculty->objectName().isEmpty())
            FormFaculty->setObjectName(QStringLiteral("FormFaculty"));
        FormFaculty->resize(386, 491);
        label = new QLabel(FormFaculty);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(160, 20, 91, 31));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        tableView = new QTableView(FormFaculty);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(10, 50, 361, 361));
        gridLayoutWidget = new QWidget(FormFaculty);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 419, 361, 51));
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


        retranslateUi(FormFaculty);

        QMetaObject::connectSlotsByName(FormFaculty);
    } // setupUi

    void retranslateUi(QWidget *FormFaculty)
    {
        FormFaculty->setWindowTitle(QApplication::translate("FormFaculty", "Form", 0));
        label->setText(QApplication::translate("FormFaculty", "\320\244\320\260\320\272\321\203\320\273\321\214\321\202\320\265\321\202", 0));
        pushButton->setText(QApplication::translate("FormFaculty", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", 0));
        pushButton_2->setText(QApplication::translate("FormFaculty", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", 0));
        pushButton_3->setText(QApplication::translate("FormFaculty", "\320\237\320\276\320\264\321\202\320\262\320\265\321\200\320\264\320\270\321\202\321\214", 0));
    } // retranslateUi

};

namespace Ui {
    class FormFaculty: public Ui_FormFaculty {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMFACULTY_H
