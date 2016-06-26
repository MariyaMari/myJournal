#pragma once
#include <QtSql>
#include <QVariant>
#include <QMap>
#include <QAbstractTableModel>

class MadeWorkModel : public QAbstractTableModel {
    Q_OBJECT

public:
    MadeWorkModel( QObject * parent = Q_NULLPTR );

    int         rowCount( const QModelIndex & parent = class QModelIndex() ) const;
    int         columnCount( const QModelIndex & parent = class QModelIndex() ) const;
    QVariant    data( const QModelIndex & idx, int role = 0 ) const;
    QVariant    headerData( int section, Qt::Orientation orientation, int role = 0 ) const;
    bool        setHeaderData( int section, Qt::Orientation orientation, const QVariant & value, int role = 2 );

    void        setGroupName( const QString & name );

public slots:
    void        select();

private:
    QString                             m_groupName;
    QSqlQueryModel                      studentsModel;
    QSqlQueryModel                      link2Model;
    QMap< int, QMap< int, bool > >      studentWorksModels;

};
