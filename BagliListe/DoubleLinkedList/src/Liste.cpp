#include "Liste.hpp"
#include <iomanip>

Liste ::Liste()
{
    ilk = 0;
}

void Liste::ekle(int veri)
{
    Dugum *yeniDugum = new Dugum(veri);
    if (ilk == 0)
    {
        ilk = yeniDugum;
    }
    else
    {
        Dugum *gecici = ilk;

        while (gecici->sonraki != 0)
        {
            gecici = gecici->sonraki;
        }
        gecici->sonraki = yeniDugum;
        yeniDugum->onceki = gecici;
    }
}
Liste::~Liste()
{
    Dugum *gecici = ilk;
    while (gecici != 0)
    {

        Dugum *silinecek = gecici;
        gecici = gecici->sonraki;

        delete silinecek;
    }
}
void Liste::cikar()
{
    if (ilk == 0)
        return;
    if (ilk->sonraki == 0)
    {
        delete ilk;
        ilk = 0;
    }
    else
    {
        Dugum *gecici = ilk;
        while (gecici->sonraki->sonraki != 0)
        {

            gecici = gecici->sonraki;
        }
        delete gecici->sonraki;
        gecici->sonraki = 0;
    }
}

void Liste::cikar(int sira)
{
    Dugum *silinecek = dugumGetir(sira);
    if (silinecek)
    {
        Dugum *onceki = silinecek->onceki;
        Dugum *sonraki = silinecek->sonraki;
        if (sonraki)
            sonraki->onceki = onceki;
        if (onceki)
            onceki->sonraki = sonraki;
        else
            ilk = sonraki;
        delete silinecek;
    }
}
void Liste::onuneEkle(int sira, int veri)
{
    Dugum *aktifdugum = dugumGetir(sira);
    if (aktifdugum)
    {
        Dugum *aktifOnceki = aktifdugum->onceki;
        Dugum *yeniDugum = new Dugum(veri);
        aktifdugum->onceki = yeniDugum;
        yeniDugum->sonraki = aktifdugum;
        yeniDugum->onceki = aktifOnceki;

        if (aktifOnceki)
            aktifOnceki->sonraki = yeniDugum;
        else
            ilk = yeniDugum;
    }
}
int Liste::ilkGetir()
{
    if (ilk != 0)
        return ilk->veri;
    throw std::out_of_range("Liste::ilkGetir() : Liste Bos hatasi");
}
Dugum *Liste::dugumGetir(int sira)
{
    Dugum *gecici = ilk;
    int sayac;
    while (sira >= 0 && gecici != 0)
    {
        if (sayac == sira)
            return gecici;
        gecici = gecici->sonraki;
        sayac++;
    }
    return 0;
}

ostream &operator<<(ostream &os, Liste &liste)
{

    using namespace std;
    os << setw(15) << " dugum adres" << setw(15) << "veri" << setw(15) << "onceki" << setw(15) << "sonraki" << endl;
    Dugum *gecici = liste.ilk;

    while (gecici != 0)
    {

        os << setw(15) << gecici << setw(15) << gecici->veri << setw(15) << gecici->onceki << setw(15) << gecici->sonraki << endl;
        gecici = gecici->sonraki;
    }
    os << "----------------------------" << endl;

    return os;
}
