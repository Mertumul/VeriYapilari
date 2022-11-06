#include <iostream>
using namespace std;
#include <iomanip>

class vector
{

public:
    vector(int x, int y, int z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    friend ostream &operator<<(ostream &os, const vector &v1);

private:
    int x, y, z;
};
ostream &operator<<(ostream &os, const vector &v1)
{
    os << "x,y,z=" << v1.x << "," << v1.y << "," << v1.z << endl;
    return os;
}

int main()
{

    vector v1(1, 2, 3);
    cout << v1;
}