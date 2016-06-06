#include "tablemadeworks.h"
#include "ui_tablemadeworks.h"

TableMadeWorks::TableMadeWorks(const SettingsPtr &settings, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TableMadeWorks),
    m_settings(settings)
{
    ui->setupUi(this);

    model = new QSqlRelationalTableModel(0, db);
    model->setEditStrategy(QSqlRelationalTableModel::OnManualSubmit);
    model->setTable("link2");
//    model->setRelation(0, QSqlRelation("students", "id_st", "fio"));
    model->select();
    Init();
}

TableMadeWorks::~TableMadeWorks()
{
    delete ui;
}

void TableMadeWorks::Update()
{
    model->select();
}

void TableMadeWorks::setNGr(const QString & text, const QString & text1)
{
//    model->setFilter("id_spec=(SELECT specialty.id_spec FROM specialty WHERE specialty.n_spec='"
//                   + text) + "') "
//                   "AND semes=" + text1) + ";");

}

void TableMadeWorks::Init()
{
    ui->tableView->setModel(model);
//    ui->tableView->setColumnHidden(0, true);

    ui->tableView->show();
    model->setHeaderData(1, Qt::Horizontal, "ФИО Студента");

    QHeaderView *pHW = ui->tableView->horizontalHeader(); //Нормальный размер колонок
    int count = pHW->count();
    for (int i = 0; i < count; i++)
        pHW->setSectionResizeMode(i,QHeaderView::ResizeToContents);
}
