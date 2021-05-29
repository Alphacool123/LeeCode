#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

double getAverage(int arr[], int size)
{
    int i, sum = 0;
    double avg = 0;
    for (i = 0; i < size; ++i)
    {
        sum += arr[i];
    }
    avg = double(sum) / size;

    return avg;
}

int main()
{

    // 定义数字
    short s;
    int i;
    long l;
    float f;
    double d;

    // 数字赋值
    s = 10.1;
    i = 10.1;
    l = 10.1;
    f = 10.1;
    d = 10.12300000;

    cout << s << endl;
    cout << i << endl;
    cout << l << endl;
    cout << f << endl;
    cout << d << endl;

    cout << sqrt(i) << endl;
    cout << pow(i, 2) << endl;
    cout << floor(f) << endl;

    int a, b;
    srand((unsigned)time(NULL));
    for (int a; a < 10; a++)
    {
        b = rand();
        cout << b / 1000 << endl;
    }

    int balance[5] = {100, 2, 300, 51, 2};
    double avg;

    avg = getAverage(balance, 5);
    cout << "均值：" << avg << endl;

    return 0;
}