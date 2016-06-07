#include "tablevisit.h"
#include "ui_tablevisit.h"

#include <QMessageBox>

TableVisit::TableVisit(const SettingsPtr &settings, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TableVisit),
    m_settings(settings)
{
    ui->setupUi(this);

    model.setEditStrategy(QSqlRelationalTableModel::OnManualSubmit);
    model.setTable("link3");
    model.setRelation(0, QSqlRelation("students", "id_st", "fio"));
    update();
    Init();
}

TableVisit::~TableVisit()
{
    delete ui;
}

void TableVisit::update()
{
    model.select();
}

void TableVisit::setFilter(const QString & n_trab, const QString & n_dis, const QString &data)
{
    QSqlQuery query( "SELECT id_trab FROM typerabot WHERE n_trab='" + n_trab + "'" );
    QString id_trab;
    while(query.next())
    {
        id_trab = query.value(0).toString();
    }
    viewModel1.setFilterKeyColumn(2);
    viewModel1.setFilterFixedString(id_trab);

    QSqlQuery query1( "SELECT id_dis FROM disciplina WHERE n_dis='" + n_dis + "'" );
    QString id_dis;
    while(query1.next())
    {
        id_dis = query1.value(0).toString();
    }
    viewModel2.setFilterKeyColumn(4);
    viewModel2.setFilterFixedString(id_dis);

    viewModel3.setFilterKeyColumn(1);
    viewModel3.setFilterFixedString(data);
}

void TableVisit::Init()
{
    viewModel1.setSourceModel(&model);
    viewModel2.setSourceModel(&viewModel1);
    viewModel3.setSourceModel(&viewModel2);
    ui->tableView->setModel(&viewModel3);
//    ui->tableView->setColumnHidden(1, true);
    ui->tableView->setColumnHidden(2, true);
    ui->tableView->setColumnHidden(4, true);
    ui->tableView->show();
    model.setHeaderData(0, Qt::Horizontal, "ФИО Студента");
    model.setHeaderData(3, Qt::Horizontal, "Пропуск");

    QHeaderView *pHW = ui->tableView->horizontalHeader(); //Нормальный размер колонок
    int count = pHW->count();
    for (int i = 0; i < count; i++)
        pHW->setSectionResizeMode(i,QHeaderView::ResizeToContents);

}

void TableVisit::on_pushButton_clicked() //Удалить
{
    model.removeRow(ui->tableView->currentIndex().row());
}

void TableVisit::on_pushButton_2_clicked() //Добавить
{

}

void TableVisit::on_pushButton_3_clicked() //Подтвердить
{
    if(!model.submitAll())
        QMessageBox::warning(this, "Error", model.lastError().text());
    update();
}
