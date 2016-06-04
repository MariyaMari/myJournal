#pragma once
#ifndef SETTINGS_HPP
#define SETTINGS_HPP
#include <QSharedPointer>

/*! @~russian
@brief Класс, реализующий настройки программы

Класс, реализующий настройки программы
*/
class Settings {

public:
    Settings();
    ~Settings();

    int     getSetting1() const;
    void    setSetting1( int newValue );

private:
    int     m_setting1;

};
typedef QSharedPointer< Settings > SettingsPtr;

#endif // SETTINGS_HPP
