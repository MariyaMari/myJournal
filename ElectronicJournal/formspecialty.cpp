#include "formspecialty.h"
#include "ui_formspecialty.h"

#include <QMessageBox>

FormSpecialty::FormSpecialty(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormSpecialty)
{
    ui->setupUi(this);
}

FormSpecialty::~FormSpecialty()
{
    delete ui;
}

void FormSpecialty::Init(QSqlTableModel *mod)
{
    this->model = mod;
    ui->tableView->setModel(model);
    //ui->tableView->setColumnHidden(0, true);
    //ui->tableView->setColumnHidden(2, true);
    ui->tableView->show();
    model->setHeaderData(1, Qt::Horizontal, "Название Специальности");

    QHeaderView *pHW = ui->tableView->horizontalHeader(); //Нрмальный размер колонок
    int count = pHW->count();
    for (int i = 0; i < count; i++)
        pHW->setSectionResizeMode(i,QHeaderView::ResizeToContents);
}

void FormSpecialty::on_pushButton_clicked() //Удалить
{
    model->removeRow(ui->tableView->currentIndex().row());
}

void FormSpecialty::on_pushButton_2_clicked() //Добавить
{
    QSqlRecord newRec;
    model->insertRecord(-1, newRec);
}

void FormSpecialty::on_pushButton_3_clicked() //Подтвердить
{
    if(!model->submitAll())
        QMessageBox::warning(this, "Error", model->lastError().text());
    model->select();
}
