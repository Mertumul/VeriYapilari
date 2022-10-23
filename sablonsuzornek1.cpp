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

int BringMin(int &x, int &y)
{
    return x < y ? x : y;
}
string BringMin(string &x, string &y)
{
    return x < y ? x : y;
}

Number &BringMin(Number &s1, Number &s2)
{
    return s1 < s2 ? s1 : s2;
}

int main()
{

    int a = 5, b = 8;
    cout << "Minimum Integer Number:" << BringMin(a, b) << endl;

    string str = "Mert", str2 = "Umul";
    cout << "Minimum String:" << BringMin(str, str2) << endl;

    Number *num = new Number(200);
    Number *num2 = new Number(500);
    cout << "Minimum Number Object:" << BringMin(*num, *num2) << endl;
    delete num;
    delete num2;
    return 0;
}