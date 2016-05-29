#ifndef TABLELISTWORKS_H
#define TABLELISTWORKS_H

#include <QWidget>
#include <QtSql>

namespace Ui {
class TableListWorks;
}

class TableListWorks : public QWidget
{
    Q_OBJECT

public:
    explicit TableListWorks(QWidget *parent = 0);
    ~TableListWorks();

    QSqlDatabase db;
    QSqlTableModel *model;

    void Init(QSqlTableModel *mod);

private:
    Ui::TableListWorks *ui;
};

#endif // TABLELISTWORKS_H
