#ifndef FORMSTUDENTS_H
#define FORMSTUDENTS_H

#include <QWidget>
#include <QtSql>

namespace Ui {
class FormStudents;
}

class FormStudents : public QWidget
{
    Q_OBJECT

public:
    explicit FormStudents(QWidget *parent = 0);
    ~FormStudents();

    QSqlDatabase db;
    QSqlTableModel *model;

    void Init(QSqlTableModel *mod);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::FormStudents *ui;
};

#endif // FORMSTUDENTS_H
