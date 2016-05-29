#include "formtypeworks.h"
#include "ui_formtypeworks.h"

#include <QMessageBox>

FormTypeWorks::FormTypeWorks(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormTypeWorks)
{
    ui->setupUi(this);
}

FormTypeWorks::~FormTypeWorks()
{
    delete ui;
}

void FormTypeWorks::Init(QSqlTableModel *mod)
{
    this->model = mod;
    ui->tableView->setModel(model);
    //ui->tableView->setColumnHidden(0, true);
    ui->tableView->show();
    model->setHeaderData(1, Qt::Horizontal, "Тип Работы");

    QHeaderView *pHW = ui->tableView->horizontalHeader(); //Нрмальный размер колонок
    int count = pHW->count();
    for (int i = 0; i < count; i++)
        pHW->setSectionResizeMode(i,QHeaderView::ResizeToContents);
}

void FormTypeWorks::on_pushButton_clicked() //Удалить
{
    model->removeRow(ui->tableView->currentIndex().row());
}

void FormTypeWorks::on_pushButton_2_clicked() //Добавить
{
    QSqlRecord newRec;
    model->insertRecord(-1, newRec);
}

void FormTypeWorks::on_pushButton_3_clicked() //Подтвердить
{
    if(!model->submitAll())
        QMessageBox::warning(this, "Error", model->lastError().text());
    model->select();
}
