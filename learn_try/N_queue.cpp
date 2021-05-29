#include <iostream>
#include <vector>
using namespace std;

void print(vector<vector<int>> array);
void change_queue(vector<vector<int>> &array, int i, int j)
{
    for (int m = 0; m < array.size(); m++)
    {
        array[i][m] = 1;
        array[m][j] = 1;
        if (i - m >= 0 && j - m >= 0)
            array[i - m][j - m] = 1;
        if (i + m < array.size() && j + m < array.size())
            array[i + m][j + m] = 1;
        if (i - m >= 0 && j + m < array.size())
            array[i - m][j + m] = 1;
        if (i + m < array.size() && j - m >= 0)
            array[i + m][j - m] = 1;
    }
}

void print(vector<vector<int>> array)
{
    for (int i = 0; i < array.size(); i++)
    {
        for (int j = 0; j < array[i].size(); j++)
            cout << array[i][j] << " ";
        cout << endl;
    }
}

void N_queue(vector<vector<int>> &array, int index, vector<vector<int>> &res, vector<int> &path)
{
    if (index == array.size())
    {
        res.push_back(path);
        return;
    }
    for (int i = 0; i < array.size(); i++)
    {
        if (array[index][i] == 1)
            continue;
        path.push_back(i);
        vector<vector<int>> now_queue = array;
        change_queue(array, index, i);
        N_queue(array, index + 1, res, path);
        array = now_queue;
        path.pop_back();
    }
}

void print_queen(int N, vector<vector<int>> queen)
{
    for (int i = 0; i < queen.size(); i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                if (queen[i][j] == k)
                    cout << 1 << " ";
                else
                    cout << 0 << " ";
            }
            cout << endl;
        }
        cout << "---------" << endl;
    }
}

int main()
{
    int N;
    cin >> N;
    vector<vector<int>> queue_list;
    for (int i = 0; i < N; i++)
    {
        vector<int> path;
        for (int i = 0; i < N; i++)
            path.push_back(0);
        queue_list.push_back(path);
    }
    vector<vector<int>> res;
    vector<int> path;
    N_queue(queue_list, 0, res, path);
    cout << "结果：" << endl;
    // cout<<res.size() << endl;
    print_queen(N, res);

    return 0;
}