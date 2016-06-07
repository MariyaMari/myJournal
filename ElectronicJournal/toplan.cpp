#include "toplan.h"
#include "ui_toplan.h"

ToPlan::ToPlan(const SettingsPtr &settings, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ToPlan),
    m_settings(settings)
{
    ui->setupUi(this);

    plan = new TablePlan(settings);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));

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
    QString text = ui->comboBox_2->currentText();
    QString text1 = ui->comboBox->currentText();


    plan->Update();
    plan->setNGr(text, text1);
    emit newWindow(plan);
}
