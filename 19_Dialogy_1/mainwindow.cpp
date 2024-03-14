#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn_msgBox1_clicked()
{
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
    msg1.addButton("Utery", QMessageBox::YesRole);

    msg1.setDefaultButton(QMessageBox::StandardButton::Cancel);
    btn = msg1.exec(); // vyvolani dialogu

    QString odpoved = "Uzivatel stiskl " + QString::number(btn);
    if(btn == QMessageBox::Help){
         QMessageBox::information(this, "Odpoved", "Uzivatel stisknul Help");
    } else {
        QMessageBox::information(this, "Odpoved", odpoved);
    }
}

void MainWindow::on_btn_kviz_clicked()
{
    int btn; // odpoved uzivatele
    QMessageBox msg;
    msg.setWindowTitle("Kvíz");
    msg.setText("Jaká je nejvyšší hora České republiky?");
    msg.addButton("Klínovec", QMessageBox::NoRole);
    msg.addButton("Ještěd", QMessageBox::NoRole);
    msg.addButton("Červený vrch", QMessageBox::NoRole);
    msg.addButton("Sněžka", QMessageBox::YesRole);
    msg.addButton("Praděd", QMessageBox::NoRole);

    btn = msg.exec();
    qDebug() << "Odpoved: " << btn;
    if(btn == 3){
        QMessageBox::information(this, "Uspech", "Spravna odpoved!");
    } else {
        QMessageBox::warning(this, "Chyba", "Toto neni spravna odpoved!");
    }

}

void MainWindow::on_btn_nacist_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,
                                                    "Vyber obrazku",
                                                    "C:\\Users\\Tom\\Pictures",
                                                    "Image files (*.png, *.jpg)");
    if(filename == ""){
        QMessageBox::critical(this, "Upozorneni", "Nebyl vybran zadny soubor");
    } else {
        QIcon i1 = QIcon(filename);
        int w = ui->l_image->width();
        int h = ui->l_image->height();
        QPixmap pix = i1.pixmap(w,h);
        ui->l_image->setPixmap(pix);
    }
}

void MainWindow::on_btn_ulozitInfo_clicked()
{
    QString inspectFolder = QFileDialog::getExistingDirectory(this,
                                                              "Vyberte slozku k inspekci",
                                                              "C:\\");
    if(inspectFolder == ""){
        QMessageBox::critical(this, "Upozorneni", "Nebyla vybrana zadna slozka.");
        return;
    }

    QString reportFile = QFileDialog::getSaveFileName(this,
                                                      "Zvolte soubor, kam se ulozi report",
                                                      "C:\\Users\\Tom\\Desktop");
    QDir directory = QDir(inspectFolder); // zalozim promennou typu QDir k pruzkumu
    QStringList files = directory.entryList(); // ziskame seznam vsech souboru a slozek v inspectFolder
    qDebug() << files;

    QFile file(reportFile);
    if(file.open(QIODevice::ReadWrite)){
        QTextStream s(&file);
        for(int i = 0; i < files.length(); i++){
            s << files[i] << endl;
        }
        QString infomessage = "Report ulozen sem: " + reportFile;
        QMessageBox::information(this, "OK", infomessage);
    }
}

void MainWindow::on_btn_color_clicked()
{
    QColor c = QColorDialog::getColor(Qt::white,this,"Vyberte barvu");
    if(c.isValid()){
        QString style = QString("background-color: %1").arg(c.name());
        qDebug() << "Jmeno barvy: " << c.name();
        ui->btn_color->setStyleSheet(style);
    } else {
        QMessageBox::critical(this, "Pozor", "Nebyla vybrana platna barva");
    }
}




void MainWindow::on_btn_font_clicked()
{
    bool ok; // kontrola, jak to dopadlo
    QFont f = QFontDialog::getFont(&ok, QFont("Times", 20), this, "Titule okna");
    if(ok){
        ui->l_dialogy->setFont(f);
    } else {
        QMessageBox::critical(this, "Pozor", "Nebyl vybran platny font");
    }
}
