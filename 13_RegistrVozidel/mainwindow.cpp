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

void MainWindow::on_btn_rename_clicked()
{

    // 1. krok - zjistim text
    QString text = QInputDialog::getText(this, "Prejmenovat", "Prosim zadejte novy nazev");
    bool nastavit = false;

    // 2. krok - zjistim spravnou polozku v seznamu
    QListWidgetItem * polozka = ui->registr->currentItem();
    if(text.length() != 0)
    {
        // kontrola delky
        if(text.length() > 20){
            QMessageBox::critical(this, "Varovani", "Moc dlouhy text, nic se nestane.");
        } else if (text.length() > 10){
            QMessageBox::warning(this, "Upozorneni", "Text je delsi nez 10 znaku.");
            nastavit = true;
        } else { // 0 - 10 znaku - vzdy nastavim
            nastavit = true;
        }

        // kontrola lomitek
        if(nastavit && ( text.contains("\\") || text.contains("/")) ){
            QMessageBox::StandardButton odpoved = QMessageBox::question(
                        this, "Otazka", "Skutecne chcete prejmenovat, kdyz obsahuje lomitko?");
            if(odpoved == QMessageBox::Yes){
                nastavit = true;
            } else {
                nastavit = false;
            }
        }

        // az tady to opravud prejmenuji
        if(nastavit) polozka->setText(text);
    }
    else{

        QMessageBox::information(this, "chyba", "Vstupni pole zustalo prazdne! ");
        QMessageBox::StandardButton odpoved = QMessageBox::question(
                    this, "Dotaz", "Chcete skutecne prejmenovat?");
        if(odpoved == QMessageBox::Yes){
           polozka->setText(text);
        }
    }

}

void MainWindow::on_btn_add_clicked()
{
    QString text = ui->le_add->text();
    int cisloRadku = ui->registr->currentRow();
    if(! text.isEmpty()){
        QListWidgetItem * novaPolozka = new QListWidgetItem(text);
        ui->registr->insertItem(cisloRadku, novaPolozka);
    } else {
        QMessageBox::critical(this, "Varovani", "Nelze pridat polozku bez jmena.");
    }
}
