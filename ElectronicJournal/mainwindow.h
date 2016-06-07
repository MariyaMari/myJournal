#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include "spravochniki.h"
#include "worktables.h"
#include "settings.h"
#include "ui_mainwindow.h"
#include "mainform.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow( QWidget * parent = 0 );
    ~MainWindow();

private slots:
    void    on_backButton_clicked();
    void    on_nextButton_clicked();
    void    setWidget( QWidget * widget );

private:
    Ui::MainWindow          m_ui;
    QVector< QWidget * >    m_widgets;
    SettingsPtr             m_settings;
    MainForm                m_mainForm;
    int                     m_currentWidget;

    void    updateButtons();

};

#endif // MAINWINDOW_H
