#ifndef TABLEVISIT_H
#define TABLEVISIT_H

#include <QWidget>
#include <QtSql>
#include "settings.h"

namespace Ui {
class TableVisit;
}

class TableVisit : public QWidget
{
    Q_OBJECT

public:
    explicit TableVisit(const SettingsPtr & settings, QWidget *parent = 0);
    ~TableVisit();

    QSqlDatabase db;
    QSqlRelationalTableModel *model;

    void Init();
    void Update();
    void setNGr(const QString & text, const QString &text1, const QString &text2);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::TableVisit *ui;

    SettingsPtr m_settings;
};

#endif // TABLEVISIT_H
