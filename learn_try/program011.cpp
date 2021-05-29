#include <iostream>

using namespace std;

int main()
{

    double runoobAarray[5] = {1000.0, 2.0, 3.4, 17.0, 50.0};
    double *p;

    p = runoobAarray;

    for (int i = 0; i < 5; i++)
    {
        cout << *(p + i) << endl;
    }

    for (int i = 0; i < 5; i++)
    {
        cout << *(runoobAarray + i) << endl;
    }
    for (int i = 0; i < 5; i++)
    {
        cout << *p << endl;
        p++;
    }
    return 0;
}