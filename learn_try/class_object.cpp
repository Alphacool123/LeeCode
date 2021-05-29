#include <iostream>
using namespace std;

class Animal
{
public:
    virtual void speak()
    {
        cout << "Animal在说话" << endl;
    }
};

class Cat : public Animal
{
public:
    void speak()
    {
        cout << "Cat在说话" << endl;
    }
};

void dowork(Animal &animal)
{
    animal.speak();
}

void test()
{
    Cat cat;
    dowork(cat);
}

int main()
{
    test();
    return 0;
}