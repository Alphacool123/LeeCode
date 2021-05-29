#include <iostream>

using namespace std;

int main()
{

    int i;
    double d;

    int &r = i;
    double &s = d;

    cout << &i << endl;
    cout << &r << endl;
}