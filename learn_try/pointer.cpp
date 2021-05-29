#include <iostream>
using namespace std;

const int Max = 3;

int main()
{
    int var[Max] = {10, 100, 200};
    int *ptr;

    ptr = var;
    while (ptr <= &var[Max - 1])
    {
        cout << *ptr << endl;
        ptr++;
    }

    return 0;
}