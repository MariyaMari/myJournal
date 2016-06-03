#pragma once
#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>
#include <QSqlDatabase>
#include "spravochniki.h"
#include "worktables.h"
#include "settings.h"
#include "ui_mainform.h"

class MainForm : public QWidget
{
    Q_OBJECT

public:
    explicit MainForm( const SettingsPtr & settings, QWidget * parent = 0 );
    ~MainForm();

    void connectToDatabase();

    private slots:
    void    on_pushButton_clicked();
    void    on_pushButton_2_clicked();

private:
    Ui::MainForm    m_ui;
    QSqlDatabase    m_db;
    Spravochniki    m_spisokSpravochniki;
    WorkTables      m_spisokWorkTables;
    SettingsPtr     m_settings;

signals:
    void    newWindow( QWidget * widget );

};

#endif // MAINFORM_H
