#ifndef ADDCOMPGROUP_H
#define ADDCOMPGROUP_H

#include <QWidget>
#include <QtSql>
#include "settings.h"

namespace Ui {
class AddCompGroup;
}

class AddCompGroup : public QWidget
{
    Q_OBJECT

public:
    explicit AddCompGroup(const SettingsPtr & settings, QWidget *parent = 0);
    ~AddCompGroup();

    QSqlDatabase *db;

    void Init(QSqlQueryModel *mod1, const QString &Semes, const QString &Gr);

signals:
    void InsertQuery(QString query);
    void    closeThisWidget();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AddCompGroup *ui;

    QString idGr, semes;
    SettingsPtr m_settings;
};

#endif // ADDCOMPGROUP_H
