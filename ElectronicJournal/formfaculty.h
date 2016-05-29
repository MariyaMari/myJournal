#ifndef FORMFACULTY_H
#define FORMFACULTY_H

#include <QWidget>
#include <QtSql>

namespace Ui {
class FormFaculty;
}

class FormFaculty : public QWidget
{
    Q_OBJECT

public:
    explicit FormFaculty(QWidget *parent = 0);
    ~FormFaculty();

    QSqlDatabase db;
    QSqlTableModel *model;

    void Init(QSqlTableModel *mod);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::FormFaculty *ui;
};

#endif // FORMFACULTY_H
