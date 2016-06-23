#ifndef FORMDISCIPLINE_H
#define FORMDISCIPLINE_H

#include <QWidget>
#include <QtSql>
#include "settings.h"

namespace Ui {
class FormDiscipline;
}

class FormDiscipline : public QWidget
{
    Q_OBJECT

public:
    explicit FormDiscipline(const SettingsPtr & settings, QWidget *parent = 0);
    ~FormDiscipline();

    QSqlDatabase db;
    QSqlTableModel *model;

    void Init();
    void Update();

protected:
    void closeEvent(QCloseEvent *e);

signals:
    void Closed();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

//    void on_pushButton_3_clicked();

private:
    Ui::FormDiscipline *ui;

    SettingsPtr m_settings;
};

#endif // FORMDISCIPLINE_H
