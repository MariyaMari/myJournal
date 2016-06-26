#ifndef TABLEMADEWORKS_H
#define TABLEMADEWORKS_H

#include <QWidget>
#include <QtSql>
#include "settings.h"
#include "madeworkmodel.hpp"

namespace Ui {
class TableMadeWorks;
}

class TableMadeWorks : public QWidget
{
    Q_OBJECT

public:
    explicit TableMadeWorks(const SettingsPtr & settings, QWidget *parent = 0);
    ~TableMadeWorks();

    MadeWorkModel model;
    QSortFilterProxyModel viewModel1, viewModel2, viewModel3, viewModel4;

    void Init();
    void update();
    void setFilter(const QString & n_gr, const QString & n_dis, const QString &n_trab, const QString &data);

private:
    Ui::TableMadeWorks *ui;

    SettingsPtr m_settings;
};

#endif // TABLEMADEWORKS_H
