#ifndef TABLECOMPOSITIONGROUP_H
#define TABLECOMPOSITIONGROUP_H

#include <QWidget>
#include <QtSql>

namespace Ui {
class TableCompositionGroup;
}

class TableCompositionGroup : public QWidget
{
    Q_OBJECT

public:
    explicit TableCompositionGroup(QWidget *parent = 0);
    ~TableCompositionGroup();

    QSqlDatabase db;
    QSqlTableModel *model;

    void Init(QSqlTableModel *mod);

private:
    Ui::TableCompositionGroup *ui;
};

#endif // TABLECOMPOSITIONGROUP_H
