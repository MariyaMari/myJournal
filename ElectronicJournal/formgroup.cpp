#include "formgroup.h"
#include "ui_formgroup.h"

#include <QMessageBox>

FormGroup::FormGroup(const SettingsPtr &settings, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormGroup),
    m_settings(settings)
{
    ui->setupUi(this);

    model = new QSqlRelationalTableModel(0, db);
    model->setEditStrategy(QSqlRelationalTableModel::OnManualSubmit);
    model->setTable("gruppa");
    model->setRelation(3, QSqlRelation("specialty", "id_spec", "n_spec"));
    model->select();
    Init();

    addGrup = new AddGroup(settings);
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(on_pushButton_2_clicked()));
    connect(addGrup, SIGNAL(InsertQuery(QString)), this, SLOT(QueryInserted(QString)));
    connect(addGrup, SIGNAL(closeThisWidget()), this, SLOT(closeAddSpec()));
}

FormGroup::~FormGroup()
{
    delete ui;
}

void FormGroup::Update()
{
    model->select();
}

void FormGroup::Init()
{
    ui->tableView->setModel(model);
    ui->tableView->setColumnHidden(0, true);
    ui->tableView->show();
    model->setHeaderData(1, Qt::Horizontal, "Название Групп");
    model->setHeaderData(2, Qt::Horizontal, "Год");
    model->setHeaderData(3, Qt::Horizontal, "Специальность");

    QHeaderView *pHW = ui->tableView->horizontalHeader(); //Нрмальный размер колонок
    int count = pHW->count();
    for (int i = 0; i < count; i++)
        pHW->setSectionResizeMode(i,QHeaderView::ResizeToContents);
}

void FormGroup::on_pushButton_clicked() //Удалить
{
    model->removeRow(ui->tableView->currentIndex().row());
}

void FormGroup::on_pushButton_2_clicked() //Добавить
{
    QSqlQueryModel *mod = new QSqlQueryModel();
    mod->setQuery("select * from specialty;");

    addGrup->Init(mod, db);
    //addGrup->show();
    emit newWindow(addGrup);
}

void FormGroup::on_pushButton_3_clicked() //Подтвердить
{
    if(!model->submitAll())
        QMessageBox::warning(this, "Error", model->lastError().text());
    model->select();
}

void FormGroup::closeAddSpec()
{
    emit newWindow(this);
}

void FormGroup::QueryInserted(QString query)
{
    QSqlQuery q;
    if(!q.exec(query))
        QMessageBox::warning(this, "Error 1", q.lastError().text());
    model->submitAll();
}
