#include <iostream>
using namespace std;

void arrayinversion(int x[], int y)
{
    if (y > 1)
    {
        int temp = x[0];
        x[0] = x[y - 1];
        x[y - 1] = temp;
        arrayinversion(x + 1, y - 2);
    }
}

int main()
{

    int Numbers[] = {1, 2, 3, 4, 5, 6, 7, 8};
    cout << " before array string inversion" << endl;

    for (int i = 0; i < 8; i++)
    {
        cout << Numbers[i] << " ";
    }
    cout << endl
         << "after array string inversion" << endl;

    arrayinversion(Numbers, 8);
    for (int i = 0; i < 8; i++)
    {
        cout << Numbers[i] << " ";
    }
}