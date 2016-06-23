#include "mainform.h"

MainForm::MainForm( const SettingsPtr & settings, QWidget * parent ) :
    QWidget( parent ),
    m_spisokSpravochniki( settings ),
    m_spisokWorkTables( settings ),
    m_settings( settings )
{
    m_ui.setupUi( this );

    connect( &m_spisokSpravochniki, SIGNAL( newWindow( QWidget * ) ), this, SIGNAL( newWindow( QWidget * ) ) );
    connect( &m_spisokWorkTables, SIGNAL( newWindow( QWidget * ) ), this, SIGNAL( newWindow( QWidget * ) ) );

    connect( m_ui.pushButton, SIGNAL( clicked() ), this, SLOT( on_pushButton_clicked() ) );
    connect( m_ui.pushButton_2, SIGNAL( clicked() ), this, SLOT( on_pushButton_2_clicked() ) );

//    connectToDatabase();
}

MainForm::~MainForm() {}

/*void MainForm::connectToDatabase()
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
}*/

void MainForm::on_pushButton_clicked()
{
    emit newWindow( &m_spisokSpravochniki );
}

void MainForm::on_pushButton_2_clicked()
{
    emit newWindow( &m_spisokWorkTables );
}

void MainForm::on_pushButton_3_clicked() //Импорт
{
    QSqlDatabase copydb;
    QString idUser;

//    if(importdata(idUser, copydb))
//    {

        QMessageBox::warning(this, "Successfully", "Импортировано");
//    }
//    else
        QMessageBox::warning(this, "Error", "Не удалось импортировать");
}

void MainForm::on_pushButton_4_clicked() //Экспорт
{
    QSqlDatabase copydb;
    QString idUser;

//    if(exportdata(idUser, copydb))
//    {

        QMessageBox::warning(this, "Successfully", "Экспортировано");
//    }
//    else
        QMessageBox::warning(this, "Error", "Не удалось экспортировать");
}




//void MainForm::copydb()
//{
//    QSqlQuery q(db);

//    q.exec("create table disciplina(id_dis integer primary key, n_dis varchar(100) unique);");
//    q.exec("create table facultet(id_fac integer primary key, n_fac varchar(100) unique);");
//    q.exec("create table specialty(id_spec integer primary key, n_spec varchar(100) unique, id_fac integer references facultet(id_fac) on update cascade on delete cascade);");
//    q.exec("create table students(id_st integer primary key, fio varchar(100) unique);");
//    q.exec("create table gruppa(id_gr integer primary key, n_gr varchar(100) unique, _year integer, id_spec integer references specialty(id_spec) on update cascade on delete cascade);");
//    q.exec("create table plan(id_spec integer references specialty(id_spec) on update cascade on delete cascade, id_dis integer references disciplina(id_dis) on update cascade on delete cascade, semes integer, primary key(id_spec, id_dis, semes));");
//    q.exec("create table sostavgr(semes integer, id_gr integer references gruppa(id_gr) on update cascade on delete cascade, id_st integer references students(id_st) on update cascade on delete cascade, primary key(semes, id_gr, id_st));");

//    q.exec("INSERT INTO disciplina SELECT id_dis, n_dis FROM disciplina;");
//}
