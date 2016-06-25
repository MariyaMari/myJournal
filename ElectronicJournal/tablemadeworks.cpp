#include "tablemadeworks.h"
#include "ui_tablemadeworks.h"

TableMadeWorks::TableMadeWorks(const SettingsPtr &settings, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TableMadeWorks),
    m_settings(settings)
{
    ui->setupUi(this);

    model.setEditStrategy(QSqlRelationalTableModel::OnManualSubmit);
    model.setTable("link2");
    model.setRelation(1, QSqlRelation("students", "id_st", "fio"));
    update();
    Init();
}

TableMadeWorks::~TableMadeWorks()
{
    delete ui;
}

void TableMadeWorks::update()
{
    model.select();
}

void TableMadeWorks::setFilter(const QString & n_gr, const QString & n_dis, const QString & n_trab, const QString &data)
{
    viewModel1.setFilterKeyColumn(0);
    viewModel1.setFilterFixedString(data);

    model.setFilter("link2.id_st=(SELECT sostavgr.id_st FROM sostavgr, gruppa WHERE gruppa.id_gr = sostavgr.id_gr AND gruppa.n_gr='" + n_gr + "')");
    model.select();


    ui->label_3->setText(data);
    ui->label_5->setText(n_gr);
    ui->label_7->setText(n_dis);
    ui->label_9->setText(n_trab);
}

void TableMadeWorks::Init()
{
    viewModel1.setSourceModel(&model);
    viewModel2.setSourceModel(&viewModel1);
    ui->tableView->setModel(&viewModel2);
//    ui->tableView->setColumnHidden(0, true);

    ui->tableView->show();
    model.setHeaderData(1, Qt::Horizontal, "ФИО Студента");
//    model.setHeaderData(2, Qt::Horizontal, "Номер\nработы");

    QHeaderView *pHW = ui->tableView->horizontalHeader(); //Нормальный размер колонок
    int count = pHW->count();
    for (int i = 0; i < count; i++)
        pHW->setSectionResizeMode(i,QHeaderView::ResizeToContents);
}
