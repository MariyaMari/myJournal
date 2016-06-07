#include "tableplan.h"
#include "ui_tableplan.h"

#include <QMessageBox>

TablePlan::TablePlan(const SettingsPtr &settings, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TablePlan),
    model( this ),
    m_settings(settings)
{
    ui->setupUi(this);

    model.setEditStrategy(QSqlRelationalTableModel::OnManualSubmit);
    model.setTable("plan");
    model.setRelation( 1, QSqlRelation( "disciplina", "id_dis", "n_dis" ) );
    update();

    Init();
}

TablePlan::~TablePlan()
{
    delete ui;
}

void    TablePlan::update()
{
    model.select();
}

void    TablePlan::setFilter( const QString & n_spec, const QString & semes )
{
    viewModel1.setFilterKeyColumn( 2 );
    viewModel1.setFilterFixedString( semes );

    QSqlQuery query( "SELECT id_spec FROM specialty WHERE n_spec='" + n_spec + "'" );
    QString id_spec;
    while( query.next() )
    {
        id_spec = query.value( 0 ).toString();
    }
    viewModel2.setFilterKeyColumn( 0 );
    viewModel2.setFilterFixedString( id_spec );
}

void TablePlan::Init()
{
    viewModel1.setSourceModel( &model );
    viewModel2.setSourceModel( &viewModel1 );
    ui->tableView->setModel( &viewModel2 );
    ui->tableView->setColumnHidden(0, true);
    ui->tableView->setColumnHidden(2, true);
    ui->tableView->show();
    model.setHeaderData(1, Qt::Horizontal, "Название Дисциплины");

    QHeaderView *pHW = ui->tableView->horizontalHeader(); //Нормальный размер колонок
    int count = pHW->count();
    for (int i = 0; i < count; i++)
        pHW->setSectionResizeMode(i,QHeaderView::ResizeToContents);
}

void TablePlan::on_pushButton_clicked() //Удалить
{
    model.removeRow(ui->tableView->currentIndex().row());
}

void TablePlan::on_pushButton_2_clicked() //Добавить
{

}

void TablePlan::on_pushButton_3_clicked() //Подтвердить
{
    if(!model.submitAll())
        QMessageBox::warning(this, "Error", model.lastError().text());
    model.select();
}
