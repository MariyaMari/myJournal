#include "tablelistworks.h"
#include "ui_tablelistworks.h"

TableListWorks::TableListWorks(const SettingsPtr &settings, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TableListWorks),
    m_settings(settings)
{
    ui->setupUi(this);
}

TableListWorks::~TableListWorks()
{
    delete ui;
}

void TableListWorks::Init(QSqlRelationalTableModel *mod)
{
    this->model = mod;
    ui->tableView->setModel(model);
    ui->tableView->setColumnHidden(0, true);
    ui->tableView->setColumnHidden(3, true);
    ui->tableView->setColumnHidden(4, true);
    ui->tableView->setColumnHidden(5, true);
    ui->tableView->setColumnHidden(8, true);
    ui->tableView->show();
    model->setHeaderData(1, Qt::Horizontal, "Название");
    model->setHeaderData(2, Qt::Horizontal, "№");
    model->setHeaderData(6, Qt::Horizontal, "Продолжительность");
    model->setHeaderData(7, Qt::Horizontal, "Ранг");

    QHeaderView *pHW = ui->tableView->horizontalHeader(); //Нормальный размер колонок
    int count = pHW->count();
    for (int i = 0; i < count; i++)
        pHW->setSectionResizeMode(i,QHeaderView::ResizeToContents);
}
