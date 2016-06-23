#include "addplan.h"
#include "ui_addplan.h"

#include <QMessageBox>

AddPlan::AddPlan(const SettingsPtr &settings, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddPlan),
    m_settings(settings)
{
    ui->setupUi(this);
}

AddPlan::~AddPlan()
{
    delete ui;
}

void AddPlan::Init(QSqlQueryModel *mod1, const QString &Semes, const QString &Spec)
{
    ui->comboBox->setModel(mod1);

    this->semes = Semes;
    idSpec = Spec;
}

void AddPlan::on_pushButton_clicked()
{
    QSqlQueryModel *potModel = new QSqlQueryModel();
    potModel->setQuery("select id_dis from disciplina where n_dis = '" + ui->comboBox->currentText() + "';");
    QString pot = potModel->record(0).field(0).value().toString();


    QString query = "insert into plan (id_spec, id_dis, semes) values ('"
                    + idSpec + "', '"
                    + pot + "', '"
                    + semes
                    + "');";

    emit InsertQuery(query);
    emit closeThisWidget();
}
