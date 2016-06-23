#include "formtypeworks.h"
#include "ui_formtypeworks.h"

#include <QMessageBox>

FormTypeWorks::FormTypeWorks(const SettingsPtr &settings, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormTypeWorks),
    m_settings(settings)
{
    ui->setupUi(this);

    model = new QSqlTableModel(0, db);
    model->setEditStrategy(QSqlTableModel::OnFieldChange);
    model->setTable("typerabot");
    model->select();
    Init();
}

FormTypeWorks::~FormTypeWorks()
{
    delete ui;
}

void FormTypeWorks::Update()
{
    model->select();
}

void FormTypeWorks::Init()
{
    ui->tableView->setModel(model);
    ui->tableView->setColumnHidden(0, true);
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
    if(!model->submitAll())
        QMessageBox::warning(this, "Error", model->lastError().text());
    model->select();
}

void FormTypeWorks::on_pushButton_2_clicked() //Добавить
{
    int row = model->rowCount();
    model->insertRow(row);
}

