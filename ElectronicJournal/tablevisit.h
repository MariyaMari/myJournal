#ifndef TABLEVISIT_H
#define TABLEVISIT_H

#include <QWidget>
#include <QtSql>

namespace Ui {
class TableVisit;
}

class TableVisit : public QWidget
{
    Q_OBJECT

public:
    explicit TableVisit(QWidget *parent = 0);
    ~TableVisit();

    QSqlDatabase db;
    QSqlTableModel *model;

    void Init(QSqlTableModel *mod);

private:
    Ui::TableVisit *ui;
};

#endif // TABLEVISIT_H
