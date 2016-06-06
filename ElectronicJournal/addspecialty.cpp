#include "addspecialty.h"
#include "ui_addspecialty.h"

#include <QMessageBox>

AddSpecialty::AddSpecialty(const SettingsPtr &settings, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddSpecialty),
    m_settings(settings)
{
    ui->setupUi(this);
}

AddSpecialty::~AddSpecialty()
{
    delete ui;
}

void AddSpecialty::Init(QSqlQueryModel *mod1, QSqlDatabase &db)
{
    this->db = &db;
    ui->comboBox->setModel(mod1);
}

void AddSpecialty::on_pushButton_clicked()
{
    if(ui->lineEdit->text() == "")
    {
        QMessageBox::warning(this, "Error", "All values must be filled");//вcе значения должны быть заполнены
        return;
    }

    QSqlQueryModel *potModel = new QSqlQueryModel();
    potModel->setQuery("select id_fac from facultet where n_fac = '" + ui->comboBox->currentText() + "';");

    QString pot = potModel->record(0).field(0).value().toString();

    QString query = "insert into specialty (n_spec, id_fac) values ('" + ui->lineEdit->text() + "', " + pot + ");";

    emit InsertQuery(query);
    emit closeThisWidget();
}
