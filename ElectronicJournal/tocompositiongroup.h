#ifndef TOCOMPOSITIONGROUP_H
#define TOCOMPOSITIONGROUP_H

#include <QWidget>
#include <QtSql>
#include <tablecompositiongroup.h>
#include "settings.h"

namespace Ui {
class ToCompositionGroup;
}

class ToCompositionGroup : public QWidget
{
    Q_OBJECT

public:
    explicit ToCompositionGroup(const SettingsPtr & settings, QWidget *parent = 0);
    ~ToCompositionGroup();

    QSqlDatabase db;
    QSqlQueryModel *modSemes, *modGrup;

    void Init(QSqlQueryModel *mod1, QSqlQueryModel *mod2);

private slots:
    void on_pushButton_clicked();

private:
    Ui::ToCompositionGroup *ui;

    TableCompositionGroup *compGrup;

    SettingsPtr m_settings;

signals:
    void    newWindow( QWidget * widget );

};

#endif // TOCOMPOSITIONGROUP_H
