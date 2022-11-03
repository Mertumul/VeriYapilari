#include <iostream>
using namespace std;
class Sayi
{
private:
    int s1;
    int s2;

public:
    Sayi()
    {
        s1 = rand() % 100;
        s2 = rand() % 100;
        cout << this << "adresinde nesne olusturuldu" << endl;
    }
    ~Sayi()
    {
        cout << this << "adresindeki nesne yokeldildi" << endl;
    }
    void yazdir()
    {
        cout << "s1,s2:" << s1 << ',' << s2 << endl;
    }
};

int main()
{
    Sayi *p[10];
    p[0] = new Sayi;
    p[0]->yazdir();
    cout << "---------------------------------------------" << endl;
    p[1] = new Sayi[5];
    for (int i = 0; i < 5; i++)
        p[1][i].yazdir();
    cout << "---------------------------------------------" << endl;
    delete p[0];
    delete[] p[1];
}
