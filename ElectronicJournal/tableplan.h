#ifndef TABLEPLAN_H
#define TABLEPLAN_H

#include <QWidget>
#include <QtSql>

namespace Ui {
class TablePlan;
}

class TablePlan : public QWidget
{
    Q_OBJECT

public:
    explicit TablePlan(QWidget *parent = 0);
    ~TablePlan();

    QSqlDatabase db;
    QSqlTableModel *model;

    void Init(QSqlTableModel *mod);

private:
    Ui::TablePlan *ui;
};

#endif // TABLEPLAN_H
