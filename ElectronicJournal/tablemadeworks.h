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

    QSqlDatabase db;
    QSqlRelationalTableModel *model;

    void Init();
    void Update();
    void setNGr(const QString & text, const QString &text1);

private:
    Ui::TableMadeWorks *ui;

    SettingsPtr m_settings;
};

#endif // TABLEMADEWORKS_H
