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
    QFile dfile( "assets:/copydb.db" );
    if( dfile.exists() )
    {
        dfile.copy( "./copydb.db" );
        QFile::setPermissions( "./copydb.db", QFile::WriteOwner | QFile::ReadOwner );
    }

    copydb = QSqlDatabase::addDatabase( "QSQLITE", "copy" );
    copydb.setDatabaseName( "copydb.db" );
    if( !copydb.open() )
    {
        QMessageBox::warning( this, tr( "Failed to connect!" ), tr( "Error connecting to database: " )
                              + copydb.lastError().driverText() );
    }
    QSqlQuery query( copydb );
    query.exec( "pragma foreign_keys = 1;" );

    copyDBFunc(m_db, copydb);

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

void MainForm::copyDBFunc(QSqlDatabase src, QSqlDatabase dest)
{
    QSqlQuery query(dest);

    query.exec("drop table Link3");
    query.exec("drop table Link2");
    query.exec("drop table Link1");
    query.exec("drop table Sostavgr");
    query.exec("drop table Plan");
    query.exec("drop table Gruppa");
    //query.exec("drop table Typerabot");
    query.exec("drop table Students");
    query.exec("drop table Specialty");
    query.exec("drop table Disciplina");
    query.exec("drop table Facultet");

    query.exec("create table disciplina(id_dis integer primary key, n_dis varchar(100) unique);"

               "create table facultet(id_fac integer primary key, n_fac varchar(100) unique);"

               "create table specialty(id_spec integer primary key, n_spec varchar(100) unique, id_fac integer references facultet(id_fac) on update cascade on delete cascade);"

               "create table students(id_st integer primary key, fio varchar(100) unique);"

               "create table gruppa(id_gr integer primary key, n_gr varchar(100) unique, _year integer, id_spec integer references specialty(id_spec) on update cascade on delete cascade);"

               "create table plan(id_spec integer references specialty(id_spec) on update cascade on delete cascade, id_dis integer references disciplina(id_dis) on update cascade on delete cascade, semes integer, primary key(id_spec, id_dis, semes));"

               "create table sostavgr(semes integer, id_gr integer references gruppa(id_gr) on update cascade on delete cascade, id_st integer references students(id_st) on update cascade on delete cascade, primary key(semes, id_gr, id_st));");

    QSqlQuery srcQuery(src);

    srcQuery.exec("select * from disciplina");

    while (srcQuery.next())
    {
        query.prepare("insert into disciplina values (?, ?)");

        query.addBindValue(srcQuery.value(0));
        query.addBindValue(srcQuery.value(1));

        query.exec();
    }

    srcQuery.exec("select * from facultet");

    while (srcQuery.next())
    {
        query.prepare("insert into facultet values (?, ?)");

        query.addBindValue(srcQuery.value(0));
        query.addBindValue(srcQuery.value(1));

        query.exec();
    }

    srcQuery.exec("select * from specialty");

    while (srcQuery.next())
    {
        query.prepare("insert into specialty values (?, ?, ?)");

        query.addBindValue(srcQuery.value(0));
        query.addBindValue(srcQuery.value(1));
        query.addBindValue(srcQuery.value(2));

        query.exec();
    }

    srcQuery.exec("select * from students");

    while (srcQuery.next())
    {
        query.prepare("insert into students values (?, ?)");

        query.addBindValue(srcQuery.value(0));
        query.addBindValue(srcQuery.value(1));

        query.exec();
    }

    srcQuery.exec("select * from gruppa");

    while (srcQuery.next())
    {
        query.prepare("insert into gruppa values (?, ?, ?, ?)");

        query.addBindValue(srcQuery.value(0));
        query.addBindValue(srcQuery.value(1));
        query.addBindValue(srcQuery.value(2));
        query.addBindValue(srcQuery.value(3));

        query.exec();
    }

    srcQuery.exec("select * from plan");

    while (srcQuery.next())
    {
        query.prepare("insert into plan values (?, ?, ?)");

        query.addBindValue(srcQuery.value(0));
        query.addBindValue(srcQuery.value(1));
        query.addBindValue(srcQuery.value(2));

        query.exec();
    }

    srcQuery.exec("select * from sostavgr");

    while (srcQuery.next())
    {
        query.prepare("insert into sostavgr values (?, ?, ?)");

        query.addBindValue(srcQuery.value(0));
        query.addBindValue(srcQuery.value(1));
        query.addBindValue(srcQuery.value(2));

        query.exec();
    }
}
