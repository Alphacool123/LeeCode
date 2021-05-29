#include <iostream>
#include <set>
using namespace std;

void print(set<int> &v)
{
    set<int>::iterator iter = v.begin();
    while (iter != v.end())
    {
        cout << *iter << " ";
        iter++;
    }
    cout << endl;
}

int main()
{
    set<int> v{1, 2, 3, 4};
    print(v);

    // 添加元素
    v.insert(5);
    print(v);

    // 擦除元素
    v.erase(2);
    print(v);

    // count
    cout << v.count(2) << endl;
    cout << v.empty() << endl;
    cout << v.size() << endl;

    return 0;
}