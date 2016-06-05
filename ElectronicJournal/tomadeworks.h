#ifndef TOMADEWORKS_H
#define TOMADEWORKS_H

#include <QWidget>
#include <QtSql>
#include <tablemadeworks.h>
#include "settings.h"

namespace Ui {
class ToMadeWorks;
}

class ToMadeWorks : public QWidget
{
    Q_OBJECT

public:
    explicit ToMadeWorks(const SettingsPtr & settings, QWidget *parent = 0);
    ~ToMadeWorks();

    QSqlDatabase db;
    QSqlQueryModel *modData, *modGr, *modDis, *modVidWor;

    void Init(QSqlQueryModel *mod1, QSqlQueryModel *mod2, QSqlQueryModel *mod3, QSqlQueryModel *mod4);

private slots:
    void on_pushButton_clicked();

private:
    Ui::ToMadeWorks *ui;

    TableMadeWorks *madeWorks;

    SettingsPtr m_settings;

signals:
    void    newWindow( QWidget * widget );

};

#endif // TOMADEWORKS_H
