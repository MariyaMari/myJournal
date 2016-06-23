#include "tolistworks.h"
#include "ui_tolistworks.h"

ToListWorks::ToListWorks(const SettingsPtr &settings, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ToListWorks),
    m_settings(settings)
{
    ui->setupUi(this);

    listWorks = new TableListWorks(settings);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));
    connect(listWorks, SIGNAL(newWindow(QWidget *)), this, SIGNAL(newWindow(QWidget *)));
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
    QString text = ui->comboBox_4->currentText();
    QString text1 = ui->comboBox_3->currentText();
    QString text2 = ui->comboBox_2->currentText();
    QString text3 = ui->comboBox->currentText();

    listWorks->setNGr(text, text1, text2, text3);
    listWorks->update();
    emit newWindow(listWorks);
}
