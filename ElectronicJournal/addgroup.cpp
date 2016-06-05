#include "addgroup.h"
#include "ui_addgroup.h"

#include <QMessageBox>

AddGroup::AddGroup(const SettingsPtr &settings, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddGroup)
{
    ui->setupUi(this);
}

AddGroup::~AddGroup()
{
    delete ui;
}

void AddGroup::Init(QSqlQueryModel *mod1, QSqlDatabase &db)
{
    this->db = &db;
    ui->comboBox->setModel(mod1);
}

void AddGroup::closeEvent(QCloseEvent *e)
{
    emit Closed();
    QWidget::closeEvent(e);
}

void AddGroup::on_pushButton_clicked()
{
    if(ui->lineEdit->text() == "" || ui->lineEdit_2->text() == "" )
    {
        QMessageBox::warning(this, "Error", "All values must be filled");//вcе значения должны быть заполнены
        return;
    }

    QSqlQueryModel *potModel = new QSqlQueryModel();
    potModel->setQuery("select id_spec from specialty where n_spec = '" + ui->comboBox->currentText() + "';", *db);

    QString pot = potModel->record(0).field(0).value().toString();

    QString query = "insert into gruppa (n_gr, _year, id_spec) values ('" + ui->lineEdit->text() + "', " + ui->lineEdit_2->text()
            + ", " + pot + ");";

    emit InsertQuery(query);
}

void AddGroup::on_pushButton_2_clicked()
{
    emit Closed();
    this->close();
}
