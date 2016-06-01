#include "mainform.h"
#include "ui_mainform.h"

MainForm::MainForm(QWidget *parent) :
    QMainWindow(parent),
    m_settings( new Settings() )
{
    m_ui.setupUi(this);

    spisokSpravochniki = new Spravochniki( /*m_settings*/ );
    connect(m_ui.pushButton, SIGNAL(clicked()), spisokSpravochniki, SLOT(show()));

    spisokWorkTables = new WorkTables();
    connect(m_ui.pushButton_2, SIGNAL(clicked()), spisokWorkTables, SLOT(show()));

    ConnectToDataBase();

}

MainForm::~MainForm() {}

void MainForm::ConnectToDataBase()
{
  /*  spisokSpravochniki->db = QSqlDatabase::addDatabase("QSQLITE");
    spisokSpravochniki->db.setDatabaseName("test.db");
    spisokSpravochniki->db.open();

    if(!spisokSpravochniki->db.open())
    {
       qDebug() << "Cannot open database:" << spisokSpravochniki->db.lastError().text();
    }
    //spisokSpravochniki->show();
    QSqlQuery query(spisokSpravochniki->db);
    query.exec("pragma foreign_keys = 1;");*/

/*    spisokWorkTables->db = QSqlDatabase::addDatabase("QSQLITE");
    spisokWorkTables->db.setDatabaseName("test.db");
    spisokWorkTables->db.open();

    if(!spisokWorkTables->db.open())
    {
       qDebug() << "Cannot open database:" << spisokWorkTables->db.lastError().text();
    }
    //spisokSpravochniki->show();
    QSqlQuery query(spisokWorkTables->db);
    query.exec("pragma foreign_keys = 1;");

*/
/*    QFile dfile("assets:/test.db");
    if (dfile.exists())
    {
         dfile.copy("./test.db");
         QFile::setPermissions("./test.db",QFile::WriteOwner | QFile::ReadOwner);
    }

    spisokWorkTables->db = QSqlDatabase::addDatabase( "QSQLITE","MyConnection" );
    spisokWorkTables->db.setDatabaseName( "test.db" );
    if(!spisokWorkTables->db.open())
    {
        QMessageBox::warning(this, tr("Failed to connect!"), tr("Error connecting to database: ")
                             + spisokWorkTables->db.lastError().driverText() );
    }
    QSqlQuery query(spisokWorkTables->db);
    query.exec("pragma foreign_keys = 1;");*/


    QFile dfile("assets:/test.db");
    if (dfile.exists())
    {
         dfile.copy("./test.db");
         QFile::setPermissions("./test.db",QFile::WriteOwner | QFile::ReadOwner);
    }

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName( "test.db" );
    if(!db.open())
    {
        QMessageBox::warning(this, tr("Failed to connect!"), tr("Error connecting to database: ")
                             + db.lastError().driverText() );
    }
    QSqlQuery query(db);
    query.exec("pragma foreign_keys = 1;");
}

void MainForm::on_pushButton_clicked()
{

}

void MainForm::on_pushButton_2_clicked()
{

}
