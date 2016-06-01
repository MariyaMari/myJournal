#include "settings.hpp"

Settings::Settings() : 
    m_setting1( 0 /* Default value */ ) {}

Settings::~Settings() {}

int     Settings::getSetting1() const {
    return m_setting1;
}

void Settings::setSetting1( int newValue )
{
    m_setting1 = newValue;
}
