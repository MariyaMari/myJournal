#ifndef FORMTYPEWORKS_H
#define FORMTYPEWORKS_H

#include <QWidget>
#include <QtSql>
#include "settings.h"

namespace Ui {
class FormTypeWorks;
}

class FormTypeWorks : public QWidget
{
    Q_OBJECT

public:
    explicit FormTypeWorks(const SettingsPtr & settings, QWidget *parent = 0);
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

    SettingsPtr m_settings;
};

#endif // FORMTYPEWORKS_H
