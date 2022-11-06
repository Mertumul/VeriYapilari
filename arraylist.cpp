#include <iostream>
using namespace std;

class ArrayList
{
public:
    int *Elements;
    int n;
    int capacitiy;
    ArrayList(int capacity) // constructor
    {
        this->capacitiy = capacitiy;
        Elements = new int[capacitiy]; // array on heap
        n = 0;
    }
    void resize()
    {
        // increas the array size of two times
        int newcap = capacitiy > 0 ? 2 * capacitiy : 1;
        int *Temp = new int[newcap];
        for (int i = 0; i < n; i++)
            Temp[i] = Elements[i];
        delete[] Elements; // delete the old array
        Elements = Temp;
        capacitiy = newcap;
    }
    ~ArrayList()
    {
        delete[] Elements;
    }
};

int main()
{

    ArrayList *arr = new ArrayList(10);
    cout << "arr Elements address:" << arr->Elements << endl;
    arr->resize();
    cout << "arr Elements address:" << arr->Elements << endl;
}