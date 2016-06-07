#ifndef TABLEMADEWORKS_H
#define TABLEMADEWORKS_H

#include <QWidget>
#include <QtSql>
#include "settings.h"

namespace Ui {
class TableMadeWorks;
}

class TableMadeWorks : public QWidget
{
    Q_OBJECT

public:
    explicit TableMadeWorks(const SettingsPtr & settings, QWidget *parent = 0);
    ~TableMadeWorks();

    QSqlRelationalTableModel model;
    QSortFilterProxyModel viewModel1, viewModel2;

    void Init();
    void update();
    void setFilter(const QString & n_gr, const QString & n_dis, const QString &n_trab);

private:
    Ui::TableMadeWorks *ui;

    SettingsPtr m_settings;
};

#endif // TABLEMADEWORKS_H
