#ifndef NOVY_H
#define NOVY_H

#include <QDialog>
#include <QFileDialog>

namespace Ui {
class Novy;
}

class Novy : public QDialog
{
    Q_OBJECT

public:
    QString n_foto;
    QString n_jmeno;
    QString n_prijmeni;
    int n_narozen;

    explicit Novy(QWidget *parent = nullptr);
    ~Novy();
    void saveData();

private slots:
    void on_btn_foto_clicked();

    void on_buttonBox_accepted();

private:
    Ui::Novy *ui;
};

#endif // NOVY_H
