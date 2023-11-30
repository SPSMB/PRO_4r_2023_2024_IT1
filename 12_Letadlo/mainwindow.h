#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include "letadlo.h"
#include <QDebug>
#include <QKeyEvent>
#include <QTimer>
#include <sstream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    Letadlo * letadlo1;
    QTimer * timer1;
    QGraphicsRectItem * automobil1;
    QGraphicsRectItem * automobil2;
    int auto_sirka;

private slots:
    void keyPressEvent(QKeyEvent *event);
    void obsluhaCasovace();
    void on_tlacitko1_clicked();
    void on_btn_color_clicked();
};

#endif // MAINWINDOW_H
