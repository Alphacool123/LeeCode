#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

int DFS(int n)
{
    if (n == 1 || n == 2)
        return 1;
    return DFS(n - 1) + DFS(n - 2);
}

int DP(int n)
{
    if (n <= 2)
        return 1;
    int *a = new int[n];
    a[0] = 1;
    a[1] = 1;
    for (int i = 2; i < n; i++)
    {
        a[i] = a[i - 1] + a[i - 2];
    }
    return a[n - 1];
}

int main()
{
    cout << DFS(1);
    // cout << DP(55);
    return 0;
}