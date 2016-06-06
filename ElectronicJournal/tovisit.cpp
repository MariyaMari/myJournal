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
    QString text = ui->comboBox_3->currentText();
    QString text1 = ui->comboBox_2->currentText();
    QString text2 = ui->comboBox->currentText();

    visit->setNGr(text, text1, text2);
    visit->Update();
    emit newWindow(visit);
}
