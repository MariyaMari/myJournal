#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <QString>
#include <QtSql>

class functions
{
public:
    bool importdata(QString iduser, QSqlDatabase &copydb);
    bool exportdata(QString iduser, QSqlDatabase &copydb);
};

#endif // FUNCTIONS_H
