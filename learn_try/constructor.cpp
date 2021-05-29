#include <iostream>
using namespace std;

class Father
{
public:
    Father()
    {
        cout << "father构造函数" << endl;
        for (int i = 0; i < 2;i++)
            a[i] = 0;
    }
    ~Father()
    {
        cout << "father析构函数" << endl;
        delete [] a;
    }

private:
    int *a = new int[2];
};

class Child : public Father
{
public:
    Child()
    {
        cout << "child构造函数" << endl;
    }
    ~Child()
    {
        cout << "child构造函数" << endl;
    }
};

int main()
{
    Father father;
    Child child;

    return 0;
}