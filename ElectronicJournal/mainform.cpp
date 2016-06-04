#include "mainform.h"

MainForm::MainForm( const SettingsPtr & settings, QWidget * parent ) :
    QWidget( parent ),
    m_spisokSpravochniki( settings ),
    m_spisokWorkTables( settings ),
    m_settings( settings )
{
    m_ui.setupUi( this );

    //spisokSpravochniki = new Spravochniki( m_settings );
    //connect(m_ui.pushButton, SIGNAL(clicked()), spisokSpravochniki, SLOT(show()));

    //spisokWorkTables = new WorkTables( m_settings );
    //connect(m_ui.pushButton_2, SIGNAL(clicked()), spisokWorkTables, SLOT(show()));

    connect( &m_spisokSpravochniki, SIGNAL( newWindow( QWidget * ) ), this, SIGNAL( newWindow( QWidget * ) ) );
    connect( &m_spisokWorkTables, SIGNAL( newWindow( QWidget * ) ), this, SIGNAL( newWindow( QWidget * ) ) );

    connect( m_ui.pushButton, SIGNAL( clicked() ), this, SLOT( on_pushButton_clicked() ) );
    connect( m_ui.pushButton_2, SIGNAL( clicked() ), this, SLOT( on_pushButton_2_clicked() ) );

    connectToDatabase();
}

MainForm::~MainForm() {}

void MainForm::connectToDatabase()
{
    QFile dfile( "assets:/test.db" );
    if( dfile.exists() )
    {
        dfile.copy( "./test.db" );
        QFile::setPermissions( "./test.db", QFile::WriteOwner | QFile::ReadOwner );
    }

    m_db = QSqlDatabase::addDatabase( "QSQLITE" );
    m_db.setDatabaseName( "test.db" );
    if( !m_db.open() )
    {
        QMessageBox::warning( this, tr( "Failed to connect!" ), tr( "Error connecting to database: " )
                              + m_db.lastError().driverText() );
    }
    QSqlQuery query( m_db );
    query.exec( "pragma foreign_keys = 1;" );
}

void MainForm::on_pushButton_clicked()
{
    emit newWindow( &m_spisokSpravochniki );
}

void MainForm::on_pushButton_2_clicked()
{
    emit newWindow( &m_spisokWorkTables );
}
