#include "worktables.h"
#include "ui_worktables.h"

#include <QMessageBox>

WorkTables::WorkTables(const SettingsPtr &settings, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WorkTables),
    m_settings(settings)
{
    ui->setupUi(this);

    toPlan = new ToPlan(settings);
    connect(ui->pushButton, SIGNAL(clicked()), toPlan, SLOT(on_pushButton_clicked()));

    toCompGroup = new ToCompositionGroup(settings);
    connect(ui->pushButton_2, SIGNAL(clicked()), toCompGroup, SLOT(show()));

    toVisit = new ToVisit(settings);
    connect(ui->pushButton_3, SIGNAL(clicked()), toVisit, SLOT(show()));

    tolistWorks = new ToListWorks(settings);
    connect(ui->pushButton_4, SIGNAL(clicked()), tolistWorks, SLOT(show()));

    toMadeWorks = new ToMadeWorks(settings);
    connect(ui->pushButton_5, SIGNAL(clicked()), toMadeWorks, SLOT(show()));
}

WorkTables::~WorkTables()
{
    delete ui;
}

void WorkTables::on_pushButton_clicked()
{
    QSqlQueryModel *mod1 = new QSqlQueryModel();
    mod1->setQuery("select semes from plan;");

    QSqlQueryModel *mod2 = new QSqlQueryModel();
    mod2->setQuery("select n_spec from specialty;");

    toPlan->Init(mod1, mod2);
    //toPlan->show();

    emit newWindow(toPlan);
}

void WorkTables::on_pushButton_2_clicked()
{
    QSqlQueryModel *mod1 = new QSqlQueryModel();
    mod1->setQuery("select semes from sostavgr;");

    QSqlQueryModel *mod2 = new QSqlQueryModel();
    mod2->setQuery("select n_gr from gruppa;");

    toCompGroup->Init(mod1, mod2);
    toCompGroup->show();
}

void WorkTables::on_pushButton_3_clicked()
{
    QSqlQueryModel *mod1 = new QSqlQueryModel();
    mod1->setQuery("select data from link3;");

    QSqlQueryModel *mod2 = new QSqlQueryModel();
    mod2->setQuery("select n_dis from disciplina;");

    QSqlQueryModel *mod3 = new QSqlQueryModel();
    mod3->setQuery("select n_trab from typerabot;");

    toVisit->Init(mod1, mod2, mod3);
    toVisit->show();
}

void WorkTables::on_pushButton_4_clicked()
{
    QSqlQueryModel *mod1 = new QSqlQueryModel();
    mod1->setQuery("select semes from link1;");

    QSqlQueryModel *mod2 = new QSqlQueryModel();
    mod2->setQuery("select n_spec from specialty;");

    QSqlQueryModel *mod3 = new QSqlQueryModel();
    mod3->setQuery("select n_dis from disciplina;");

    QSqlQueryModel *mod4 = new QSqlQueryModel();
    mod4->setQuery("select n_trab from typerabot;");

    tolistWorks->Init(mod1, mod2, mod3, mod4);
    tolistWorks->show();
}

void WorkTables::on_pushButton_5_clicked()
{
    QSqlQueryModel *mod1 = new QSqlQueryModel();
    mod1->setQuery("select data from link2;");

    QSqlQueryModel *mod2 = new QSqlQueryModel();
    mod2->setQuery("select n_gr from gruppa;");

    QSqlQueryModel *mod3 = new QSqlQueryModel();
    mod3->setQuery("select n_dis from disciplina;");

    QSqlQueryModel *mod4 = new QSqlQueryModel();
    mod4->setQuery("select n_trab from typerabot;");

    toMadeWorks->Init(mod1, mod2, mod3, mod4);
    toMadeWorks->show();
}
