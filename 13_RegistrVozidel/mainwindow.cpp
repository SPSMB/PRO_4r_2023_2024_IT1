#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->registr->addItem(QString("Skoda Superb"));

    for(int i = 0; i < 10; i++){
        ui->registr->addItem(QString::number(i) + ". auto");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_registr_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    // kontrola, ze polozka existuje
    if(current != NULL){
        QString text = current->text();
        ui->label_vyber->setText(text);
    } else {
        ui->label_vyber->setText(QString("Seznam je prazdny"));
    }

}

void MainWindow::on_btn_odstranit_clicked()
{
    // 1. najdeme text/polozku, ktery chceme vymazat
    /*QListWidgetItem * polozkaKOdstraneni
            = ui->registr->currentItem();*/
    int cisloRadku = ui->registr->currentRow();
    qDebug() << "Cislo radku: " << cisloRadku;
    // 2. odstranime ze seznamu
    ui->registr->takeItem(cisloRadku);
}
