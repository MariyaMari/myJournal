#include "tableplan.h"
#include "ui_tableplan.h"

TablePlan::TablePlan(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TablePlan)
{
    ui->setupUi(this);
}

TablePlan::~TablePlan()
{
    delete ui;
}

void TablePlan::Init(QSqlTableModel *mod)
{
    this->model = mod;
    ui->tableView->setModel(model);
    ui->tableView->setColumnHidden(0, true);
    ui->tableView->setColumnHidden(2, true);
    ui->tableView->show();
    model->setHeaderData(1, Qt::Horizontal, "Название Дисциплины");

    QHeaderView *pHW = ui->tableView->horizontalHeader(); //Нормальный размер колонок
    int count = pHW->count();
    for (int i = 0; i < count; i++)
        pHW->setSectionResizeMode(i,QHeaderView::ResizeToContents);
}
