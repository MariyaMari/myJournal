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
    QString text = ui->comboBox_2->currentText();
    QString text1 = ui->comboBox->currentText();

    madeWorks->setNGr(text, text1);
    madeWorks->Update();
    emit newWindow(madeWorks);
}
