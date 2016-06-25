#include "tablecompositiongroup.h"
#include "ui_tablecompositiongroup.h"

#include <QMessageBox>

TableCompositionGroup::TableCompositionGroup(const SettingsPtr &settings, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TableCompositionGroup),
    m_settings(settings)
{
    ui->setupUi(this);

    model.setEditStrategy(QSqlRelationalTableModel::OnManualSubmit);
    model.setTable("sostavgr");
    model.setRelation(2, QSqlRelation("students", "id_st", "fio"));
    update();
    Init();

    addCompGr = new AddCompGroup(settings);
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(on_pushButton_2_clicked()));
    connect(addCompGr, SIGNAL(InsertQuery(QString)), this, SLOT(QueryInserted(QString)));
    connect(addCompGr, SIGNAL(closeThisWidget()), this, SLOT(closeAddCompGr()));
}

TableCompositionGroup::~TableCompositionGroup()
{
    delete ui;
}

void TableCompositionGroup::update()
{
    model.select();
}

void TableCompositionGroup::setFilter(const QString & semes, const QString & n_gr)
{
    viewModel1.setFilterKeyColumn(0);
    viewModel1.setFilterFixedString(semes);

    QSqlQuery query( "SELECT id_gr FROM gruppa WHERE n_gr='" + n_gr + "'" );
    QString id_gr;
    while(query.next())
    {
        id_gr = query.value(0).toString();
    }
    viewModel2.setFilterKeyColumn(1);
    viewModel2.setFilterFixedString(id_gr);

    this->Semes = semes;
    idGr = id_gr;

    ui->label_3->setText(n_gr);
    ui->label_5->setText(semes);
}

void TableCompositionGroup::Init()
{
    viewModel1.setSourceModel(&model);
    viewModel2.setSourceModel(&viewModel1);
    ui->tableView->setModel(&viewModel2);
    ui->tableView->setColumnHidden(0, true);
    ui->tableView->setColumnHidden(1, true);
    ui->tableView->show();
    model.setHeaderData(2, Qt::Horizontal, "ФИО Студента");

    QHeaderView *pHW = ui->tableView->horizontalHeader(); //Нормальный размер колонок
    int count = pHW->count();
    for (int i = 0; i < count; i++)
        pHW->setSectionResizeMode(i,QHeaderView::ResizeToContents);
}

void TableCompositionGroup::on_pushButton_clicked() //Удалить
{
    model.removeRow(ui->tableView->currentIndex().row());
    if(!model.submitAll())
        QMessageBox::warning(this, "Error", model.lastError().text());
    update();
}

void TableCompositionGroup::on_pushButton_2_clicked() //Добавить
{
    QSqlQueryModel *mod = new QSqlQueryModel();
    mod->setQuery("select fio from students;");

    addCompGr->Init(mod, Semes, idGr);

    emit newWindow(addCompGr);
}

void TableCompositionGroup::closeAddCompGr()
{
    emit newWindow(this);
}

void TableCompositionGroup::QueryInserted(QString query)
{
    QSqlQuery q;
    if(!q.exec(query))
        QMessageBox::warning(this, "Error 1", q.lastError().text());
    model.submitAll();
}
