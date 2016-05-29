#ifndef FORMTYPEWORKS_H
#define FORMTYPEWORKS_H

#include <QWidget>
#include <QtSql>

namespace Ui {
class FormTypeWorks;
}

class FormTypeWorks : public QWidget
{
    Q_OBJECT

public:
    explicit FormTypeWorks(QWidget *parent = 0);
    ~FormTypeWorks();

    QSqlDatabase db;
    QSqlTableModel *model;

    void Init(QSqlTableModel *mod);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::FormTypeWorks *ui;
};

#endif // FORMTYPEWORKS_H
