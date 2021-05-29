#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int &b = a;
    int *c = &a;
    int **d = &c;

    if (!c)//指针可直接作为判断语句
    {
        cout << "指针为空" << endl;
    }
    if (c)
    {
        cout << "指针不为空" << endl;
    }

    return 0;
}