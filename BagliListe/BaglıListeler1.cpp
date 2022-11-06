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

int main()
{

    Dugum *d1 = new Dugum(15);
    Dugum *d2 = new Dugum(22);
    Dugum *d3 = new Dugum(45);
    Dugum *d4 = new Dugum(56);

    // listeye eleman ekleme
    d1->sonraki = d2;
    d2->sonraki = d3;
    d3->sonraki = d4;

    // listeyi döngü ile gezme
    Dugum *yeni = new Dugum(99);
    Dugum *gec = d1;
    while (gec->sonraki != 0)
    {
        gec = gec->sonraki;
    }
    // liste sonuna eleman ekleme
    gec->sonraki = yeni;
    cout << gec->veri << endl;
    cout << gec->sonraki->veri << endl;
    cout << yeni->veri << endl;
}