#ifndef TABLECOMPOSITIONGROUP_H
#define TABLECOMPOSITIONGROUP_H

#include <QWidget>
#include <QtSql>
#include "settings.h"

namespace Ui {
class TableCompositionGroup;
}

class TableCompositionGroup : public QWidget
{
    Q_OBJECT

public:
    explicit TableCompositionGroup(const SettingsPtr & settings, QWidget *parent = 0);
    ~TableCompositionGroup();

    QSqlRelationalTableModel model;
    QSortFilterProxyModel viewModel1, viewModel2;

    void Init();
    void update();
    void setFilter(const QString & semes, const QString & n_gr);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::TableCompositionGroup *ui;

    SettingsPtr m_settings;
};

#endif // TABLECOMPOSITIONGROUP_H
