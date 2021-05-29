#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> path;
        vector<int> check(nums.size(), 0);
        trace_back(nums, res, path, check);
        return res;
    }

    void trace_back(vector<int> &nums, vector<vector<int>> &res, vector<int> &path, vector<int> &check)
    {
        if (path.size() == nums.size())
        {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (check[i] == 1)
                continue;
            if (i > 0 && nums[i] == nums[i - 1] && check[i - 1] == 0)
                continue;
            check[i] = 1;
            path.push_back(nums[i]);
            trace_back(nums, res, path, check);
            path.pop_back();
            check[i] = 0;
        }
    }
};

int main()
{
    Solution a;
    vector<int> v{1, 1, 2};
    vector<vector<int>> b = a.permuteUnique(v);
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < b[i].size(); j++)
            cout << b[i][j] << " ";
        cout << endl;
    }
    return 0;
}