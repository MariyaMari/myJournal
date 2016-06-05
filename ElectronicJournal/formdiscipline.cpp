#include "formdiscipline.h"
#include "ui_formdiscipline.h"

#include <QMessageBox>

FormDiscipline::FormDiscipline(const SettingsPtr &settings, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormDiscipline),
    m_settings(settings)
{
    ui->setupUi(this);

    model = new QSqlTableModel(0, db);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->setTable("disciplina");
    model->select();
    Init();


    QIcon remove("remove.png"); //Иконки на кнопки
    ui->pushButton->setIcon(remove);
}

FormDiscipline::~FormDiscipline()
{
    delete ui;
}

void FormDiscipline::Update()
{
    model->select();
}

void FormDiscipline::Init()
{
    ui->tableView->setModel(model);
    ui->tableView->setColumnHidden(0, true);
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
    QSqlRecord newRec;
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
