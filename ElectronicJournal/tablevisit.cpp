#include "tablevisit.h"
#include "ui_tablevisit.h"

#include <QMessageBox>

TableVisit::TableVisit(const SettingsPtr &settings, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TableVisit),
    m_settings(settings)
{
    ui->setupUi(this);

    model = new QSqlRelationalTableModel(0, db);
    model->setEditStrategy(QSqlRelationalTableModel::OnManualSubmit);
    model->setTable("link3");
    model->setRelation(0, QSqlRelation("students", "id_st", "fio"));
    model->select();
    Init();
}

TableVisit::~TableVisit()
{
    delete ui;
}

void TableVisit::Update()
{
    model->select();
}

void TableVisit::setNGr(const QString & text, const QString & text1, const QString & text2)
{
    model->setFilter("id_trab=(SELECT typerabot.id_trab FROM typerabot WHERE typerabot.n_trab='"
                   + text + "') "
                   "AND id_dis=(SELECT disciplina.id_dis FROM disciplina WHERE disciplina.n_dis='"
                   + text1 + "') "
 //                  "AND data=" + text2
                   + ";");

}

void TableVisit::Init()
{
    ui->tableView->setModel(model);
//    ui->tableView->setColumnHidden(1, true);
    ui->tableView->setColumnHidden(2, true);
    ui->tableView->setColumnHidden(4, true);
    ui->tableView->show();
    model->setHeaderData(0, Qt::Horizontal, "ФИО Студента");
    model->setHeaderData(3, Qt::Horizontal, "Пропуск");

    QHeaderView *pHW = ui->tableView->horizontalHeader(); //Нормальный размер колонок
    int count = pHW->count();
    for (int i = 0; i < count; i++)
        pHW->setSectionResizeMode(i,QHeaderView::ResizeToContents);

}

void TableVisit::on_pushButton_clicked() //Удалить
{
    model->removeRow(ui->tableView->currentIndex().row());
}

void TableVisit::on_pushButton_2_clicked() //Добавить
{

}

void TableVisit::on_pushButton_3_clicked() //Подтвердить
{
    if(!model->submitAll())
        QMessageBox::warning(this, "Error", model->lastError().text());
    model->select();
}
