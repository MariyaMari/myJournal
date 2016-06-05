#ifndef FORMSPECIALTY_H
#define FORMSPECIALTY_H

#include <QWidget>
#include <QtSql>
#include "addspecialty.h"
#include "settings.h"

namespace Ui {
class FormSpecialty;
}

class FormSpecialty : public QWidget
{
    Q_OBJECT

public:
    explicit FormSpecialty(const SettingsPtr & settings, QWidget *parent = 0);
    ~FormSpecialty();

    QSqlDatabase db;
    QSqlRelationalTableModel *model;

    void Init(QSqlRelationalTableModel *mod);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void QueryInserted(QString query);

private:
    Ui::FormSpecialty *ui;

    AddSpecialty *addSpec;
    SettingsPtr m_settings;

signals:
    void    newWindow( QWidget * widget );
};

#endif // FORMSPECIALTY_H
