#include <iostream>
#include <cstdio>
#include <list>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n;
vector<list<int>> graphs;
bool visited[100] = {0};
void dfs(int v)
{
    list<int>::iterator it;
    visited[v] = true;
    printf("%5d", v);
    for (it = graphs[v].begin(); it != graphs[v].end(); ++it)
    {
        if (!visited[*it])
        {
            dfs(*it);
        }
    }
}

int main()
{
    cout << "input the vertex num:" << endl;
    cin >> n;
    vector<list<int>>::iterator it;
    for (int i = 0; i < n; ++i)
    {
        list<int> i1;
        int t;
        while (cin >> t && t != n)
            i1.push_back(t);
        graphs.push_back(i1);
    }
    cout << "result for bfs:" << endl;
    dfs(0);

    return 0;
}