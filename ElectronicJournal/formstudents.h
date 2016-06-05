#ifndef FORMSTUDENTS_H
#define FORMSTUDENTS_H

#include <QWidget>
#include <QtSql>
#include "settings.h"

namespace Ui {
class FormStudents;
}

class FormStudents : public QWidget
{
    Q_OBJECT

public:
    explicit FormStudents(const SettingsPtr & settings, QWidget *parent = 0);
    ~FormStudents();

    QSqlDatabase db;
    QSqlTableModel *model;

    void Init();
    void Update();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::FormStudents *ui;

    SettingsPtr m_settings;
};

#endif // FORMSTUDENTS_H
