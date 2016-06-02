#include "tablecompositiongroup.h"
#include "ui_tablecompositiongroup.h"

#include <QMessageBox>

TableCompositionGroup::TableCompositionGroup(const SettingsPtr &settings, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TableCompositionGroup),
    m_settings(settings)
{
    ui->setupUi(this);
}

TableCompositionGroup::~TableCompositionGroup()
{
    delete ui;
}

void TableCompositionGroup::Init(QSqlTableModel *mod)
{
    this->model = mod;
    ui->tableView->setModel(model);
    ui->tableView->setColumnHidden(0, true);
    ui->tableView->setColumnHidden(1, true);
    ui->tableView->show();
    model->setHeaderData(2, Qt::Horizontal, "ФИО Студента");

    QHeaderView *pHW = ui->tableView->horizontalHeader(); //Нормальный размер колонок
    int count = pHW->count();
    for (int i = 0; i < count; i++)
        pHW->setSectionResizeMode(i,QHeaderView::ResizeToContents);
}

void TableCompositionGroup::on_pushButton_clicked() //Удалить
{
    model->removeRow(ui->tableView->currentIndex().row());
}

void TableCompositionGroup::on_pushButton_2_clicked() //Добавить
{

}

void TableCompositionGroup::on_pushButton_3_clicked() //Подтвердить
{
    if(!model->submitAll())
        QMessageBox::warning(this, "Error", model->lastError().text());
    model->select();
}
