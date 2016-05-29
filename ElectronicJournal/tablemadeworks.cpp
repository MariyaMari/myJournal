#include "tablemadeworks.h"
#include "ui_tablemadeworks.h"

TableMadeWorks::TableMadeWorks(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TableMadeWorks)
{
    ui->setupUi(this);
}

TableMadeWorks::~TableMadeWorks()
{
    delete ui;
}

void TableMadeWorks::Init(QSqlTableModel *mod)
{
    this->model = mod;
    ui->tableView->setModel(model);
//    ui->tableView->setColumnHidden(0, true);

    ui->tableView->show();
    model->setHeaderData(1, Qt::Horizontal, "ФИО Студента");

    QHeaderView *pHW = ui->tableView->horizontalHeader(); //Нормальный размер колонок
    int count = pHW->count();
    for (int i = 0; i < count; i++)
        pHW->setSectionResizeMode(i,QHeaderView::ResizeToContents);
}
