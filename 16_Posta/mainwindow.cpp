#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    fronta = new Fronta();
    z_prepazka1 = new Zasobnik();
    z_prepazka2 = new Zasobnik();
    z_prepazka3 = new Zasobnik();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete fronta;
    delete z_prepazka1;
    delete z_prepazka2;
    delete z_prepazka3;
}

// osoba, ktera je zadana v textovem poli se prida do Fronty
void MainWindow::on_btn_pridej_clicked()
{
    QString jmeno = ui->le_pridej->text();
    Osoba * os = new Osoba();
    os->jmeno = jmeno;
    fronta->pridej(os);
    ui->te_fronta->setText(fronta->toString());
}

void MainWindow::on_btn_prepazka1_clicked()
{
    Osoba * os = fronta->odeber();
    if(os == NULL){
        QMessageBox::warning(this, "Varovani",
                             "Nelze presunout osobu k prepazce, protoze nikdo ve fronte neni.");
    }
    ui->te_fronta->setText(fronta->toString()); // aktualizace grafiky
    z_prepazka1->push(os);
    ui->te_prepazka1->setText(z_prepazka1->toString());
}

void MainWindow::on_btn_prepazka2_clicked()
{
    Osoba * os = fronta->odeber();
    if(os == NULL){
        QMessageBox::warning(this, "Varovani",
                             "Nelze presunout osobu k prepazce, protoze nikdo ve fronte neni.");
    }
    ui->te_fronta->setText(fronta->toString()); // aktualizace grafiky
    z_prepazka2->push(os);
    ui->te_prepazka2->setText(z_prepazka2->toString());
}

void MainWindow::on_btn_prepazka3_clicked()
{
    Osoba * os = fronta->odeber();
    if(os == NULL){
        QMessageBox::warning(this, "Varovani",
                             "Nelze presunout osobu k prepazce, protoze nikdo ve fronte neni.");
    }
    ui->te_fronta->setText(fronta->toString()); // aktualizace grafiky
    z_prepazka3->push(os);
    ui->te_prepazka3->setText(z_prepazka3->toString());
}

void MainWindow::on_le_pridej_returnPressed()
{
    QString jmeno = ui->le_pridej->text();
    Osoba * os = new Osoba();
    os->jmeno = jmeno;
    fronta->pridej(os);
    ui->te_fronta->setText(fronta->toString());
}
