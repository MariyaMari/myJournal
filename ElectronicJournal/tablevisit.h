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

    QSqlRelationalTableModel model;
    QSortFilterProxyModel viewModel1, viewModel2, viewModel3;

    void Init();
    void update();
    void setFilter(const QString & n_trab, const QString & n_dis, const QString & data);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::TableVisit *ui;

    SettingsPtr m_settings;
};

#endif // TABLEVISIT_H
