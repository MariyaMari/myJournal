#include "tomadeworks.h"
#include "ui_tomadeworks.h"

ToMadeWorks::ToMadeWorks(const SettingsPtr &settings, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ToMadeWorks),
    m_settings(settings)
{
    ui->setupUi(this);

    madeWorks = new TableMadeWorks(settings);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));
}

ToMadeWorks::~ToMadeWorks()
{
    delete ui;
}

void ToMadeWorks::Init(QSqlQueryModel *mod1, QSqlQueryModel *mod2, QSqlQueryModel *mod3, QSqlQueryModel *mod4)
{
    this->modData = mod1;
    ui->comboBox->setModel(mod1);

    this->modGr = mod2;
    ui->comboBox_2->setModel(mod2);

    this->modDis = mod3;
    ui->comboBox_3->setModel(mod3);

    this->modVidWor = mod4;
    ui->comboBox_4->setModel(mod4);
}

void ToMadeWorks::on_pushButton_clicked()
{
    QSqlRelationalTableModel *mod = new QSqlRelationalTableModel(0, db);
    mod->setEditStrategy(QSqlRelationalTableModel::OnManualSubmit);
    mod->setTable("link2");
//    mod->setRelation(0, QSqlRelation("students", "id_st", "fio"));
    mod->select();
//    mod->setFilter("id_spec=(SELECT specialty.id_spec FROM specialty WHERE specialty.n_spec='"
//                   + ui->comboBox_2->currentText() + "') "
//                   "AND semes=" + ui->comboBox->currentText() + ";");

    madeWorks->Init(mod);
    //madeWorks->show();
    emit newWindow(madeWorks);
}
