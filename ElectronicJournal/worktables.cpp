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
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));
    connect(toPlan, SIGNAL(newWindow(QWidget *)), this, SIGNAL(newWindow(QWidget *)));

    toCompGroup = new ToCompositionGroup(settings);
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(on_pushButton_2_clicked()));
    connect(toCompGroup, SIGNAL(newWindow(QWidget *)), this, SIGNAL(newWindow(QWidget *)));

    toVisit = new ToVisit(settings);
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(on_pushButton_3_clicked()));
    connect(toVisit, SIGNAL(newWindow(QWidget *)), this, SIGNAL(newWindow(QWidget *)));

    tolistWorks = new ToListWorks(settings);
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(on_pushButton_4_clicked()));
    connect(tolistWorks, SIGNAL(newWindow(QWidget *)), this, SIGNAL(newWindow(QWidget *)));

    toMadeWorks = new ToMadeWorks(settings);
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(on_pushButton_5_clicked()));
    connect(toMadeWorks, SIGNAL(newWindow(QWidget *)), this, SIGNAL(newWindow(QWidget *)));
}

WorkTables::~WorkTables()
{
    delete ui;
}

void WorkTables::on_pushButton_clicked()
{
    QSqlQueryModel *mod1 = new QSqlQueryModel();
//    mod1->setQuery("select semes from plan GROUP BY semes;");

    QSqlQueryModel *mod2 = new QSqlQueryModel();
    mod2->setQuery("select n_spec from specialty;");

    toPlan->Init(mod1, mod2);

    emit newWindow(toPlan);
}

void WorkTables::on_pushButton_2_clicked()
{
    QSqlQueryModel *mod1 = new QSqlQueryModel();
//    mod1->setQuery("select semes from sostavgr GROUP BY semes;");

    QSqlQueryModel *mod2 = new QSqlQueryModel();
    mod2->setQuery("select n_gr from gruppa;");

    toCompGroup->Init(mod1, mod2);

    emit newWindow(toCompGroup);
}

void WorkTables::on_pushButton_3_clicked()
{
    QSqlQueryModel *mod1 = new QSqlQueryModel();
    mod1->setQuery("select data from link3 GROUP BY data;");

    QSqlQueryModel *mod2 = new QSqlQueryModel();
    mod2->setQuery("select n_dis from disciplina;");

    QSqlQueryModel *mod3 = new QSqlQueryModel();
    mod3->setQuery("select n_trab from typerabot;");

    QSqlQueryModel *mod4 = new QSqlQueryModel();
    mod4->setQuery("select n_gr from gruppa;");

    toVisit->Init(mod1, mod2, mod3, mod4);

    emit newWindow(toVisit);
}

void WorkTables::on_pushButton_4_clicked()
{
    QSqlQueryModel *mod1 = new QSqlQueryModel();
//    mod1->setQuery("select semes from link1 GROUP BY semes;");

    QSqlQueryModel *mod2 = new QSqlQueryModel();
    mod2->setQuery("select n_spec from specialty;");

    QSqlQueryModel *mod3 = new QSqlQueryModel();
    mod3->setQuery("select n_dis from disciplina;");

    QSqlQueryModel *mod4 = new QSqlQueryModel();
    mod4->setQuery("select n_trab from typerabot;");

    tolistWorks->Init(mod1, mod2, mod3, mod4);

    emit newWindow(tolistWorks);
}

void WorkTables::on_pushButton_5_clicked()
{
    QSqlQueryModel *mod1 = new QSqlQueryModel();
    mod1->setQuery("select data from link2 GROUP BY data;");

    QSqlQueryModel *mod2 = new QSqlQueryModel();
    mod2->setQuery("select n_gr from gruppa;");

    QSqlQueryModel *mod3 = new QSqlQueryModel();
    mod3->setQuery("select n_dis from disciplina;");

    QSqlQueryModel *mod4 = new QSqlQueryModel();
    mod4->setQuery("select n_trab from typerabot;");

    toMadeWorks->Init(mod1, mod2, mod3, mod4);

    emit newWindow(toMadeWorks);
}
