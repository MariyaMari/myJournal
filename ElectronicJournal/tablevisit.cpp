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
    ui->label_11->setText(numberPropusk);

    model.setEditStrategy(QSqlRelationalTableModel::OnManualSubmit);
    model.setTable("link3");
    //model.setFilter("fio = (SELECT students.fio FROM students, sostavgr, gruppa WHERE students.id_st = sostavgr.id_st AND gruppa.id_gr = sostavgr.id_gr AND gruppa.n_gr='ПО-11')");
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

void TableVisit::setFilter(const QString &n_trab, const QString &n_dis, const QString &data, const QString &n_gr)
{
    model.setFilter("link3.id_st=(SELECT sostavgr.id_st FROM sostavgr, gruppa WHERE gruppa.id_gr = sostavgr.id_gr AND gruppa.n_gr='" + n_gr + "')");
    model.select();

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

//    QSqlQuery query2( "SELECT sostavgr.id_st FROM sostavgr, gruppa WHERE gruppa.id_gr = sostavgr.id_gr AND gruppa.n_gr='" + n_gr + "'" );
//    QString regString = "(";
//    while(query2.next())
//    {
//        regString += query2.value(0).toString() + "|";
//    }
//    regString = regString.left(regString.length() - 1);
//    regString += ")";
    QString regString = "";
    QRegExp regExp(regString);

    viewModel4.setFilterKeyColumn(0);
    viewModel4.setFilterRegExp(regExp);

//    qDebug()<<regString<<endl;


    this->data = data;
    idDis = id_dis;
    idTrab = id_trab;

    ui->label_3->setText(data);
    ui->label_5->setText(n_gr);
    ui->label_7->setText(n_dis);
    ui->label_9->setText(n_trab);
}

void TableVisit::Init()
{
    viewModel1.setSourceModel(&model);
    viewModel2.setSourceModel(&viewModel1);
    viewModel3.setSourceModel(&viewModel2);
    viewModel4.setSourceModel(&viewModel3);
    ui->tableView->setModel(&viewModel4);
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
    ui->label_11->setText(numberPropusk);
}

void TableVisit::on_pushButton_clicked()
{
    numberPropusk = "1";
    ui->label_11->setText(numberPropusk);
}

void TableVisit::on_pushButton_4_clicked()
{
    numberPropusk = "2";
    ui->label_11->setText(numberPropusk);
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
