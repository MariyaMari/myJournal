#include "formstudents.h"
#include "ui_formstudents.h"

#include <QMessageBox>

FormStudents::FormStudents(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormStudents)
{
    ui->setupUi(this);
}

FormStudents::~FormStudents()
{
    delete ui;
}

void FormStudents::Init(QSqlTableModel *mod)
{
    this->model = mod;
    ui->tableView->setModel(model);
    //ui->tableView->setColumnHidden(0, true);
    ui->tableView->show();
    model->setHeaderData(1, Qt::Horizontal, "ФИО Студента");

    QHeaderView *pHW = ui->tableView->horizontalHeader(); //Нрмальный размер колонок
    int count = pHW->count();
    for (int i = 0; i < count; i++)
        pHW->setSectionResizeMode(i,QHeaderView::ResizeToContents);
}

void FormStudents::on_pushButton_clicked() //Удалить
{
    model->removeRow(ui->tableView->currentIndex().row());
}

void FormStudents::on_pushButton_2_clicked() //Добавить
{
    QSqlRecord newRec;
    model->insertRecord(-1, newRec);
}

void FormStudents::on_pushButton_3_clicked() //Подтвердить
{
    if(!model->submitAll())
        QMessageBox::warning(this, "Error", model->lastError().text());
    model->select();
}
