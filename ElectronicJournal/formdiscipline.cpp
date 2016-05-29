#include "formdiscipline.h"
#include "ui_formdiscipline.h"

#include <QMessageBox>

FormDiscipline::FormDiscipline(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormDiscipline)
{
    ui->setupUi(this);

    QIcon remove("remove.png"); //Иконки на кнопки
    ui->pushButton->setIcon(remove);
}

FormDiscipline::~FormDiscipline()
{
    delete ui;
}

void FormDiscipline::Init(QSqlTableModel *mod)
{
    this->model = mod;
    ui->tableView->setModel(model);
   // ui->tableView->setColumnHidden(0, true);
    ui->tableView->show();
    model->setHeaderData(1, Qt::Horizontal, "Название Дисциплины");

    QHeaderView *pHW = ui->tableView->horizontalHeader(); //Нормальный размер колонок
    int count = pHW->count();
    for (int i = 0; i < count; i++)
        pHW->setSectionResizeMode(i,QHeaderView::ResizeToContents);

}

void FormDiscipline::on_pushButton_clicked() //Удалить
{
    model->removeRow(ui->tableView->currentIndex().row());
}

void FormDiscipline::on_pushButton_2_clicked() //Добавить
{
    QSqlRecord newRec;// = model->record();
   // newRec.field("id_dis").setGenerated(true);
   // newRec.field("id_dis").setValue(10);
    model->insertRecord(-1, newRec);
}

void FormDiscipline::on_pushButton_3_clicked() //Подтвердить
{
    if(!model->submitAll())
        QMessageBox::warning(this, "Error", model->lastError().text());
    model->select();
}

void FormDiscipline::closeEvent(QCloseEvent *e)
{
    emit Closed();
    QWidget::closeEvent(e);
}
