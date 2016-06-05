#include "formfaculty.h"
#include "ui_formfaculty.h"

#include <QMessageBox>

FormFaculty::FormFaculty(const SettingsPtr &settings, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormFaculty),
    m_settings(settings)
{
    ui->setupUi(this);

    model = new QSqlTableModel(0, db);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->setTable("facultet");
    model->select();
    Init();
}

FormFaculty::~FormFaculty()
{
    delete ui;
}

void FormFaculty::Update()
{
    model->select();
}

void FormFaculty::Init()
{
    ui->tableView->setModel(model);
    ui->tableView->setColumnHidden(0, true);
    ui->tableView->show();
    model->setHeaderData(1, Qt::Horizontal, "Название Факультета");

    QHeaderView *pHW = ui->tableView->horizontalHeader(); //Нрмальный размер колонок
    int count = pHW->count();
    for (int i = 0; i < count; i++)
        pHW->setSectionResizeMode(i,QHeaderView::ResizeToContents);
}

void FormFaculty::on_pushButton_clicked() //Удалить
{
    model->removeRow(ui->tableView->currentIndex().row());
}

void FormFaculty::on_pushButton_2_clicked() //Добавить
{
    QSqlRecord newRec;
    model->insertRecord(-1, newRec);
}

void FormFaculty::on_pushButton_3_clicked() //Подтвердить
{
    if(!model->submitAll())
        QMessageBox::warning(this, "Error", model->lastError().text());
    model->select();
}

