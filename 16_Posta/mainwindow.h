#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "fronta.h"
#include "zasobnik.h"
#include "osoba.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_pridej_clicked();

private:
    Ui::MainWindow *ui;
    Fronta * fronta;
    Zasobnik * z_prepazka1;
    Zasobnik * z_prepazka2;
    Zasobnik * z_prepazka3;
};
#endif // MAINWINDOW_H
