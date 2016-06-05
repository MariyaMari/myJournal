#include "formspecialty.h"
#include "ui_formspecialty.h"

#include <QMessageBox>

FormSpecialty::FormSpecialty(const SettingsPtr &settings, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormSpecialty),
    m_settings(settings)
{
    ui->setupUi(this);

    model = new QSqlRelationalTableModel(0, db);
    model->setEditStrategy(QSqlRelationalTableModel::OnManualSubmit);
    model->setTable("specialty");
    model->setRelation(2, QSqlRelation("facultet", "id_fac", "n_fac"));
    model->select();
    Init();

    addSpec = new AddSpecialty(settings);
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(on_pushButton_2_clicked()));
    connect(addSpec, SIGNAL(InsertQuery(QString)), this, SLOT(QueryInserted(QString)));
    connect(addSpec, SIGNAL(closeThisWidget()), this, SLOT(closeAddSpec()));
}

FormSpecialty::~FormSpecialty()
{
    delete ui;
}

void FormSpecialty::Update()
{
    model->select();
}

void FormSpecialty::Init()
{
    ui->tableView->setModel(model);
    ui->tableView->setColumnHidden(0, true);
    ui->tableView->show();
    model->setHeaderData(1, Qt::Horizontal, "Название Специальности");
    model->setHeaderData(2, Qt::Horizontal, "Факультет");

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
    QSqlQueryModel *mod = new QSqlQueryModel();
    mod->setQuery("select * from facultet;");

    addSpec->Init(mod, db);
    //addSpec->show();
    emit newWindow(addSpec);
}

void FormSpecialty::on_pushButton_3_clicked() //Подтвердить
{
    if(!model->submitAll())
        QMessageBox::warning(this, "Error", model->lastError().text());
    model->select();
}

void FormSpecialty::closeAddSpec()
{
    emit newWindow(this);
}

void FormSpecialty::QueryInserted(QString query)
{
    QSqlQuery q;
    if(!q.exec(query))
        QMessageBox::warning(this, "Error 1", q.lastError().text());
    model->submitAll();
}
