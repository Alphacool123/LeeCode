#include <iostream>
using namespace std;

const int VERTICES = 6;

void initialise(int parent[])
{
    for (int i = 0; i < VERTICES; i++)
        parent[i] = -1;
}

int fint_root(int x, int parent[])
{
    int x_root = x;
    while (parent[x_root] != -1)
        x_root = parent[x_root];
    return x_root;
}

bool union_area(int x, int y, int parent[])
{
    int x_root = fint_root(x, parent);
    int y_root = fint_root(y, parent);
    if (x_root == y_root)
        return true;
    else
        parent[x_root] = y_root;
    return false;
}

int main()
{
    int parent[VERTICES] = {0};
    initialise(parent);

    int eages[5][2] = {{0, 1}, {1, 2}, {1, 3}, {3, 4}, {2, 5}};
    for (int i = 0; i < 5; i++)
    {
        int x = eages[i][0];
        int y = eages[i][1];
        if (union_area(x, y, parent))
        {
            cout << "circle" << endl;
  
        }
    }
    cout << "no circle" << endl;
    return 0;
}