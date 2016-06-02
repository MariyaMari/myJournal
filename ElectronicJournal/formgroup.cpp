#include "formgroup.h"
#include "ui_formgroup.h"

#include <QMessageBox>

FormGroup::FormGroup(const SettingsPtr &settings, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormGroup),
    m_settings(settings)
{
    ui->setupUi(this);
}

FormGroup::~FormGroup()
{
    delete ui;
}

void FormGroup::Init(QSqlTableModel *mod)
{
    this->model = mod;
    ui->tableView->setModel(model);
    //ui->tableView->setColumnHidden(0, true);
    //ui->tableView->setColumnHidden(3, true);
    ui->tableView->show();
    model->setHeaderData(1, Qt::Horizontal, "Название Групп");
    model->setHeaderData(2, Qt::Horizontal, "Год");

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
    QSqlRecord newRec;
    model->insertRecord(-1, newRec);
}

void FormGroup::on_pushButton_3_clicked() //Подтвердить
{
    if(!model->submitAll())
        QMessageBox::warning(this, "Error", model->lastError().text());
    model->select();
}
