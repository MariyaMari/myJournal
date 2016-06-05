#pragma once
#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include <QSharedPointer>
#include <QSqlDatabase>

typedef QSharedPointer< QSqlDatabase > QSqlDatabasePtr;

/*! @~russian
@brief Класс, реализующий настройки программы

Класс, реализующий настройки программы
*/
class Settings {

public:
    Settings();
    ~Settings();

    const QSqlDatabasePtr getDB() const;

private:
    QSqlDatabasePtr m_db;

};
typedef QSharedPointer< Settings > SettingsPtr;

#endif // SETTINGS_HPP
