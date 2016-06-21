#include "tablevisit.h"
#include "ui_tablevisit.h"

#include <QMessageBox>
#include <QDebug>

TableVisit::TableVisit(const SettingsPtr &settings, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TableVisit),
    m_settings(settings)
{
    ui->setupUi(this);

    numberPropusk = "0";

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

void TableVisit::setFilter(const QString & n_trab, const QString & n_dis, const QString &data, const QString & n_gr)
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

    this->data = data;
    idDis = id_dis;
    idTrab = id_trab;

}

void TableVisit::Init()
{
    viewModel1.setSourceModel(&model);
    viewModel2.setSourceModel(&viewModel1);
    viewModel3.setSourceModel(&viewModel2);
    ui->tableView->setModel(&viewModel3);
    ui->tableView->setColumnHidden(1, true);
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

void TableVisit::on_pushButton_2_clicked()
{
    numberPropusk = "0";
}

void TableVisit::on_pushButton_clicked()
{
    numberPropusk = "1";
}

void TableVisit::on_pushButton_4_clicked()
{
    numberPropusk = "2";
}

void TableVisit::on_tableView_clicked(const QModelIndex &index)
{
    QString FIO = model.record(index.row()).value(0).toString();

    QSqlQuery query( "SELECT id_st FROM students WHERE fio='" + FIO + "'" );
    while(query.next())
    {
        idSt = query.value(0).toString();
    }

    QSqlQuery query1( "UPDATE link3 SET otm='" + numberPropusk + "' WHERE id_st='" + idSt
                      + "' AND data='" + data + "' AND id_trab='" + idTrab + "' AND id_dis='" + idDis + "'" );
    query1.exec();

    if(!model.submitAll())
        QMessageBox::warning(this, "Error", model.lastError().text());
    update();

    //qDebug()<<idSt<<" "<<data<<" "<<idTrab<<" "<<idDis<<endl;
}
