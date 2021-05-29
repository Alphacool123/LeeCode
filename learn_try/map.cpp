#include <iostream>
#include <map>
using namespace std;

void print(map<int, int> &_map)
{
    map<int, int>::iterator iter = _map.begin();
    while (iter != _map.end())
    {
        cout << iter->first << ":" << iter->second << endl;
        iter++;
    }
}

int main()
{
    map<int, int> _map;
    // map添加元素
    _map[0] = 1;
    _map[1] = 2;
    _map[2] = 10;

    map<int, int>::iterator iter;
    print(_map);

    // 判断map是否为空
    cout << _map.empty() << endl;

    // 判断map大小
    cout << _map.size() << endl;

    // 插入元素
    _map.insert(pair<int, int>(3, 5));
    _map.insert(pair<int, int>(100, 3));
    _map.insert(pair<int, int>(5, 15));
    print(_map);

    return 0;
}