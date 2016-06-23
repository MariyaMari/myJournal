#ifndef ADDLISTWORKS_H
#define ADDLISTWORKS_H

#include <QWidget>
#include <QtSql>
#include "settings.h"

namespace Ui {
class AddListWorks;
}

class AddListWorks : public QWidget
{
    Q_OBJECT

public:
    explicit AddListWorks(const SettingsPtr & settings, QWidget *parent = 0);
    ~AddListWorks();

    QSqlDatabase *db;

    void Init(const QString &Semes, const QString &Spec, const QString &Dis, const QString &Trab, QSqlDatabase &db);

signals:
    void InsertQuery(QString query);
    void closeThisWidget();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AddListWorks *ui;

    QString idSpec, idDis, idTrab, semes;
    SettingsPtr m_settings;
};

#endif // ADDLISTWORKS_H
