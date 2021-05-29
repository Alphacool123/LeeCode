#include <iostream>
#include <vector>
using namespace std;

vector<vector<float>> bubble_sort(vector<vector<float>> &array, int k)
{
    int n = array.size();
    vector<float> num(n, 0);
    for (int i = 0; i < n; i++)
    {
        num[i] = array[i][4];
    }

    vector<vector<float>> res;
    while (k > 0)
    {
        int index = 0;
        for (int i = 0; i < n; i++)
        {
            if (num[index] < num[i])
                index = i;
        }
        res.push_back(array[index]);
        num[index] = 0;

        k--;
    }

    return res;
}

int main()
{

    vector<vector<float>> array{
        {5, 4, 2, 1, 6.3}, {1, 5, 4, 2, 8.2}, {1, 5, 4, 2, 1.3}, {1, 5, 4, 2, 100.3}};
    vector<vector<float>> res = bubble_sort(array, 3);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << endl;
    }
    return 0;
}