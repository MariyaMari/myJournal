#ifndef MAINFORM_H
#define MAINFORM_H

#include <QMainWindow>
#include <QtSql>
#include <spravochniki.h>
#include <worktables.h>

namespace Ui {
class MainForm;
}

class MainForm : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainForm(QWidget *parent = 0);
    ~MainForm();

    QSqlDatabase db;

    void ConnectToDataBase();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainForm *ui;

    Spravochniki *spisokSpravochniki;
    WorkTables *spisokWorkTables;

};

#endif // MAINFORM_H
