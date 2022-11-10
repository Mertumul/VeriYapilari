#include <iostream>
#include <iomanip>
#include "Liste.hpp"
using namespace std;

int main()
{

    Liste *liste = new Liste();
    liste->ekle(11);
    liste->ekle(12);
    liste->ekle(31);
    cout << *liste;
    liste->onuneEkle(0, 945);
    cout << *liste;
    liste->cikar(1);
    cout << *liste;

    try
    {
        cout << liste->ilkGetir() << endl;
    }
    catch (std::out_of_range &e)
    {
        cout << e.what() << endl;
    }
    delete liste;
}