#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int btn;
    // 1. pristup
    /*
    btn = QMessageBox::question(this, "Titulek",
                          "Jaky je dnes den?",
                          QMessageBox::StandardButton::Ok,
                          QMessageBox::StandardButton::Cancel);
    */

    // 2. pristup
    QIcon i1 = QIcon("E:\\SPSMB\\PRO\\2r\\src\\2023_4r_IT1\\19_Dialogy_1\\spsmb.jpg");
    QPixmap pix = i1.pixmap(150,150);
    QMessageBox msg1;
    msg1.setWindowTitle("Titulek");
    msg1.setText("Jaky je dnes den?");
    // msg1.setIcon(QMessageBox::Critical); // vyber jen z predvolenych standardnich ikon
    msg1.setIconPixmap(pix);
    msg1.addButton(QMessageBox::StandardButton::Ok);
    msg1.addButton(QMessageBox::StandardButton::Cancel);
    msg1.addButton(QMessageBox::StandardButton::Help);

    // vyrobim vlastni button

    msg1.addButton("Pondeli", QMessageBox::YesRole);

    msg1.setDefaultButton(QMessageBox::StandardButton::Cancel);
    btn = msg1.exec(); // vyvolani dialogu

    QString odpoved = "Uzivatel stiskl " + QString::number(btn);
    if(btn == QMessageBox::Ok){
         QMessageBox::information(this, "Odpoved", "Uzivatel stisknul OK");
    } else {
        QMessageBox::information(this, "Odpoved", odpoved);
    }




}

MainWindow::~MainWindow()
{
    delete ui;
}

