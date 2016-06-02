#ifndef TOPLAN_H
#define TOPLAN_H

#include <QWidget>
#include <QtSql>
#include <tableplan.h>
#include "settings.h"

namespace Ui {
class ToPlan;
}

class ToPlan : public QWidget
{
    Q_OBJECT

public:
    explicit ToPlan(const SettingsPtr & settings, QWidget *parent = 0);
    ~ToPlan();

    QSqlDatabase db;
    QSqlQueryModel *modSemes, *modSpec;

    void Init(QSqlQueryModel *mod1, QSqlQueryModel *mod2);


private slots:
    void on_pushButton_clicked();

private:
    Ui::ToPlan *ui;

    TablePlan *plan;

    SettingsPtr m_settings;
};

#endif // TOPLAN_H
