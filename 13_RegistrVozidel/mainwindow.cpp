#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QIcon a = QIcon("../img/car2.png");
    ui->registr->setIconSize(QSize(50,50));
    QListWidgetItem * i1 = new QListWidgetItem(a, QString("Skoda Superb"));
    ui->registr->addItem(i1);
    addItem(ui->registr, QString("Skoda Superb"));

    for(int i = 0; i < 10;){
        addItem(ui->registr, QString::number(i) + ". auto");
        addItem(ui->registr2, QString::number(i) + ". auto");
        i++;
        //ui->registr->addItem(QString::number(i) + ". auto");
    }

    QString style = "QListWidget::item:selected{\
                        color: rgb(0,0,0);\
                        background-color: yellow;\
                     }";
    ui->registr->setStyleSheet(style);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addItem(QListWidget *list, QListWidgetItem *item)
{
    // defaultni ikona
    QIcon ico = QIcon("../img/car1.png");
    item->setIcon(ico);
    list->addItem(item);
}

void MainWindow::addItem(QListWidget *list, QString itemString)
{
    // defaultni ikona
    QIcon ico = QIcon("../img/car1.png");
    QListWidgetItem * item = new QListWidgetItem(itemString);
    item->setIcon(ico);
    list->addItem(item);
}


void MainWindow::on_registr_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    // kontrola shodnych nazvu s registrem 2
    kontrolujShodu();

    // kontrola, ze polozka existuje
    if(current != NULL){
        QString text = current->text();
        ui->label_vyber->setText(text);
        int w = ui->l_image->width();
        int h = ui->l_image->height();
        QPixmap p = current->icon().pixmap(w, h);
        ui->l_image->setPixmap(p.scaled(w, h, Qt::KeepAspectRatio));
        // barvicky
        //current->setBackground(Qt::yellow);
        //current->setForeground(Qt::black);
    } else {
        ui->label_vyber->setText(QString("Seznam je prazdny"));
    }

    if(previous != NULL){
        // barvicky
        //previous->setBackground(Qt::white);
        //previous->setForeground(Qt::black);
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
        // tady ziskame cetu k ikone od uzivatele
        QString path = QFileDialog::getOpenFileName(this,
                       "Vyberte obrazek", "C:\\Users\\Tom\\Pictures");
        qDebug() << "Ikona: " << path;
        QIcon i = QIcon(path);
        novaPolozka->setIcon(i);
        novaPolozka->setSizeHint(QSize(50,50));
        ui->registr->insertItem(cisloRadku, novaPolozka);
    } else {
        QMessageBox::critical(this, "Varovani", "Nelze pridat polozku bez jmena.");
    }
}

void MainWindow::on_registr_itemClicked(QListWidgetItem *item)
{
  //  item->setBackground(Qt::yellow);
    //  item->setForeground(Qt::black);
}

void MainWindow::on_registr2_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    kontrolujShodu();
}

void MainWindow::kontrolujShodu()
{
    // zjistim prave vybrane polozky
    QListWidgetItem * item1 = ui->registr->currentItem();
    QListWidgetItem * item2 = ui->registr2->currentItem();

    if(item1 == NULL || item2 == NULL){
        ui->l_shoda->setText("Zadna vybrana polozka");
        ui->l_shoda->setStyleSheet("color: black");
        return;
    } else {
        QString text1 = item1->text();
        QString text2 = item2->text();

        if(text1 == text2){
            ui->l_shoda->setText("ANO");
            ui->l_shoda->setStyleSheet("color: green");

        } else {
            ui->l_shoda->setText("NE");
            ui->l_shoda->setStyleSheet("color: red");

        }
    }

}










