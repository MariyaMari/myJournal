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
    QString data = ui->comboBox->currentText();
    QString n_gr = ui->comboBox_2->currentText();
    QString n_dis = ui->comboBox_3->currentText();
    QString n_trab = ui->comboBox_4->currentText();

    madeWorks->update();
    madeWorks->setFilter(n_gr, n_dis, n_trab);

    emit newWindow(madeWorks);
}
