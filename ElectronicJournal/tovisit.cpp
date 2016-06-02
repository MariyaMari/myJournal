#include "tovisit.h"
#include "ui_tovisit.h"

ToVisit::ToVisit(const SettingsPtr &settings, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ToVisit),
    m_settings(settings)
{
    ui->setupUi(this);

    visit = new TableVisit(settings);
    connect(ui->pushButton, SIGNAL(clicked()), visit, SLOT(show()));
}

ToVisit::~ToVisit()
{
    delete ui;
}

void ToVisit::Init(QSqlQueryModel *mod1, QSqlQueryModel *mod2, QSqlQueryModel *mod3)
{
    this->modData = mod1;
    ui->comboBox->setModel(mod1);

    this->modDis = mod2;
    ui->comboBox_2->setModel(mod2);

    this->modVidWor = mod3;
    ui->comboBox_3->setModel(mod3);
}

void ToVisit::on_pushButton_clicked()
{
    QSqlRelationalTableModel *mod = new QSqlRelationalTableModel(0, db);
    mod->setEditStrategy(QSqlRelationalTableModel::OnManualSubmit);
    mod->setTable("link3");
//    mod->setRelation(0, QSqlRelation("students", "id_st", "fio"));
    mod->select();
    mod->setFilter("id_trab=(SELECT typerabot.id_trab FROM typerabot WHERE typerabot.n_trab='"
                   + ui->comboBox_3->currentText() + "') "
                   "AND id_dis=(SELECT disciplina.id_dis FROM disciplina WHERE disciplina.n_dis='"
                   + ui->comboBox_2->currentText() + "') "
 //                  "AND data=" + ui->comboBox->currentText()
                   + ";");

    visit->Init(mod);
    visit->show();
}
