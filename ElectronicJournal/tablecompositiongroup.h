#ifndef TABLECOMPOSITIONGROUP_H
#define TABLECOMPOSITIONGROUP_H

#include <QWidget>
#include <QtSql>
#include "settings.h"

namespace Ui {
class TableCompositionGroup;
}

class TableCompositionGroup : public QWidget
{
    Q_OBJECT

public:
    explicit TableCompositionGroup(const SettingsPtr & settings, QWidget *parent = 0);
    ~TableCompositionGroup();

    QSqlDatabase db;
    QSqlRelationalTableModel *model;

    void Init();
    void Update();
    void setNGr(const QString & text, const QString &text1);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::TableCompositionGroup *ui;

    SettingsPtr m_settings;
};

#endif // TABLECOMPOSITIONGROUP_H
