#include <iostream>
#include <memory>
using namespace std;

class Test
{
public:
    Test() { cout << "constructor called" << endl; }
    ~Test() { cout << "destructor called" << endl; }
    void show() const { cout << "show" << endl; }
};

int main()
{
    {
        shared_ptr<Test> aptr(new Test);
        cout << aptr.use_count() << endl;
        shared_ptr<Test> bptr = aptr;
        cout << aptr.use_count() << endl;
        cout << bptr.use_count() << endl;
        cout << aptr.get() << endl;
        cout << bptr.get() << endl;
    }

    return 0;
}
