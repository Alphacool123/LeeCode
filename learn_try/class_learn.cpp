#include <iostream>
using namespace std;

class Box
{
public:
    double length;
    double breadth;
    double hieght;

    double get();
    void set(double len, double bre, double hei);
};

double Box::get()
{
    return length * breadth * hieght;
}

void Box::set(double len, double bre, double hei)
{
    length = len;
    breadth = bre;
    hieght = hei;
}

int main()
{

    Box box1;
    Box box2;
    double volume;

    box1.hieght = 5.0;
    box1.length = 6.0;
    box1.breadth = 8.0;
    cout << box1.get() << endl;

    box2.set(5.0, 5.0, 5.0);
    cout << box2.get() << endl;

    return 0;
}