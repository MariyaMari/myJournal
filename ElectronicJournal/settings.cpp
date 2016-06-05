#include "settings.h"
#include <QFile>
#include <QMessageBox>

Settings::Settings() :
    m_db( new QSqlDatabase() )
{
    QFile dfile( "assets:/test.db" );
    if( dfile.exists() )
    {
        dfile.copy( "./test.db" );
        QFile::setPermissions( "./test.db", QFile::WriteOwner | QFile::ReadOwner );
    }

    *m_db = QSqlDatabase::addDatabase( "QSQLITE" );
    m_db->setDatabaseName( "test.db" );
    m_db->open();

//    if( !m_db->open() )
//    {
//        QMessageBox::warning( this, tr( "Failed to connect!" ), tr( "Error connecting to database: " )
//                              + m_db->lastError().driverText() );
//    }
//    QSqlQuery query( m_db );
//    query.exec( "pragma foreign_keys = 1;" );
}

Settings::~Settings() {}

const QSqlDatabasePtr Settings::getDB() const {
    return m_db;
}
