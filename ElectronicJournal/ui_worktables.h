/********************************************************************************
** Form generated from reading UI file 'worktables.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WORKTABLES_H
#define UI_WORKTABLES_H

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

class Ui_WorkTables
{
public:
    QLabel *label;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;

    void setupUi(QWidget *WorkTables)
    {
        if (WorkTables->objectName().isEmpty())
            WorkTables->setObjectName(QStringLiteral("WorkTables"));
        WorkTables->resize(386, 491);
        label = new QLabel(WorkTables);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(120, 60, 151, 31));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        verticalLayoutWidget = new QWidget(WorkTables);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(89, 120, 211, 301));
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


        retranslateUi(WorkTables);

        QMetaObject::connectSlotsByName(WorkTables);
    } // setupUi

    void retranslateUi(QWidget *WorkTables)
    {
        WorkTables->setWindowTitle(QApplication::translate("WorkTables", "Form", 0));
        label->setText(QApplication::translate("WorkTables", "\320\240\320\260\320\261\320\276\321\207\320\270\320\265 \321\202\320\260\320\261\320\273\320\270\321\206\321\213", 0));
        pushButton->setText(QApplication::translate("WorkTables", "\320\237\320\273\320\260\320\275", 0));
        pushButton_2->setText(QApplication::translate("WorkTables", "\320\241\320\276\321\201\321\202\320\260\320\262 \320\263\321\200\321\203\320\277\320\277", 0));
        pushButton_3->setText(QApplication::translate("WorkTables", "\320\237\320\276\321\201\320\265\321\211\320\260\320\265\320\274\320\276\321\201\321\202\321\214", 0));
        pushButton_4->setText(QApplication::translate("WorkTables", "\320\241\320\277\320\270\321\201\320\276\320\272 \321\200\320\260\320\261\320\276\321\202", 0));
        pushButton_5->setText(QApplication::translate("WorkTables", "\320\241\320\264\320\260\320\275\320\275\321\213\320\265 \321\200\320\260\320\261\320\276\321\202\321\213", 0));
    } // retranslateUi

};

namespace Ui {
    class WorkTables: public Ui_WorkTables {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORKTABLES_H
