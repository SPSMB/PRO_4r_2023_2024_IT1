#include "novy.h"
#include "ui_novy.h"

Novy::Novy(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Novy)
{
    ui->setupUi(this);
}

Novy::~Novy()
{
    delete ui;
}

void Novy::saveData()
{
    n_jmeno = ui->le_jmeno->text();
    n_prijmeni = ui->le_prijmeni->text();
    QString tmp = ui->le_narozen->text();
    n_narozen = tmp.toInt();
}

void Novy::on_btn_foto_clicked()
{
    n_foto = QFileDialog::getOpenFileName(this,
                                          "Vyberte fotografii uzivatele",
                                          "C:\\Users\\Tom\\Pictures",
                                          "Images (*.png *.jpg)");
}

void Novy::on_buttonBox_accepted()
{
    saveData(); // ulozim vsechna data z formulare
    done(QDialog::Accepted);
}
