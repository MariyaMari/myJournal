#ifndef MAINFORM_H
#define MAINFORM_H

#include <QMainWindow>
#include <QtSql>
#include "spravochniki.h"
#include "worktables.h"
#include "settings.hpp"
#include "ui_mainform.h"

class MainForm : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainForm(QWidget *parent = 0);
    ~MainForm();

    QSqlDatabase db;

    void ConnectToDataBase();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainForm		m_ui;

    Spravochniki *spisokSpravochniki;
    WorkTables *spisokWorkTables;
    SettingsPtr     m_settings;

};

#endif // MAINFORM_H
