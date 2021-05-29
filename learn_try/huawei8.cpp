#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int main()
{
    int node_nums;
    cin >> node_nums;

    int n;
    cin >> n;
    map<int, vector<int>> node_class;
    while (n > 0)
    {
        int node1;
        int node2;
        cin >> node1 >> node2;
        if (node_class.find(node1) == node_class.end())
        {
            vector<int> a{node2};
            node_class[node1] = a;
        }
        else
        {
            node_class[node1].push_back(node2);
        }
        n--;
    }

    set<int> visited;
    queue<int> used;
    bool flag = false;
    for (auto itr = node_class.begin(); itr != node_class.end(); itr++)
    {
        used.push(itr->first);
        while (!used.empty())
        {
            int a = used.front();
            if (visited.find(a) != visited.end())
            {
                flag = true;
            }
            visited.insert(a);
            used.pop();
            for (int i = 0; i < node_class[a].size(); i++)
            {
                used.push(node_class[a][i]);
            }
            node_class.erase(a);
        }
    }
    int result = 10;
    if (flag)
        result -= 2;
    result = result - (node_nums - visited.size());
    cout << (result < 0 ? 0 : result);

    return 0;
}
