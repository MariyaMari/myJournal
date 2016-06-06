#include "tocompositiongroup.h"
#include "ui_tocompositiongroup.h"

ToCompositionGroup::ToCompositionGroup(const SettingsPtr &settings, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ToCompositionGroup),
    m_settings(settings)
{
    ui->setupUi(this);

    compGrup = new TableCompositionGroup(settings);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));
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
    QString text = ui->comboBox_2->currentText();
    QString text1 = ui->comboBox->currentText();

    compGrup->setNGr(text, text1);
    compGrup->Update();
    emit newWindow(compGrup);
}

