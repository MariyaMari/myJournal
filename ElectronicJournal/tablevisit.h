#ifndef TABLEVISIT_H
#define TABLEVISIT_H

#include <QWidget>
#include <QtSql>
#include "settings.h"

namespace Ui {
class TableVisit;
}

class TableVisit : public QWidget
{
    Q_OBJECT

public:
    explicit TableVisit(const SettingsPtr & settings, QWidget *parent = 0);
    ~TableVisit();

    QSqlDatabase db;
    QSqlTableModel *model;

    void Init(QSqlTableModel *mod);

private:
    Ui::TableVisit *ui;

    SettingsPtr m_settings;
};

#endif // TABLEVISIT_H
