#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QDebug>
#include <QFileDialog>
#include <QColorDialog>
#include <QFontDialog>
#include <QInputDialog>
#include <QTime>
#include <QProgressDialog>

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
    void on_btn_msgBox1_clicked();

    void on_btn_kviz_clicked();

    void on_btn_nacist_clicked();

    void on_btn_ulozitInfo_clicked();

    void on_btn_color_clicked();

    void on_btn_font_clicked();

    void on_btn_pobocky_clicked();

    void delay(int msec);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
