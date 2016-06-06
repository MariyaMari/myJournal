#include "tableplan.h"
#include "ui_tableplan.h"

#include <QMessageBox>

TablePlan::TablePlan(const SettingsPtr &settings, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TablePlan),
    m_settings(settings)
{
    ui->setupUi(this);

    model = new QSqlRelationalTableModel(0, db);
    model->setEditStrategy(QSqlRelationalTableModel::OnManualSubmit);
    model->setTable("plan");
    model->setRelation(1, QSqlRelation("disciplina", "id_dis", "n_dis"));
    model->select();
    Init();
}

TablePlan::~TablePlan()
{
    delete ui;
}

void TablePlan::Update()
{
    model->select();
}

void TablePlan::setNGr(const QString & text, const QString & text1)
{
    model->setFilter("id_spec=(SELECT specialty.id_spec FROM specialty WHERE specialty.n_spec='"
                    + text + "') "
                    "AND semes=" + text1
                    + ";");

}

void TablePlan::Init()
{
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
