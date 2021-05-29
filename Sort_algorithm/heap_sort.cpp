#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void heapify(vector<T> &tree, int n, int i)
{
    // 获取i节点的两个儿子节点
    int c1 = 2 * i + 1;
    int c2 = 2 * i + 2;
    int max = i;
    if (c1 <= n && tree[c1] > tree[max])
        max = c1;
    if (c2 <= n && tree[c2] > tree[max])
        max = c2;
    if (max != i)
    {
        swap(tree[max], tree[i]);
        heapify(tree, n, max);
    }
}

template <typename T>
void build_heap(vector<T> &tree, int n)
{
    for (int i = n; i > 0; i--)
    {
        int parent = (i - 1) / 2;
        heapify(tree, n, parent);
    }
}

template <typename T>
vector<T> heap_sort(vector<T> &tree, int n)
{
    vector<T> result;
    while (tree.size() > 0)
    {
        build_heap(tree, tree.size() - 1);
        result.insert(result.begin(), tree.front());
        tree.erase(tree.begin());
    }
    return result;
}

int main()
{
    vector<int> v{0, 6, 8, 5, 9, 3, 2, 4, 7, 5, 5, 1};
    vector<int> result = heap_sort(v, 9);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }
    return 0;
}