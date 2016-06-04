#ifndef WORKTABLES_H
#define WORKTABLES_H

#include <QWidget>
#include <QtSql>
#include <toplan.h>
#include <tocompositiongroup.h>
#include <tovisit.h>
#include <tolistworks.h>
#include <tomadeworks.h>
#include "settings.h"

namespace Ui {
class WorkTables;
}

class WorkTables : public QWidget
{
    Q_OBJECT

public:
    explicit WorkTables(const SettingsPtr & settings, QWidget *parent = 0);
    ~WorkTables();

    QSqlDatabase db;
    QSqlTableModel *model;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::WorkTables *ui;

    ToPlan *toPlan;
    ToCompositionGroup *toCompGroup;
    ToVisit *toVisit;
    ToListWorks *tolistWorks;
    ToMadeWorks *toMadeWorks;

    SettingsPtr m_settings;

signals:
    void    newWindow( QWidget * widget );

};

#endif // WORKTABLES_H
