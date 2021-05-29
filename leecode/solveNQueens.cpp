#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename T>
void print(vector<vector<T>> &array)
{
    for (int i = 0; i < array.size(); i++)
    {
        for (int j = 0; j < array[i].size(); j++)
            cout << array[i][j] << " ";
        cout << endl;
    }
    cout << "------------" << endl;
}

class Solution
{
public:
    vector<vector<int>> init_queen(int n)
    {
        vector<vector<int>> result;
        for (int i = 0; i < n; i++)
        {
            vector<int> path;
            for (int j = 0; j < n; j++)
                path.push_back(0);
            result.push_back(path);
        }
        return result;
    }

    void change_queen(vector<vector<int>> &array, int x, int y)
    {
        for (int i = 0; i < array.size(); i++)
        {
            array[x][i] = 1;
            array[i][y] = 1;
            if (x + i < array.size() && y + i < array.size())
                array[x + i][y + i] = 1;
            if (x - i >= 0 && y - i >= 0)
                array[x - i][y - i] = 1;
            if (x + i < array.size() && y - i >= 0)
                array[x + i][y - i] = 1;
            if (x - i >= 0 && y + i < array.size())
                array[x - i][y + i] = 1;
        }
    }

    void N_queens(vector<vector<int>> &put_queen, vector<vector<int>> &res, vector<int> &path, int index)
    {
        if (index == put_queen.size())
        {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < put_queen.size(); i++)
        {
            if (put_queen[index][i] == 1)
                continue;
            path.push_back(i);
            vector<vector<int>> pre = put_queen;
            change_queen(put_queen, index, i);
            N_queens(put_queen, res, path, index + 1);
            put_queen = pre;
            path.pop_back();
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<int>> initail = init_queen(n);
        vector<vector<int>> res;
        vector<int> path;
        N_queens(initail, res, path, 0);
        print(res);
        vector<vector<string>> results;
        for (int i = 0; i < res.size(); i++)
        {
            vector<string> paths;
            for (int j = 0; j < n; j++)
            {
                string str;
                for (int k = 0; k < n; k++)
                {
                    if (res[i][j] == k)
                        str.push_back('Q');
                    else
                        str.push_back('.');
                }
                paths.push_back(str);
            }
            results.push_back(paths);
        }
        return results;
    }
};

int main()
{
    Solution a;
    int n;
    cin >> n;
    vector<vector<string>> res = a.solveNQueens(n);
    print(res);

    return 0;
}