#ifndef TABLEMADEWORKS_H
#define TABLEMADEWORKS_H

#include <QWidget>
#include <QtSql>

namespace Ui {
class TableMadeWorks;
}

class TableMadeWorks : public QWidget
{
    Q_OBJECT

public:
    explicit TableMadeWorks(QWidget *parent = 0);
    ~TableMadeWorks();

    QSqlDatabase db;
    QSqlTableModel *model;

    void Init(QSqlTableModel *mod);

private:
    Ui::TableMadeWorks *ui;
};

#endif // TABLEMADEWORKS_H
