#include "spravochniki.h"
#include "ui_spravochniki.h"

#include <QMessageBox>

Spravochniki::Spravochniki( const SettingsPtr & settings, QWidget * parent ) :
    QWidget(parent),
    ui(new Ui::Spravochniki),
    m_settings( settings )
{
    ui->setupUi(this);

    discipline = new FormDiscipline();
    connect(ui->pushButton, SIGNAL(clicked()), discipline, SLOT(show()));

    specialty = new FormSpecialty();
    connect(ui->pushButton_2, SIGNAL(clicked()), specialty, SLOT(show()));

    typeWorks = new FormTypeWorks();
    connect(ui->pushButton_3, SIGNAL(clicked()), typeWorks, SLOT(show()));

    faculty = new FormFaculty();
    connect(ui->pushButton_4, SIGNAL(clicked()), faculty, SLOT(show()));

    students = new FormStudents();
    connect(ui->pushButton_5, SIGNAL(clicked()), students, SLOT(show()));

    group = new FormGroup();
    connect(ui->pushButton_6, SIGNAL(clicked()), group, SLOT(show()));
}

Spravochniki::~Spravochniki()
{
    delete ui;
}

void Spravochniki::on_pushButton_clicked()
{
    //Setting use
    int setting1 = m_settings->getSetting1();

    //Setting set
    m_settings->setSetting1( 1 );

    QSqlTableModel *mod = new QSqlTableModel(0, db);
    mod->setEditStrategy(QSqlTableModel::OnManualSubmit);
    mod->setTable("disciplina");
    mod->select();

    discipline->Init(mod);
    discipline->show();
}

void Spravochniki::on_pushButton_2_clicked()
{
    QSqlTableModel *mod = new QSqlTableModel(0, db);
    mod->setEditStrategy(QSqlTableModel::OnManualSubmit);
    mod->setTable("specialty");
    mod->select();

    specialty->Init(mod);
    specialty->show();
}

void Spravochniki::on_pushButton_3_clicked()
{
    QSqlTableModel *mod = new QSqlTableModel(0, db);
    mod->setEditStrategy(QSqlTableModel::OnManualSubmit);
    mod->setTable("typerabot");
    mod->select();

    typeWorks->Init(mod);
    typeWorks->show();
}

void Spravochniki::on_pushButton_4_clicked()
{
    QSqlTableModel *mod = new QSqlTableModel(0, db);
    mod->setEditStrategy(QSqlTableModel::OnManualSubmit);
    mod->setTable("facultet");
    mod->select();

    faculty->Init(mod);
    faculty->show();
}

void Spravochniki::on_pushButton_5_clicked()
{
    QSqlTableModel *mod = new QSqlTableModel(0, db);
    mod->setEditStrategy(QSqlTableModel::OnManualSubmit);
    mod->setTable("students");
    mod->select();

    students->Init(mod);
    students->show();
}

void Spravochniki::on_pushButton_6_clicked()
{
    QSqlTableModel *mod = new QSqlTableModel(0, db);
    mod->setEditStrategy(QSqlTableModel::OnManualSubmit);
    mod->setTable("gruppa");
    mod->select();

    group->Init(mod);
    group->show();
}
