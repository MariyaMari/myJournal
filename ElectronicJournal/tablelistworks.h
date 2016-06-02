#ifndef TABLELISTWORKS_H
#define TABLELISTWORKS_H

#include <QWidget>
#include <QtSql>
#include "settings.h"

namespace Ui {
class TableListWorks;
}

class TableListWorks : public QWidget
{
    Q_OBJECT

public:
    explicit TableListWorks(const SettingsPtr & settings, QWidget *parent = 0);
    ~TableListWorks();

    QSqlDatabase db;
    QSqlTableModel *model;

    void Init(QSqlTableModel *mod);

private:
    Ui::TableListWorks *ui;

    SettingsPtr m_settings;
};

#endif // TABLELISTWORKS_H
