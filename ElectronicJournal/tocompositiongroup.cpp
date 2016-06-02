#include "tocompositiongroup.h"
#include "ui_tocompositiongroup.h"

ToCompositionGroup::ToCompositionGroup(const SettingsPtr &settings, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ToCompositionGroup),
    m_settings(settings)
{
    ui->setupUi(this);

    compGrup = new TableCompositionGroup(settings);
    connect(ui->pushButton, SIGNAL(clicked()), compGrup, SLOT(show()));
}

ToCompositionGroup::~ToCompositionGroup()
{
    delete ui;
}

void ToCompositionGroup::Init(QSqlQueryModel *mod1, QSqlQueryModel *mod2)
{
    this->modSemes = mod1;
    ui->comboBox->setModel(mod1);

    this->modGrup = mod2;
    ui->comboBox_2->setModel(mod2);
}

void ToCompositionGroup::on_pushButton_clicked()
{
    QSqlTableModel *mod = new QSqlTableModel(0, db);
    mod->setEditStrategy(QSqlTableModel::OnManualSubmit);
    mod->setTable("sostavgr");
    mod->select();
    mod->setFilter("id_gr=(SELECT gruppa.id_gr FROM gruppa WHERE gruppa.n_gr='"
                    + ui->comboBox_2->currentText() + "') "
                    "AND semes=" + ui->comboBox->currentText() + ";");

    compGrup->Init(mod);
    compGrup->show();
}
