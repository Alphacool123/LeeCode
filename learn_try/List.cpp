#include <iostream>
#include <list>
using namespace std;

int main()
{

    list<int> l;
    list<int> new_list{1, 2, 3, 4};
    cout << l.empty() << endl;
    cout << new_list.empty() << endl;
    l.push_back(1);
    cout << l.size() << endl;
    l.swap(new_list);
    cout << l.size() << endl;
    cout << *new_list.begin() + 1 << endl;

    for (list<int>::iterator itr = l.begin(); itr != l.end(); itr++)
    {
        cout << *itr << endl;
    }

    for (list<int>::reverse_iterator rtr = l.rbegin(); rtr != l.rend(); rtr++)
    {
        cout << *rtr << " ";
    }

    return 0;
}