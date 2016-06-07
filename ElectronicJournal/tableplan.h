#ifndef TABLEPLAN_H
#define TABLEPLAN_H

#include <QWidget>
#include <QtSql>
#include "settings.h"

namespace Ui {
class TablePlan;
}

class TablePlan : public QWidget
{
    Q_OBJECT

public:
    explicit TablePlan(const SettingsPtr & settings, QWidget *parent = 0);
    ~TablePlan();

    QSqlRelationalTableModel model;
    QSortFilterProxyModel viewModel1, viewModel2;

    void Init();
    void update();
    void setFilter(const QString & n_spec, const QString & semes);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::TablePlan *ui;

    SettingsPtr m_settings;

};

#endif // TABLEPLAN_H
