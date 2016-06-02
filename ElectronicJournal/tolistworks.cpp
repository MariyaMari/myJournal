#include "tolistworks.h"
#include "ui_tolistworks.h"

ToListWorks::ToListWorks(const SettingsPtr &settings, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ToListWorks),
    m_settings(settings)
{
    ui->setupUi(this);

    listWorks = new TableListWorks(settings);
    connect(ui->pushButton, SIGNAL(clicked()), listWorks, SLOT(show()));
}

ToListWorks::~ToListWorks()
{
    delete ui;
}

void ToListWorks::Init(QSqlQueryModel *mod1, QSqlQueryModel *mod2, QSqlQueryModel *mod3, QSqlQueryModel *mod4)
{
    this->modSemes = mod1;
    ui->comboBox->setModel(mod1);

    this->modSpec = mod2;
    ui->comboBox_2->setModel(mod2);

    this->modDis = mod3;
    ui->comboBox_3->setModel(mod3);

    this->modVidWor = mod4;
    ui->comboBox_4->setModel(mod4);
}

void ToListWorks::on_pushButton_clicked()
{
    QSqlRelationalTableModel *mod = new QSqlRelationalTableModel(0, db);
    mod->setEditStrategy(QSqlRelationalTableModel::OnManualSubmit);
    mod->setTable("link1");
    mod->select();
    mod->setFilter("id_trab=(SELECT typerabot.id_trab FROM typerabot WHERE typerabot.n_trab='"
                   + ui->comboBox_4->currentText() + "') "
                   "AND id_dis=(SELECT disciplina.id_dis FROM disciplina WHERE disciplina.n_dis='"
                   + ui->comboBox_3->currentText() + "') "
                   "AND id_spec=(SELECT specialty.id_spec FROM specialty WHERE specialty.n_spec='"
                   + ui->comboBox_2->currentText() + "') "
                   "AND semes=" + ui->comboBox->currentText()
                   + ";");

    listWorks->Init(mod);
    listWorks->show();
}
