#include <iostream>
using namespace std;

class Number
{

public:
    int value;
    Number(int value)
    {
        this->value = value;
    }
    Number()
    {
        value = 0;
    }
    bool operator<(Number &right)
    {
        return this->value < right.value;
    }
    friend ostream &operator<<(ostream &screen, Number &right)
    {
        screen << right.value;
        return screen;
    }
};

template <typename Tur>
Tur BringMin(Tur &t1, Tur t2)
{
    return t1 < t2 ? t1 : t2;
}

int main()
{
    int a = 5, b = 8;
    cout << "Minimum Integer Number:" << BringMin<int &>(a, b) << endl;

    string str = "Mert", str2 = "Umul";
    cout << "Minimum String:" << BringMin<string &>(str, str2) << endl;

    Number *num = new Number(200);
    Number *num2 = new Number(500);
    cout << "Minimum Number Object:" << BringMin<Number &>(*num, *num2) << endl;
    delete num;
    delete num2;
    return 0;
}
