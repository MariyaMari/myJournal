#include "tablecompositiongroup.h"
#include "ui_tablecompositiongroup.h"

#include <QMessageBox>

TableCompositionGroup::TableCompositionGroup(const SettingsPtr &settings, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TableCompositionGroup),
    m_settings(settings)
{
    ui->setupUi(this);

    model.setEditStrategy(QSqlRelationalTableModel::OnManualSubmit);
    model.setTable("sostavgr");
    model.setRelation(2, QSqlRelation("students", "id_st", "fio"));
    update();
    Init();
}

TableCompositionGroup::~TableCompositionGroup()
{
    delete ui;
}

void TableCompositionGroup::update()
{
    model.select();
}

void TableCompositionGroup::setFilter(const QString & semes, const QString & n_gr)
{
    viewModel1.setFilterKeyColumn(0);
    viewModel1.setFilterFixedString(semes);

    QSqlQuery query( "SELECT id_gr FROM gruppa WHERE n_gr='" + n_gr + "'" );
    QString id_gr;
    while(query.next())
    {
        id_gr = query.value(0).toString();
    }
    viewModel2.setFilterKeyColumn(1);
    viewModel2.setFilterFixedString(id_gr);

//    model->setFilter("id_gr=(SELECT gruppa.id_gr FROM gruppa WHERE gruppa.n_gr='"
//                    + text + "') "
//                    "AND semes=" + text1 + ";");

}

void TableCompositionGroup::Init()
{
    viewModel1.setSourceModel(&model);
    viewModel2.setSourceModel(&viewModel1);
    ui->tableView->setModel(&viewModel2);
    ui->tableView->setColumnHidden(0, true);
    ui->tableView->setColumnHidden(1, true);
    ui->tableView->show();
    model.setHeaderData(2, Qt::Horizontal, "ФИО Студента");

    QHeaderView *pHW = ui->tableView->horizontalHeader(); //Нормальный размер колонок
    int count = pHW->count();
    for (int i = 0; i < count; i++)
        pHW->setSectionResizeMode(i,QHeaderView::ResizeToContents);
}

void TableCompositionGroup::on_pushButton_clicked() //Удалить
{
    model.removeRow(ui->tableView->currentIndex().row());
}

void TableCompositionGroup::on_pushButton_2_clicked() //Добавить
{

}

void TableCompositionGroup::on_pushButton_3_clicked() //Подтвердить
{
    if(!model.submitAll())
        QMessageBox::warning(this, "Error", model.lastError().text());
    update();
}
