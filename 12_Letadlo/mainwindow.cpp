#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setSceneRect(0, 0, 700, 600);

    QLineF line1 = QLineF(0,0,100,200);
    QLineF line2 = QLineF(10,0,110,200);

    QColor modra = QColor(0,0,200,255);
    QPen styl = QPen(modra);

    QGraphicsLineItem * cara = scene->addLine(line1, styl);
    scene->addLine(line2, QPen(QColor(255,0,0,255)));


    QGraphicsItem * obdelnik = scene->addRect(0,0,100,200,
                   QPen(QColor(0,150,0,255)),QBrush(Qt::yellow));

    obdelnik->setPos(0,0);

    // vytvorim vlastni letadlo
    letadlo1 = new Letadlo;
    scene->addItem(letadlo1);
    letadlo1->setPos(700,50);

    // pridani automobilu
    auto_sirka = 50;
    automobil1 = scene->addRect(100,100,auto_sirka,auto_sirka,
                   QPen(QColor(255,0,0,255)),QBrush(Qt::red));
    auto_sirka = 100;
    automobil2 = scene->addRect(500,500,auto_sirka,auto_sirka,
                   QPen(QColor(255,0,0,255)),QBrush(Qt::red));

    // obsluha casovace
    timer1 = new QTimer;
    connect(timer1, &QTimer::timeout, this, &MainWindow::obsluhaCasovace);
    timer1->setInterval(100);
    timer1->start();

    barevny_stav = 0;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "Key pressed " << event->key();


    if(event->key() == Qt::Key_W){ // W = 87
        if(letadlo1->y() > 0){
            qDebug() << "Letadlo y: " << letadlo1->y();
            letadlo1->setY(letadlo1->y() - 10);
        }
    } else if(event->key() == Qt::Key_A) //A = 65
    {
        letadlo1->setX(letadlo1->x()-10);
    } else if(event->key() == Qt::Key_S) //S = 83
    {
        qDebug() << "Letadlo y: " << letadlo1->y();
        qDebug() << "Vyska graphicsView: " << ui->graphicsView->height();
        if(letadlo1->y() < ui->graphicsView->height() - letadlo1->height()){
            letadlo1->setY(letadlo1->y()+10);
        }
    } else if(event->key() == Qt::Key_D)  //D = 68
    {
        letadlo1->setX(letadlo1->x()+10);
    } else if(event->key() == Qt::Key_R){
        letadlo1->setX(0);
        letadlo1->setY(0);
    } else if(event->key() == Qt::Key_H){
        letadlo1->setY(0);
    }

}

void MainWindow::obsluhaCasovace()
{
    automobil1->setX(automobil1->x()+10);
    automobil2->setY(automobil2->y()-9);

    QString s2;
    QTextStream ts(&s2);
    ts << "Auto x: " << automobil1->x();
    QString s = "Auto x: " + QString::number(automobil1->x());
    ui->console->append(ts.readAll());

    //qDebug() << "Auto x: " << automobil1->x();
    //qDebug() << "Limit: " << ui->graphicsView->width() - auto_sirka;

    if(automobil1->x() > 900 || automobil1->collidesWithItem(letadlo1)
            || automobil1->collidesWithItem(automobil2)){
        automobil1->setBrush(QBrush(QColor(235,175,50,255)));
        automobil2->setBrush(QBrush(QColor(235,175,50,255)));
        timer1->stop();
    }
}



void MainWindow::on_tlacitko1_clicked()
{
    // qDebug() << "Tlacitko 1 bylo stisknuto";
    // QString s = "Tlacitko 1 bylo stisknuto";
    // ui->console->append(s);

    if(barevny_stav == 1){
        automobil1->setBrush(QBrush(QColor(0,0,0,255)));
        barevny_stav++;
    } else if(barevny_stav == 2){
        automobil1->setBrush(QBrush(QColor(255,255,0,255)));
        barevny_stav = 0;
    } else { // barevny_stav == 0
        automobil1->setBrush(QBrush(QColor(255,0,255,255)));
        barevny_stav++;
    }
}

void MainWindow::on_btn_color_clicked()
{
    // Varianta 2 - pouziti staticke promenne - na jeji hodnotu se ptam v ifu
    static bool checked = false;
    QPalette p = ui->console->palette();

    if(/*!checked */ p.color(QPalette::Base) == Qt::white){
        ui->console->append(QString("Zmena barvy na cerne pozadi"));
        p.setColor(QPalette::Base, Qt::black);
        p.setColor(QPalette::Text, Qt::white);
    } else {
        ui->console->append(QString("Zmena barvy na bile pozadi"));
        p.setColor(QPalette::Base, Qt::white);
        p.setColor(QPalette::Text, Qt::black);
    }
    checked = !checked;

    // Varianta 3 - velmi usporny zapis
    //p.setColor(QPalette::Base, p.color(QPalette::Base) == Qt::white ? Qt::black : Qt::white);
    //p.setColor(QPalette::Text, p.color(QPalette::Text) == Qt::black ? Qt::white : Qt::black);

    ui->console->setPalette(p);
}

void MainWindow::on_btn_vymazat_clicked()
{
    ui->console->clear();
}

void MainWindow::on_btn_letadlo_clicked()
{
    // bylo by dobre kontrolovat mnozstvi pridanych letadel
    //  a bud pridat jen 1 navic nebo kazde dalsi ulozit do nejake struktury
    Letadlo * dalsiLetadlo = new Letadlo();
    scene->addItem(dalsiLetadlo);
    dalsiLetadlo->setPos(350,50);
}
