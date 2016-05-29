#include "toplan.h"
#include "ui_toplan.h"

ToPlan::ToPlan(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ToPlan)
{
    ui->setupUi(this);

    plan = new TablePlan();
    connect(ui->pushButton, SIGNAL(clicked()), plan, SLOT(show()));
}

ToPlan::~ToPlan()
{
    delete ui;
}

void ToPlan::Init(QSqlQueryModel *mod1, QSqlQueryModel *mod2)
{
    this->modSemes = mod1;
    ui->comboBox->setModel(mod1);

    this->modSpec = mod2;
    ui->comboBox_2->setModel(mod2);
}

void ToPlan::on_pushButton_clicked()
{
    QSqlTableModel *mod = new QSqlTableModel(0, db);
    mod->setEditStrategy(QSqlTableModel::OnManualSubmit);
    mod->setTable("plan");
    mod->select();
    mod->setFilter("id_spec=(SELECT specialty.id_spec FROM specialty WHERE specialty.n_spec='"
                    + ui->comboBox_2->currentText() + "') "
                    "AND semes=" + ui->comboBox->currentText()
 //                  + "AND id_dis=(SELECT disciplina.n_dis FROM disciplina WHERE plan.id_dis=disciplina.id_dis)"
                    + ";");

 /*   QSqlQueryModel *potModel = new QSqlQueryModel();
    potModel->setQuery("select id_dis from disciplina where n_dis = '" + ui->comboBox->currentText() + "';");

    QString pot = potModel->record(0).field(0).value().toString();

    mod->setFilter("id_dis=" + pot);*/

    plan->Init(mod);
    plan->show();
}
