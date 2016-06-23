#include "tablelistworks.h"
#include "ui_tablelistworks.h"

#include <QMessageBox>

TableListWorks::TableListWorks(const SettingsPtr &settings, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TableListWorks),
    m_settings(settings)
{
    ui->setupUi(this);

    model = new QSqlRelationalTableModel(0, db);
    model->setEditStrategy(QSqlRelationalTableModel::OnManualSubmit);
    model->setTable("link1");
    model->select();
    Init();

    addListWor = new AddListWorks(settings);
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(on_pushButton_2_clicked()));
    connect(addListWor, SIGNAL(InsertQuery(QString)), this, SLOT(QueryInserted(QString)));
    connect(addListWor, SIGNAL(closeThisWidget()), this, SLOT(closeAddListWorks()));
}

TableListWorks::~TableListWorks()
{
    delete ui;
}

void TableListWorks::update()
{
    model->select();
}

void TableListWorks::setNGr(const QString & text, const QString & text1, const QString & text2, const QString & text3)
{
    model->setFilter("id_trab=(SELECT typerabot.id_trab FROM typerabot WHERE typerabot.n_trab='"
                   + text + "') "
                   "AND id_dis=(SELECT disciplina.id_dis FROM disciplina WHERE disciplina.n_dis='"
                   + text1 + "') "
                   "AND id_spec=(SELECT specialty.id_spec FROM specialty WHERE specialty.n_spec='"
                   + text2 + "') "
                   + "AND semes=" + text3
                   + ";");

    this->Semes = text3;
    Spec = text2;
    Dis = text1;
    Trab = text;
}

void TableListWorks::Init()
{
    ui->tableView->setModel(model);
    ui->tableView->setColumnHidden(0, true);
    ui->tableView->setColumnHidden(3, true);
    ui->tableView->setColumnHidden(4, true);
    ui->tableView->setColumnHidden(5, true);
    ui->tableView->setColumnHidden(8, true);
    ui->tableView->show();
    model->setHeaderData(1, Qt::Horizontal, "Название");
    model->setHeaderData(2, Qt::Horizontal, "№");
    model->setHeaderData(6, Qt::Horizontal, "Срок");
    model->setHeaderData(7, Qt::Horizontal, "Ранг");

    QHeaderView *pHW = ui->tableView->horizontalHeader(); //Нормальный размер колонок
    int count = pHW->count();
    for (int i = 0; i < count; i++)
        pHW->setSectionResizeMode(i,QHeaderView::ResizeToContents);
}

void TableListWorks::on_pushButton_clicked() //Удалить
{
    model->removeRow(ui->tableView->currentIndex().row());
    if(!model->submitAll())
        QMessageBox::warning(this, "Error", model->lastError().text());
    model->select();
}

void TableListWorks::on_pushButton_2_clicked() //Добавить
{
    addListWor->Init(Semes, Spec, Dis, Trab, db);

    emit newWindow(addListWor);
}

void TableListWorks::closeAddListWorks()
{
    emit newWindow(this);
}

void TableListWorks::QueryInserted(QString query)
{
    QSqlQuery q;
    if(!q.exec(query))
        QMessageBox::warning(this, "Error 1", q.lastError().text());
    model->submitAll();
}
