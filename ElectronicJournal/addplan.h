#ifndef ADDPLAN_H
#define ADDPLAN_H

#include <QWidget>
#include <QtSql>
#include "settings.h"

namespace Ui {
class AddPlan;
}

class AddPlan : public QWidget
{
    Q_OBJECT

public:
    explicit AddPlan(const SettingsPtr & settings, QWidget *parent = 0);
    ~AddPlan();

    QSqlDatabase *db;

    void Init(QSqlQueryModel *mod1, const QString &Semes, const QString &Spec);

signals:
    void InsertQuery(QString query);
    void    closeThisWidget();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AddPlan *ui;

    QString idSpec, semes;
    SettingsPtr m_settings;
};

#endif // ADDPLAN_H

