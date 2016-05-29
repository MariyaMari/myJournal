#ifndef TOLISTWORKS_H
#define TOLISTWORKS_H

#include <QWidget>
#include <QtSql>
#include <tablelistworks.h>

namespace Ui {
class ToListWorks;
}

class ToListWorks : public QWidget
{
    Q_OBJECT

public:
    explicit ToListWorks(QWidget *parent = 0);
    ~ToListWorks();

    QSqlDatabase db;
    QSqlTableModel *model;
    QSqlQueryModel *modSemes, *modSpec, *modDis, *modVidWor;

    void Init(QSqlQueryModel *mod1, QSqlQueryModel *mod2, QSqlQueryModel *mod3, QSqlQueryModel *mod4);

private slots:
    void on_pushButton_clicked();

private:
    Ui::ToListWorks *ui;

    TableListWorks *listWorks;
};

#endif // TOLISTWORKS_H
