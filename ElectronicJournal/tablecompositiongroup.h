#ifndef TABLECOMPOSITIONGROUP_H
#define TABLECOMPOSITIONGROUP_H

#include <QWidget>
#include <QtSql>
#include "addcompgroup.h"
#include "settings.h"

namespace Ui {
class TableCompositionGroup;
}

class TableCompositionGroup : public QWidget
{
    Q_OBJECT

public:
    explicit TableCompositionGroup(const SettingsPtr & settings, QWidget *parent = 0);
    ~TableCompositionGroup();

    QSqlRelationalTableModel model;
    QSortFilterProxyModel viewModel1, viewModel2;

    void Init();
    void update();
    void setFilter(const QString & semes, const QString & n_gr);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void QueryInserted(QString query);

    void closeAddCompGr();

private:
    Ui::TableCompositionGroup *ui;

    AddCompGroup *addCompGr;
    QString idGr, Semes;
    SettingsPtr m_settings;

signals:
    void newWindow( QWidget * widget );
};

#endif // TABLECOMPOSITIONGROUP_H
