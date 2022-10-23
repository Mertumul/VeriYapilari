#include <iostream>
#include <sstream>
using namespace std;

int StringtoInt(string str)
{
    stringstream ss(str);
    int deger;
    ss >> deger;
    return deger;
}

int a2b2(int x, int y)
{
    return x * x + y * y;
}

int main(int argc, char *argv[])
{

    int x, y;
    x = StringtoInt(argv[1]);
    y = StringtoInt(argv[2]);
    cout << "x2+y2:" << a2b2(x, y);

    return 0;
}