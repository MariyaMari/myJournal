#ifndef ADDGROUP_H
#define ADDGROUP_H

#include <QWidget>
#include <QtSql>
#include "settings.h"

namespace Ui {
class AddGroup;
}

class AddGroup : public QWidget
{
    Q_OBJECT

public:
    explicit AddGroup(const SettingsPtr & settings, QWidget *parent = 0);
    ~AddGroup();

    QSqlDatabase *db;

    void Init(QSqlQueryModel *mod1, QSqlDatabase &db);

signals:
    void InsertQuery(QString query);
    void closeThisWidget();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AddGroup *ui;

    SettingsPtr m_settings;
};

#endif // ADDGROUP_H
