#include <iostream>
using namespace std;

class Ddügüm
{
public:
    Ddügüm(int veri)
    {
        this->veri = veri;
        sonraki = onceki = 0;
    }
    int veri;
    Ddügüm *onceki;
    Ddügüm *sonraki;
};

class IkiYonluBagliListe
{
public:
    IkiYonluBagliListe()
    {
        ilk = 0;
    }
    ~IkiYonluBagliListe();
    void ekle(int sayi)
    {
        Ddügüm *yeni = new Ddügüm(sayi);
        if (ilk == 0)
        {
            ilk = yeni;
            return;
        }
        Ddügüm *gec = ilk;
        while (gec->sonraki != 0)
        {
            gec = gec->sonraki;
        }
        gec->sonraki = yeni;
        yeni->onceki = gec;
    }
    void cikar()
    {
        if (ilk == 0)
            return;
        if (ilk->sonraki == 0)
        {
            delete ilk;
            ilk = 0;
            return;
        }
        Ddügüm *gec = ilk;
        while (gec->sonraki->sonraki != 0)
        {
            gec = gec->sonraki;
        }
        delete gec->sonraki;
        gec->sonraki = 0;
    }
    // istenilen dügümü getir

    Ddügüm *dugumgetir(int sira)
    {
        int sayac = 0;
        Ddügüm *gec = ilk;
        while (gec != 0)
        {
            if (sayac == sira)
                return gec;
            gec = gec->sonraki;
            sayac++;
        }
        return 0;
    }
    // istenen elemanı cıkar

    void cikar(int sira)
    {
        Ddügüm *sil = dugumgetir(sira);
        if (sira == 0)
            return;

        Ddügüm *onceki = sil->onceki;
        Ddügüm *sonraki = sil->sonraki;
        delete sil;
        if (sonraki)
            sonraki->onceki = onceki;
        if (onceki)
            onceki->sonraki = sonraki;
        else
            ilk = sonraki;
    }

    // istenilen yere eleman ekle
    void ekle(int sira, int veri)
    {
        if (ilk == 0 && sira == 0)
        {
            ilk = new Ddügüm(veri);
            return;
        }

        Ddügüm *dug = dugumgetir(sira);
        if (dug == 0)
            return;

        Ddügüm *yeni = new Ddügüm(veri);
        Ddügüm *onceki = dug->onceki;
        dug->onceki = yeni;
        yeni->sonraki = dug;
        yeni->onceki = onceki;
        if (onceki)
            onceki->sonraki = yeni;
        else
            ilk = yeni;
    }

private:
    Ddügüm *ilk;
};

int main()
{
    Ddügüm *d1 = new Ddügüm(25);
    Ddügüm *d2 = new Ddügüm(50);
    Ddügüm *d3 = new Ddügüm(75);
    d1->sonraki = d2;
    d2->onceki = d1;
    d2->sonraki = d3;
    d3->onceki = d2;
}