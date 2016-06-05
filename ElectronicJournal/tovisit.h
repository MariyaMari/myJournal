#ifndef TOVISIT_H
#define TOVISIT_H

#include <QWidget>
#include <QWidget>
#include <QtSql>
#include <tablevisit.h>
#include "settings.h"

namespace Ui {
class ToVisit;
}

class ToVisit : public QWidget
{
    Q_OBJECT

public:
    explicit ToVisit(const SettingsPtr & settings, QWidget *parent = 0);
    ~ToVisit();

    QSqlDatabase db;
    QSqlQueryModel *modData, *modDis, *modVidWor;

    void Init(QSqlQueryModel *mod1, QSqlQueryModel *mod2, QSqlQueryModel *mod3);

private slots:
    void on_pushButton_clicked();

private:
    Ui::ToVisit *ui;

    TableVisit *visit;

    SettingsPtr m_settings;

signals:
    void    newWindow( QWidget * widget );

};

#endif // TOVISIT_H
