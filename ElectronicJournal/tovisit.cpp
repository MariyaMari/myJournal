#include "tovisit.h"
#include "ui_tovisit.h"

ToVisit::ToVisit(const SettingsPtr &settings, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ToVisit),
    m_settings(settings)
{
    ui->setupUi(this);

    visit = new TableVisit(settings);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));
}

ToVisit::~ToVisit()
{
    delete ui;
}

void ToVisit::Init(QSqlQueryModel *mod1, QSqlQueryModel *mod2, QSqlQueryModel *mod3, QSqlQueryModel *mod4)
{
    this->modData = mod1;
    ui->comboBox->setModel(mod1);

    this->modDis = mod2;
    ui->comboBox_2->setModel(mod2);

    this->modVidWor = mod3;
    ui->comboBox_3->setModel(mod3);

    this->modGr = mod4;
    ui->comboBox_4->setModel(mod4);
}

void ToVisit::on_pushButton_clicked()
{
    QString data = ui->comboBox->currentText();
    QString n_dis = ui->comboBox_2->currentText();
    QString n_trab = ui->comboBox_3->currentText();
    QString n_gr = ui->comboBox_4->currentText();

    visit->update();
    visit->setFilter(n_trab, n_dis, data, n_gr);

    emit newWindow(visit);
}
