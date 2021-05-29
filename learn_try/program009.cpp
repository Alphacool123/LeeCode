#include <iostream>

using namespace std;

class Shape
{

protected:
    int width, height;

public:
    Shape(int a = 0, int b = 0)
    {
        width = a;
        height = b;
    }
    int area()
    {
        cout << "Parent class area:" << endl;
        return 0;
    }
};

class Rectangle:public Shape
{
    
};

int main()
{

    return 0;
}