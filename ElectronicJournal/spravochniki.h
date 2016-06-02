#ifndef SPRAVOCHNIKI_H
#define SPRAVOCHNIKI_H

#include <QWidget>
#include <QtSql>
#include <QMessageBox>
#include <formdiscipline.h>
#include <formspecialty.h>
#include <formtypeworks.h>
#include <formfaculty.h>
#include <formstudents.h>
#include <formgroup.h>
#include "settings.h"

namespace Ui {
class Spravochniki;
}

class Spravochniki : public QWidget
{
    Q_OBJECT

public:
    explicit Spravochniki( const SettingsPtr & settings, QWidget * parent = 0 );
    ~Spravochniki();

    QSqlDatabase db;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::Spravochniki *ui;

    FormDiscipline *discipline;
    FormSpecialty *specialty;
    FormTypeWorks *typeWorks;
    FormFaculty *faculty;
    FormStudents *students;
    FormGroup *group;

    SettingsPtr m_settings;

};

#endif // SPRAVOCHNIKI_H
