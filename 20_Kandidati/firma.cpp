#include "firma.h"
#include "ui_firma.h"

Firma::Firma(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Firma)
{
    ui->setupUi(this);
    Kandidat * k1 = new Kandidat("Amy", "Farrah Fowler", 1990, ":/osoby/img/Amy.PNG");
    Kandidat * k2 = new Kandidat("Leonard", "Howstadter", 1950, ":/osoby/img/Leonard.PNG");
    Kandidat * k3 = new Kandidat("Sheldon", "Cooper", 1965, ":/osoby/img/Sheldon.PNG");
    Kandidat * k4 = new Kandidat("Penny", "XYZ", 2001, ":/osoby/img/Penny.PNG");

    pridejKandidata(k1, f_novi_kandidati, ui->lw_novy);
    pridejKandidata(k2, f_novi_kandidati, ui->lw_novy);
    pridejKandidata(k3, f_novi_kandidati, ui->lw_novy);
    pridejKandidata(k4, f_novi_kandidati, ui->lw_novy);

}

Firma::~Firma()
{
    delete ui;
    int kontrolniCitac = 0;
    int velikostFronty = f_novi_kandidati.size();
    for(int i=0; i<velikostFronty; i++){
        Kandidat * k = f_novi_kandidati.dequeue();
        kontrolniCitac++;
        delete k;
    }
    velikostFronty = f_schvaleni_kandidati.size();
    for(int i=0; i<velikostFronty; i++){
        Kandidat * k = f_schvaleni_kandidati.dequeue();
        kontrolniCitac++;
        delete k;
    }
    velikostFronty = f_prijati_kandidati.size();
    for(int i=0; i<velikostFronty; i++){
        Kandidat * k = f_prijati_kandidati.dequeue();
        kontrolniCitac++;
        delete k;
    }
    velikostFronty = f_zamitnuti_kandidati.size();
    for(int i=0; i<velikostFronty; i++){
        Kandidat * k = f_zamitnuti_kandidati.dequeue();
        kontrolniCitac++;
        delete k;
    }
    qDebug()  << "Odstraneno " << kontrolniCitac << " kandidatu.";
}

void Firma::pridejKandidata(Kandidat *k, QQueue<Kandidat *> &fronta, QListWidget *lw)
{
    fronta.enqueue(k);
    lw->addItem(k);
}

Kandidat * Firma::odeberKandidata(QQueue<Kandidat *> &fronta, QListWidget *lw)
{
    Kandidat *k = fronta.dequeue();
    lw->takeItem(0);
    return k;
}

void Firma::updateDetail(Kandidat *k)
{
    ui->l_jmeno->setText(k->k_jmeno + " " + k->k_prijmeni);
    ui->l_bydliste->setText(k->k_bydliste);
    ui->l_vek->setText(QString::number(k->vek())+" let");
    ui->l_stav->setText(k->stav().toUpper());
    ui->l_posledniZmena->setText(k->k_posledniZmena.toString("dd.MM.yyyy, hh:mm:ss"));

    // vlozeni obrazku
    int w = ui->l_obrazek->width();
    int h = ui->l_obrazek->height();
    QPixmap p = QPixmap(k->k_foto);
    ui->l_obrazek->setPixmap(p.scaled(w, h, Qt::KeepAspectRatio));

    // nastaveni barvy ukazatele stavu
    QString color;
    if(k->stav() == "novy"){
        color = "white";
    } else if(k->stav() == "schvalen"){
        color = "yellow";
    } else if(k->stav() == "prijat"){
        color = "#9cf79c";
    } else {
        color = "red";
    }
    ui->l_stav->setStyleSheet("QLabel { background: " + color + " }");
}


void Firma::on_btn_n_zamitnout_clicked()
{
    // 0 mel bych spravne osetrit pripad, kdy je fronta prazdna
    if(f_novi_kandidati.isEmpty()){
        QMessageBox::warning(this, "Upozorneni", "Fronta je prazdna.");
        return;
    }
    // 1 - odebiram
    Kandidat * k = odeberKandidata(f_novi_kandidati, ui->lw_novy);

    // 2 - posun stavu
    k->posunStav(false);

    // 3 - pridavam
    pridejKandidata(k, f_zamitnuti_kandidati, ui->lw_zamitnut);
}

void Firma::on_btn_n_dale_clicked()
{
    // 0 mel bych spravne osetrit pripad, kdy je fronta prazdna
    if(f_novi_kandidati.isEmpty()){
        QMessageBox::warning(this, "Upozorneni", "Fronta je prazdna.");
        return;
    }
    // 1 - odebiram
    Kandidat * k = odeberKandidata(f_novi_kandidati, ui->lw_novy);

    // 2 - posun stavu
    k->posunStav(true);

    // 3 - pridavam
    pridejKandidata(k, f_schvaleni_kandidati, ui->lw_schvalen);
}

void Firma::on_btn_s_zamitnout_clicked()
{
    // 0 mel bych spravne osetrit pripad, kdy je fronta prazdna
    if(f_schvaleni_kandidati.isEmpty()){
        QMessageBox::warning(this, "Upozorneni", "Fronta je prazdna.");
        return;
    }
    // 1 - odebiram
    Kandidat * k = odeberKandidata(f_schvaleni_kandidati, ui->lw_schvalen);

    // 2 - posun stavu
    k->posunStav(false);

    // 3 - pridavam
    pridejKandidata(k, f_zamitnuti_kandidati, ui->lw_zamitnut);
}

void Firma::on_btn_s_dale_clicked()
{
    // 0 mel bych spravne osetrit pripad, kdy je fronta prazdna
    if(f_schvaleni_kandidati.isEmpty()){
        QMessageBox::warning(this, "Upozorneni", "Fronta je prazdna.");
        return;
    }
    // 1 - odebiram
    Kandidat * k = odeberKandidata(f_schvaleni_kandidati, ui->lw_schvalen);

    // 2 - posun stavu
    k->posunStav(true);

    // 3 - pridavam
    pridejKandidata(k, f_prijati_kandidati, ui->lw_prijat);
}

void Firma::on_lw_novy_itemClicked(QListWidgetItem *item)
{
    updateDetail(dynamic_cast<Kandidat *>(item)); //?
    //updateDetail(static_cast<Kandidat *>(item));
    //updateDetail((Kandidat *)item);
}

void Firma::on_lw_schvalen_itemClicked(QListWidgetItem *item)
{
    updateDetail((Kandidat *)item);
}

void Firma::on_lw_prijat_itemClicked(QListWidgetItem *item)
{
    updateDetail((Kandidat *)item);
}

void Firma::on_lw_zamitnut_itemClicked(QListWidgetItem *item)
{
    updateDetail((Kandidat *)item);
}
