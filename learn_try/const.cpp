#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // const右边是什么，什么就不可以变
    int c = 22;
    const int a = 10;
    int const b = 20;
    // int const *p = &c;
    int *const p = &c;
    *p = b;
    cout << *p << endl;

    return 0;
}