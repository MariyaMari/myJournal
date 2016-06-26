#include "mainwindow.h"

MainWindow::MainWindow( QWidget * parent ) :
    QWidget( parent ),
    m_settings( new Settings() ),
    m_mainForm( m_settings, this ),
    m_currentWidget( -1 )
{
    m_ui.setupUi( this );

    connect( m_ui.backButton, SIGNAL( clicked() ), this, SLOT( on_backButton_clicked() ) );
    connect( m_ui.nextButton, SIGNAL( clicked() ), this, SLOT( on_nextButton_clicked() ) );
    connect( &m_mainForm, &MainForm::newWindow, this, &MainWindow::setWidget );

    setWidget( &m_mainForm );
}

MainWindow::~MainWindow() {}

void    MainWindow::updateButtons()
{
    m_ui.backButton->setEnabled( m_currentWidget > 0 );
    m_ui.nextButton->setEnabled( m_currentWidget < m_widgets.size() - 1 );
}

void    MainWindow::on_backButton_clicked()
{
    if( m_currentWidget <= 0 )
    {
        return;
    }

    --m_currentWidget;

    QWidget * widget = m_widgets.value( m_currentWidget );
    m_ui.dockWidget->setWidget( widget );
    updateButtons();
}

void    MainWindow::on_nextButton_clicked()
{
    if( m_currentWidget >= m_widgets.size() - 1 )
    {
        return;
    }

    ++m_currentWidget;

    QWidget * widget = m_widgets.value( m_currentWidget );
    m_ui.dockWidget->setWidget( widget );
    updateButtons();
}

void    MainWindow::setWidget( QWidget * widget )
{
    if( m_widgets.contains( widget ) )
    {
        //m_widgets.removeAll( widget );
    }

    m_widgets.push_back( widget );
    ++m_currentWidget;
    m_ui.dockWidget->setWidget( widget );
    updateButtons();
}
