#include <iostream>
using namespace std;

const float NORMAL = 0.000001;

int main()
{
    bool flag = false;
    if (!flag)
        cout << "A" << endl;
    else
        cout << "B" << endl;

    int flag2 = 0;
    if (flag == 0)
        cout << "A" << endl;
    else
        cout << "B" << endl;

    int *p = nullptr;
    if (p == nullptr)
        cout << "A" << endl;
    else
        cout << "B" << endl;

    float f = 0.000000001;
    if ((f >= -NORMAL) && (f <= NORMAL))
        cout << "A" << endl;
    else
        cout << "B" << endl;
    return 0;
}