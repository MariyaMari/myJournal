#include "tablevisit.h"
#include "ui_tablevisit.h"

TableVisit::TableVisit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TableVisit)
{
    ui->setupUi(this);
}

TableVisit::~TableVisit()
{
    delete ui;
}

void TableVisit::Init(QSqlTableModel *mod)
{
    this->model = mod;
    ui->tableView->setModel(model);
//    ui->tableView->setColumnHidden(1, true);
//    ui->tableView->setColumnHidden(2, true);
//    ui->tableView->setColumnHidden(4, true);
    ui->tableView->show();
    model->setHeaderData(0, Qt::Horizontal, "ФИО Студента");
    model->setHeaderData(3, Qt::Horizontal, "Пропуск");

    QHeaderView *pHW = ui->tableView->horizontalHeader(); //Нормальный размер колонок
    int count = pHW->count();
    for (int i = 0; i < count; i++)
        pHW->setSectionResizeMode(i,QHeaderView::ResizeToContents);

}
