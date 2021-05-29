#include <iostream>

using namespace std;

class Box
{
public:
    double length;
    double breadth;
    double height;

    //成员函数
    double get(void);
    void set(double len, double bre, double hei);
};

double Box::get(void)
{
    return length * breadth * height;
}

void Box::set(double len, double bre, double hei)
{
    length = len;
    breadth = bre;
    height = hei;
}

int main()
{
    Box Box1;
    Box Box2;
    Box Box3;

    double volume = 0.0;
    Box1.height = 5.0;
    Box1.breadth = 6.0;
    Box1.length = 3.0;
    Box1.set(6.0, 5.0, 3.0);
    cout << Box1.get() << endl;

    return 0;
}
