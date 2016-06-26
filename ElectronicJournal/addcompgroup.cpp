#include "addcompgroup.h"
#include "ui_addcompgroup.h"

AddCompGroup::AddCompGroup(const SettingsPtr &settings, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddCompGroup),
    m_settings(settings)
{
    ui->setupUi(this);
}

AddCompGroup::~AddCompGroup()
{
    delete ui;
}

void AddCompGroup::Init(QSqlQueryModel *mod1, const QString &Semes, const QString &Gr)
{
    ui->comboBox->setModel(mod1);

    this->semes = Semes;
    idGr = Gr;
}

void AddCompGroup::on_pushButton_clicked()
{
    QSqlQueryModel *potModel = new QSqlQueryModel();
    potModel->setQuery("select id_st from students where fio = '" + ui->comboBox->currentText() + "';");
    QString pot = potModel->record(0).field(0).value().toString();


    QString query = "insert into sostavgr (id_gr, id_st, semes) values ('"
                    + idGr + "', '"
                    + pot + "', '"
                    + semes
                    + "');";

    emit InsertQuery(query);
    emit closeThisWidget();
}

