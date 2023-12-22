#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QDebug>
#include <QInputDialog>
#include <QMessageBox>
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void addItem(QListWidget * list, QListWidgetItem * item);
    void addItem(QListWidget * list, QString itemString);

private slots:
    void on_registr_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_btn_odstranit_clicked();

    void on_btn_rename_clicked();

    void on_btn_add_clicked();

    void on_registr_itemClicked(QListWidgetItem *item);

    void on_registr2_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

private:
    Ui::MainWindow *ui;
    void kontrolujShodu();
};
#endif // MAINWINDOW_H
