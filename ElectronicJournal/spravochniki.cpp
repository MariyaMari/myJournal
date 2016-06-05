#include "spravochniki.h"
#include "ui_spravochniki.h"

#include <QMessageBox>

Spravochniki::Spravochniki( const SettingsPtr & settings, QWidget * parent ) :
    QWidget(parent),
    ui(new Ui::Spravochniki),
    m_settings( settings )
{
    ui->setupUi(this);

    discipline = new FormDiscipline(m_settings);
    //connect(ui->pushButton, SIGNAL(clicked()), discipline, SLOT(show()));
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));

    specialty = new FormSpecialty(m_settings);
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(on_pushButton_2_clicked()));
    connect(specialty, SIGNAL(newWindow(QWidget *)), this, SIGNAL(newWindow(QWidget *)));

    typeWorks = new FormTypeWorks(m_settings);
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(on_pushButton_3_clicked()));

    faculty = new FormFaculty(m_settings);
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(on_pushButton_4_clicked()));

    students = new FormStudents(m_settings);
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(on_pushButton_5_clicked()));

    group = new FormGroup(m_settings);
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(on_pushButton_6_clicked()));
    connect(group, SIGNAL(newWindow(QWidget *)), this, SIGNAL(newWindow(QWidget *)));
}

Spravochniki::~Spravochniki()
{
    delete ui;
}

void Spravochniki::on_pushButton_clicked()
{
    //Setting use
    //int setting1 = m_settings->getSetting1();

    //Setting set
    //m_settings->setSetting1( 1 );

    QSqlTableModel *mod = new QSqlTableModel(0, db);
    mod->setEditStrategy(QSqlTableModel::OnManualSubmit);
    mod->setTable("disciplina");
    mod->select();

    discipline->Init(mod);
    //discipline->show();

    emit newWindow(discipline);
}

void Spravochniki::on_pushButton_2_clicked()
{
    QSqlRelationalTableModel *mod = new QSqlRelationalTableModel(0, db);
    mod->setEditStrategy(QSqlRelationalTableModel::OnManualSubmit);
    mod->setTable("specialty");
    mod->setRelation(2, QSqlRelation("facultet", "id_fac", "n_fac"));
    mod->select();

    specialty->Init(mod);
    //specialty->show();

    emit newWindow(specialty);
}

void Spravochniki::on_pushButton_3_clicked()
{
    QSqlTableModel *mod = new QSqlTableModel(0, db);
    mod->setEditStrategy(QSqlTableModel::OnManualSubmit);
    mod->setTable("typerabot");
    mod->select();

    typeWorks->Init(mod);
    //typeWorks->show();

    emit newWindow(typeWorks);
}

void Spravochniki::on_pushButton_4_clicked()
{
    QSqlTableModel *mod = new QSqlTableModel(0, db);
    mod->setEditStrategy(QSqlTableModel::OnManualSubmit);
    mod->setTable("facultet");
    mod->select();

    faculty->Init(mod);
    //faculty->show();

    emit newWindow(faculty);
}

void Spravochniki::on_pushButton_5_clicked()
{
    QSqlTableModel *mod = new QSqlTableModel(0, db);
    mod->setEditStrategy(QSqlTableModel::OnManualSubmit);
    mod->setTable("students");
    mod->select();

    students->Init(mod);
    //students->show();

    emit newWindow(students);
}

void Spravochniki::on_pushButton_6_clicked()
{
    QSqlRelationalTableModel *mod = new QSqlRelationalTableModel(0, db);
    mod->setEditStrategy(QSqlRelationalTableModel::OnManualSubmit);
    mod->setTable("gruppa");
    mod->setRelation(3, QSqlRelation("specialty", "id_spec", "n_spec"));
    mod->select();

    group->Init(mod);
    //group->show();

    emit newWindow(group);
}
