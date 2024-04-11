#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint | Qt::WindowTitleHint);
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_buttonBox_accepted()
{
    QString jmeno = ui->le_jmeno->text();
    QString heslo = ui->le_heslo->text();

    if(jmeno == "admin" && heslo == "admin"){
        this->done(QDialog::Accepted);
        qDebug() << "Admin prihlasen";
    } else if(jmeno == "user" && heslo == "user"){
        this->done(QDialog::Rejected);
        qDebug() << "User prihlasen";
    } else {
        QMessageBox::critical(this, "Chyba",
                              "Toto neni platna kombinace jmena a hesla",
                              QMessageBox::StandardButton::Ok);
    }

    /* this->done(QDialog::Accepted);*/
}

void Login::on_buttonBox_rejected()
{
    QMessageBox::critical(this, "Chyba",
                          "Toto neni platna kombinace jmena a hesla",
                          QMessageBox::StandardButton::Ok);
    /*this->done(QDialog::Rejected);*/
}
