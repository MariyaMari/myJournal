#include "addlistworks.h"
#include "ui_addlistworks.h"

#include <QMessageBox>

AddListWorks::AddListWorks(const SettingsPtr &settings, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddListWorks),
    m_settings(settings)
{
    ui->setupUi(this);
}

AddListWorks::~AddListWorks()
{
    delete ui;
}

void AddListWorks::Init(const QString &Semes, const QString &Spec, const QString &Dis, const QString &Trab, QSqlDatabase &db)
{
    this->db = &db;

    QSqlQueryModel *potModel = new QSqlQueryModel();
    potModel->setQuery("select id_spec from specialty where n_spec = '" + Spec + "';", db);
    idSpec = potModel->record(0).field(0).value().toString();

    QSqlQueryModel *potModel1 = new QSqlQueryModel();
    potModel1->setQuery("select id_trab from typerabot where n_trab = '" + Trab + "';", db);
    idTrab = potModel1->record(0).field(0).value().toString();

    QSqlQueryModel *potModel2 = new QSqlQueryModel();
    potModel2->setQuery("select id_dis from disciplina where n_dis = '" + Dis + "';", db);
    idDis = potModel2->record(0).field(0).value().toString();

    semes = Semes;
}

void AddListWorks::on_pushButton_clicked()
{
    if(ui->lineEdit->text() == "" || ui->lineEdit_2->text() == "" || ui->lineEdit_3->text() == "" || ui->lineEdit_4->text() == "")
    {
        QMessageBox::warning(this, "Error", "All values must be filled");//вcе значения должны быть заполнены
        return;
    }

    QString query = "insert into link1 (id_spec, n_rab, rabn, id_trab, semes, id_dis, nedel, rang) values ('"
                    + idSpec + "', '"
                    + ui->lineEdit->text() + "', '"
                    + ui->lineEdit_2->text() + "', "
                    + idTrab + ", "
                    + semes + ", "
                    + idDis + ", '"
                    + ui->lineEdit_3->text() + "', "
                    + ui->lineEdit_4->text()
                    + ");";

    emit InsertQuery(query);
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    emit closeThisWidget();
}
