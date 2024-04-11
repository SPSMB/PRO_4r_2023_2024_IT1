#ifndef FIRMA_H
#define FIRMA_H

#include <QMainWindow>
#include <QQueue>
#include "kandidat.h"
#include "login.h"
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class Firma; }
QT_END_NAMESPACE

class Firma : public QMainWindow
{
    Q_OBJECT

public:
    Firma(QWidget *parent = nullptr);
    ~Firma();

    void pridejKandidata(Kandidat * k, QQueue<Kandidat *> & fronta, QListWidget * lw);
    void pridejKandidatadoQLW(Kandidat * k, QListWidget * lw);
    Kandidat * odeberKandidata(QQueue<Kandidat *> & fronta, QListWidget * lw);
    void odeberKandidatazQLW(Kandidat * k, QListWidget * lw);
    void updateDetail(Kandidat * k); // funkce odpovedna za spravne vypsani informaci na karte detail

private slots:
    void on_btn_n_zamitnout_clicked();

    void on_btn_n_dale_clicked();

    void on_btn_s_zamitnout_clicked();

    void on_btn_s_dale_clicked();

    void on_lw_novy_itemClicked(QListWidgetItem *item);

    void on_lw_schvalen_itemClicked(QListWidgetItem *item);

    void on_lw_prijat_itemClicked(QListWidgetItem *item);

    void on_lw_zamitnut_itemClicked(QListWidgetItem *item);

    void on_btn_login_clicked();

    void upravProstredi(); // upravi prostredu bud pro admina nebo pro usera

    void on_btn_novy_clicked();

    void on_lw_abecedne_itemClicked(QListWidgetItem *item);

private:
    Ui::Firma *ui;
    QQueue<Kandidat *> f_novi_kandidati;
    QQueue<Kandidat *> f_schvaleni_kandidati;
    QQueue<Kandidat *> f_prijati_kandidati;
    QQueue<Kandidat *> f_zamitnuti_kandidati;
    QString f_prihlasen; // kdo je prihlasen
};
#endif // FIRMA_H
