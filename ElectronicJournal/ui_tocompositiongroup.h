/********************************************************************************
** Form generated from reading UI file 'tocompositiongroup.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOCOMPOSITIONGROUP_H
#define UI_TOCOMPOSITIONGROUP_H

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

class Ui_ToCompositionGroup
{
public:
    QLabel *label;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_4;
    QComboBox *comboBox;
    QLabel *label_5;
    QComboBox *comboBox_2;
    QPushButton *pushButton;

    void setupUi(QWidget *ToCompositionGroup)
    {
        if (ToCompositionGroup->objectName().isEmpty())
            ToCompositionGroup->setObjectName(QStringLiteral("ToCompositionGroup"));
        ToCompositionGroup->resize(386, 491);
        label = new QLabel(ToCompositionGroup);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(150, 50, 91, 21));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        verticalLayoutWidget = new QWidget(ToCompositionGroup);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(50, 110, 281, 251));
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

        pushButton = new QPushButton(ToCompositionGroup);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(50, 386, 279, 51));

        retranslateUi(ToCompositionGroup);

        QMetaObject::connectSlotsByName(ToCompositionGroup);
    } // setupUi

    void retranslateUi(QWidget *ToCompositionGroup)
    {
        ToCompositionGroup->setWindowTitle(QApplication::translate("ToCompositionGroup", "Form", 0));
        label->setText(QApplication::translate("ToCompositionGroup", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265: ", 0));
        label_4->setText(QApplication::translate("ToCompositionGroup", "\320\241\320\265\320\274\320\265\321\201\321\202\321\200:", 0));
        label_5->setText(QApplication::translate("ToCompositionGroup", "\320\223\321\200\321\203\320\277\320\277\320\260:", 0));
        pushButton->setText(QApplication::translate("ToCompositionGroup", "\320\241\320\276\321\201\321\202\320\260\320\262 \320\263\321\200\321\203\320\277\320\277\321\213", 0));
    } // retranslateUi

};

namespace Ui {
    class ToCompositionGroup: public Ui_ToCompositionGroup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOCOMPOSITIONGROUP_H
