#include "madeworkmodel.hpp"

MadeWorkModel::MadeWorkModel( QObject * parent ) :
    QAbstractTableModel( parent )
{
    //link2Model.setEditStrategy( QSqlRelationalTableModel::OnManualSubmit );

    //link2Model.setTable( "link2" );
    //link2Model.setRelation( 1, QSqlRelation( "students", "id_st", "fio" ) );
}

void    MadeWorkModel::select()
{
    QString filter;
    if( !m_groupName.isEmpty() )
    {
        filter = " AND link2.id_st=(SELECT sostavgr.id_st FROM sostavgr, gruppa WHERE gruppa.id_gr = sostavgr.id_gr AND gruppa.n_gr=`" + m_groupName + "`) ";
    }

    link2Model.setQuery( "SELECT * FROM link2, students WHERE students.id_st = link2.id_st GROUP BY link2.id_st" );

    studentsModel.setQuery( "SELECT students.fio FROM students, sostavgr, gruppa WHERE students.id_st = sostavgr.id_st AND gruppa.id_gr = sostavgr.id_gr" );

    QVector< int > ids;
    for( int i = 0; i < link2Model.rowCount(); ++i )
    {
        int idLink1 = link2Model.data( link2Model.index( i, 2 ) ).toInt();
        if( !ids.contains( idLink1 ) )
        {
            ids.push_back( idLink1 );
        }
    }

    QMap< int, int > idToIndex;
    for( int i = 0; i < ids.size(); ++i )
    {
        idToIndex[ ids[ i ] ] = i;
    }

    studentWorksModels.clear();
    for( int i = 0; i < link2Model.rowCount(); ++i )
    {
        int id = link2Model.data( link2Model.index( i, 1 ) ).toInt();
        QSqlQueryModel model;
        model.setQuery( "SELECT id_lin1 FROM link2 WHERE id_st = " + QString( "%1" ).arg( id ) );
        for( int j = 0; j < model.rowCount(); ++j )
        {
            int idLink1 = model.data( model.index( j, 0 ) ).toInt();
            studentWorksModels[ id ][ idToIndex[ idLink1 ] ] = true;
        }
    }
}

int    MadeWorkModel::rowCount( const QModelIndex & parent ) const
{
    return studentsModel.rowCount( parent );
}

int    MadeWorkModel::columnCount( const QModelIndex & parent ) const
{
    return studentsModel.columnCount( parent ) + 8;
}

QVariant    MadeWorkModel::data( const QModelIndex & idx, int role ) const
{
    int workNumber = idx.column() - studentsModel.columnCount();
    if ( workNumber >= 0 )
    {
        int id = link2Model.data( link2Model.index( idx.row(), 1 ) ).toInt();
        return studentWorksModels[ id ].contains( workNumber );
    }
    return studentsModel.data( idx, role );
}

QVariant    MadeWorkModel::headerData( int section, Qt::Orientation orientation, int role ) const
{
    int workNumber = section - studentsModel.columnCount();
    if( workNumber >= 0 )
    {
        return QString( "%1" ).arg( workNumber + 1 );
    }
    return studentsModel.headerData( section, orientation, role );
}

bool    MadeWorkModel::setHeaderData( int section, Qt::Orientation orientation, const QVariant & value, int role )
{
    return studentsModel.setHeaderData( section, orientation, value, role );
}

void    MadeWorkModel::setGroupName( const QString & name )
{
    m_groupName = name;
}