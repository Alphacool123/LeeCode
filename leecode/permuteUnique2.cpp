#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
    void trace_back(vector<int> &nums, int i, vector<vector<int>> &result)
    {
        if (i == nums.size())
        {
            result.push_back(nums);
            return;
        }
        map<int, bool> visited;
        for (int j = i; j < nums.size(); j++)
        {
            if (!visited[nums[j]])
            {
                visited[nums[j]] = true;
                swap(nums[j], nums[i]);
                trace_back(nums, i + 1, result);
                swap(nums[j], nums[i]);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> result;
        trace_back(nums, 0, result);
        return result;
    }
};

int main()
{
    Solution a;
    vector<vector<int>> result;
    vector<int> nums{1, 1, 3};
    result = a.permuteUnique(nums);
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
            cout << result[i][j] << " ";
        cout << endl;
    }

    return 0;
}