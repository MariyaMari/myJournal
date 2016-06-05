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
    discipline->Update();
    emit newWindow(discipline);
}

void Spravochniki::on_pushButton_2_clicked()
{
    specialty->Update();
    emit newWindow(specialty);
}

void Spravochniki::on_pushButton_3_clicked()
{
    typeWorks->Update();
    emit newWindow(typeWorks);
}

void Spravochniki::on_pushButton_4_clicked()
{
    faculty->Update();
    emit newWindow(faculty);
}

void Spravochniki::on_pushButton_5_clicked()
{
    students->Update();
    emit newWindow(students);
}

void Spravochniki::on_pushButton_6_clicked()
{
    group->Update();
    emit newWindow(group);
}
