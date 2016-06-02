#ifndef FORMSPECIALTY_H
#define FORMSPECIALTY_H

#include <QWidget>
#include <QtSql>
#include "settings.h"

namespace Ui {
class FormSpecialty;
}

class FormSpecialty : public QWidget
{
    Q_OBJECT

public:
    explicit FormSpecialty(const SettingsPtr & settings, QWidget *parent = 0);
    ~FormSpecialty();

    QSqlDatabase db;
    QSqlTableModel *model;

    void Init(QSqlTableModel *mod);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::FormSpecialty *ui;

    SettingsPtr m_settings;
};

#endif // FORMSPECIALTY_H
