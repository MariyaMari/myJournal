#include "tableplan.h"
#include "ui_tableplan.h"

#include <QMessageBox>

TablePlan::TablePlan(const SettingsPtr &settings, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TablePlan),
    m_settings(settings)
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

void TablePlan::on_pushButton_clicked() //Удалить
{
    model->removeRow(ui->tableView->currentIndex().row());
}

void TablePlan::on_pushButton_2_clicked() //Добавить
{

}

void TablePlan::on_pushButton_3_clicked() //Подтвердить
{
    if(!model->submitAll())
        QMessageBox::warning(this, "Error", model->lastError().text());
    model->select();
}
