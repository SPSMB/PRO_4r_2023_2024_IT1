#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setSceneRect(0, 0, 1000, 800);

    QLineF line1 = QLineF(0,0,100,200);
    QLineF line2 = QLineF(10,0,110,200);

    QColor modra = QColor(0,0,200,255);
    QPen styl = QPen(modra);

    scene->addLine(line1, styl);
    scene->addLine(line2, QPen(QColor(255,0,0,255)));

    QGraphicsItem * obdelnik = scene->addRect(0,0,100,200,
                   QPen(QColor(0,150,0,255)),QBrush(Qt::yellow));

    obdelnik->setPos(0,0);

    // vytvorim vlastni letadlo
    letadlo1 = new Letadlo;
    scene->addItem(letadlo1);
    letadlo1->setPos(700,50);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "Key pressed " << event->key();


    if(event->key() == Qt::Key_W){ // W = 87
        letadlo1->setY(letadlo1->y() - 10);
    } else if(event->key() == Qt::Key_A) //A = 65
    {
        letadlo1->setX(letadlo1->x()-10);
    } else if(event->key() == Qt::Key_S) //S = 83
    {
        letadlo1->setY(letadlo1->y()+10);
    } else if(event->key() == Qt::Key_D)  //D = 68
    {
        letadlo1->setX(letadlo1->x()+10);
    }

}


