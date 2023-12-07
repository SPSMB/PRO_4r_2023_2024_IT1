#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QDebug>
#include <QInputDialog>
#include <QMessageBox>

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
    void on_registr_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_btn_odstranit_clicked();

    void on_btn_rename_clicked();

    void on_btn_add_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
