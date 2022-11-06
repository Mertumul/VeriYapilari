#include <iostream>
using namespace std;

class Dugum
{
public:
    Dugum(int veri)
    {
        this->veri = veri;
        sonraki = NULL;
    }
    int veri;
    Dugum *sonraki;
};

class BagliListe
{
private:
    Dugum *ilk;

public:
    BagliListe()
    {
        ilk = 0;
    }
    ~BagliListe()
    {
        Dugum *gec = ilk;
        while (gec != 0)
        {
            Dugum *sil = gec;
            gec = gec->sonraki;
            delete sil;
        }
    }
    void ekle(int sayı)
    {
        Dugum *yeni = new Dugum(sayı);
        if (ilk == 0)
        {
            ilk = yeni;
            return;
        }
        Dugum *gec = ilk;
        while (gec->sonraki != 0)
        {
            gec = gec->sonraki;
        }
        gec->sonraki = yeni;
    }
    void yazdır()
    {
        Dugum *gec = ilk;
        while (gec != 0)
        {
            cout << gec->veri << ",";
            gec = gec->sonraki;
        }
    }

    void Elemancikarma()
    {
        if (ilk == 0)
            return;
        if (ilk->sonraki == 0)
        {
            delete ilk;
            ilk = 0;
            return;
        }
        Dugum *gec = ilk;
        while (gec->sonraki->sonraki != 0)
        {
            gec = gec->sonraki;
        }
        delete gec->sonraki;
        gec->sonraki = 0;
    }
};