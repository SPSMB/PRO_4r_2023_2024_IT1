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

