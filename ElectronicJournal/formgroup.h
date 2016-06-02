#ifndef FORMGROUP_H
#define FORMGROUP_H

#include <QWidget>
#include <QtSql>
#include "settings.h"

namespace Ui {
class FormGroup;
}

class FormGroup : public QWidget
{
    Q_OBJECT

public:
    explicit FormGroup(const SettingsPtr & settings, QWidget *parent = 0);
    ~FormGroup();

    QSqlDatabase db;
    QSqlTableModel *model;

    void Init(QSqlTableModel *mod);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::FormGroup *ui;

    SettingsPtr m_settings;
};

#endif // FORMGROUP_H
