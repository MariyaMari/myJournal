#include "tableplan.h"
#include "ui_tableplan.h"

#include <QMessageBox>

TablePlan::TablePlan(const SettingsPtr &settings, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TablePlan),
    m_settings(settings)
{
    ui->setupUi(this);

    model.setEditStrategy(QSqlRelationalTableModel::OnManualSubmit);
    model.setTable("plan");
    model.setRelation(1, QSqlRelation("disciplina", "id_dis", "n_dis"));
    update();
    Init();

    addPlan = new AddPlan(settings);
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(on_pushButton_2_clicked()));
    connect(addPlan, SIGNAL(InsertQuery(QString)), this, SLOT(QueryInserted(QString)));
    connect(addPlan, SIGNAL(closeThisWidget()), this, SLOT(closeAddPlan()));
}

TablePlan::~TablePlan()
{
    delete ui;
}

void TablePlan::update()
{
    model.select();
}

void TablePlan::setFilter(const QString & n_spec, const QString & semes)
{
    viewModel1.setFilterKeyColumn(2);
    viewModel1.setFilterFixedString(semes);

    QSqlQuery query( "SELECT id_spec FROM specialty WHERE n_spec='" + n_spec + "'" );
    QString id_spec;
    while(query.next())
    {
        id_spec = query.value(0).toString();
    }
    viewModel2.setFilterKeyColumn(0);
    viewModel2.setFilterFixedString(id_spec);

    this->Semes = semes;
    idSpec = id_spec;

    ui->label_3->setText(n_spec);
    ui->label_5->setText(semes);
}

void TablePlan::Init()
{
    viewModel1.setSourceModel(&model);
    viewModel2.setSourceModel(&viewModel1);
    ui->tableView->setModel(&viewModel2);
    ui->tableView->setColumnHidden(0, true);
    ui->tableView->setColumnHidden(2, true);
    ui->tableView->show();
    model.setHeaderData(1, Qt::Horizontal, "Название Дисциплины");

    QHeaderView *pHW = ui->tableView->horizontalHeader(); //Нормальный размер колонок
    int count = pHW->count();
    for (int i = 0; i < count; i++)
        pHW->setSectionResizeMode(i,QHeaderView::ResizeToContents);
}

void TablePlan::on_pushButton_clicked() //Удалить
{
    model.removeRow(ui->tableView->selectionModel()->currentIndex().row());
    //qDebug() << ui->tableView->currentIndex().row() << model.lastError().driverText();
    /*QList<int> delList;
        foreach(QModelIndex ind, ui->tableView->selectionModel()->selectedRows()) {
     delList.append(ind.row());
    }

        int k=0;
        foreach(int ind, delList) {
            model.removeRow(ind-k);
            model.select();
            k++;
        }
        model.removeRow(0);*/
    if(!model.submitAll())
        QMessageBox::warning(this, "Error", model.lastError().text());
    model.select();
}

void TablePlan::on_pushButton_2_clicked() //Добавить
{
    QSqlQueryModel *mod = new QSqlQueryModel();
    mod->setQuery("select n_dis from disciplina;");

    addPlan->Init(mod, Semes, idSpec);

    emit newWindow(addPlan);
}

void TablePlan::closeAddPlan()
{
    emit newWindow(this);
}

void TablePlan::QueryInserted(QString query)
{
    QSqlQuery q;
    if(!q.exec(query))
        QMessageBox::warning(this, "Error 1", q.lastError().text());
    model.submitAll();
}
