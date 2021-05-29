#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> res;
    vector<int> choose;

    void dfs(int cur, vector<int> &nums)
    {
        if (cur == nums.size())
        {
            res.push_back(choose);
            return;
        }
        choose.push_back(nums[cur]);
        dfs(cur + 1, nums);
        choose.pop_back();
        dfs(cur + 1, nums);
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        dfs(0, nums);
        return res;
    }
};

int main()
{
    vector<int> nums = {1, 2, 3};
    Solution a;
    vector<vector<int>> result = a.subsets(nums);
    for (int i = 0; i < result.size(); i++)
    {
        cout << "{";
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << "}";
    }

    return 0;
}