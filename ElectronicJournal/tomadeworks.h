#ifndef TOMADEWORKS_H
#define TOMADEWORKS_H

#include <QWidget>
#include <QtSql>
#include <tablemadeworks.h>

namespace Ui {
class ToMadeWorks;
}

class ToMadeWorks : public QWidget
{
    Q_OBJECT

public:
    explicit ToMadeWorks(QWidget *parent = 0);
    ~ToMadeWorks();

    QSqlDatabase db;
    QSqlTableModel *model;
    QSqlQueryModel *modData, *modGr, *modDis, *modVidWor;

    void Init(QSqlQueryModel *mod1, QSqlQueryModel *mod2, QSqlQueryModel *mod3, QSqlQueryModel *mod4);

private slots:
    void on_pushButton_clicked();

private:
    Ui::ToMadeWorks *ui;

    TableMadeWorks *madeWorks;
};

#endif // TOMADEWORKS_H
