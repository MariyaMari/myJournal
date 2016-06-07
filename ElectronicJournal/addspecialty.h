#ifndef ADDSPECIALTY_H
#define ADDSPECIALTY_H

#include <QWidget>
#include <QtSql>
#include "settings.h"

namespace Ui {
class AddSpecialty;
}

class AddSpecialty : public QWidget
{
    Q_OBJECT

public:
    explicit AddSpecialty(const SettingsPtr & settings, QWidget *parent = 0);
    ~AddSpecialty();

    QSqlDatabase *db;
    QSqlQueryModel *modFac;

    void Init(QSqlQueryModel *mod1, QSqlDatabase &db);

signals:
    void InsertQuery(QString query);
    void    closeThisWidget();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AddSpecialty *ui;

    SettingsPtr m_settings;
};

#endif // ADDSPECIALTY_H
