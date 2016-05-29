/********************************************************************************
** Form generated from reading UI file 'formdiscipline.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMDISCIPLINE_H
#define UI_FORMDISCIPLINE_H

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

class Ui_FormDiscipline
{
public:
    QLabel *label;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QTableView *tableView;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QWidget *FormDiscipline)
    {
        if (FormDiscipline->objectName().isEmpty())
            FormDiscipline->setObjectName(QStringLiteral("FormDiscipline"));
        FormDiscipline->resize(386, 491);
        label = new QLabel(FormDiscipline);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(150, 30, 111, 21));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        verticalLayoutWidget = new QWidget(FormDiscipline);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 60, 361, 371));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tableView = new QTableView(verticalLayoutWidget);
        tableView->setObjectName(QStringLiteral("tableView"));

        verticalLayout->addWidget(tableView);

        gridLayoutWidget = new QWidget(FormDiscipline);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 439, 361, 41));
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


        retranslateUi(FormDiscipline);

        QMetaObject::connectSlotsByName(FormDiscipline);
    } // setupUi

    void retranslateUi(QWidget *FormDiscipline)
    {
        FormDiscipline->setWindowTitle(QApplication::translate("FormDiscipline", "Form", 0));
        label->setText(QApplication::translate("FormDiscipline", "\320\224\320\270\321\201\321\206\320\270\320\277\320\273\320\270\320\275\320\260", 0));
        pushButton->setText(QApplication::translate("FormDiscipline", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", 0));
        pushButton_2->setText(QApplication::translate("FormDiscipline", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", 0));
        pushButton_3->setText(QApplication::translate("FormDiscipline", "\320\237\320\276\320\264\321\202\320\262\320\265\321\200\320\264\320\270\321\202\321\214", 0));
    } // retranslateUi

};

namespace Ui {
    class FormDiscipline: public Ui_FormDiscipline {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMDISCIPLINE_H
