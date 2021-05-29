#include <iostream>
using namespace std;

int my_abs(int x)
{
    static int y = x;
    if (x >= 0)
        return x;
    else
        return -x;
}

int count_calls()
{
    static int a = 0;
    return ++a;
}

int main()
{
    int i = 100;
    for (int i = 0; i < 5; i++)
    {
        cout << i << " ";
    }
    cout << my_abs(i) << endl;
    for (int i = 0; i < 10; i++)
        cout << count_calls() << " ";
    return 0;
}