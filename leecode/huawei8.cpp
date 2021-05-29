#include <iostream>
#include <set>
using namespace std;

void initialise_node(int parent[], int nums)
{
    for (int i = 0; i < nums; i++)
        parent[i] = -1;
}

int find_root(int x, int parent[])
{
    int x_root = x;
    while (parent[x_root] != -1)
        x_root = parent[x_root];
    return x_root;
}

bool Unions_root(int x, int y, int parent[])
{
    int x_root = find_root(x, parent);
    int y_root = find_root(y, parent);
    if (x_root == y_root)
        return true;
    parent[x_root] = y_root;
    return false;
}

int main()
{
    int nodes_nums;
    cin >> nodes_nums;
    int *parent = new int[nodes_nums];
    initialise_node(parent, nodes_nums);
    int n;
    cin >> n;
    int(*nodes)[2] = new int[n][2];
    for (int i = 0; i < n; i++)
    {
        cin >> nodes[i][0] >> nodes[i][1];  
    }

    bool flag = false;
    set<int> link_ndoes;
    for (int i = 0; i < n; i++)
    {
        int x = nodes[i][0];
        int y = nodes[i][1];
        link_ndoes.insert(x);
        link_ndoes.insert(y);
        if (Unions_root(x, y, parent))
            flag = true;
    }

    int score = flag ? 10 - 2 - (nodes_nums - link_ndoes.size()) : 10 - (nodes_nums - link_ndoes.size());
    cout << (score >= 0 ? score : 0) << endl;

    delete[] parent;
    delete[] nodes;
    return 0;
}