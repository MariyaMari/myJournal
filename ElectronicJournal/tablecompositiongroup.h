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

    QSqlDatabase db;
    QSqlTableModel *model;

    void Init(QSqlTableModel *mod);

private:
    Ui::TableCompositionGroup *ui;

    SettingsPtr m_settings;
};

#endif // TABLECOMPOSITIONGROUP_H
