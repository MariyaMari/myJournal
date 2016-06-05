#include "settings.h"

Settings::Settings() :
    m_db( &QSqlDatabase::addDatabase( "QSQLITE" ) ) {
    m_db->setDatabaseName( "test.db" );
    m_db->open();
}

Settings::~Settings() {}

const QSqlDatabasePtr   Settings::getDB() const {
    return m_db;
}
