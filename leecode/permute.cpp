#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// class Solution
// {
// public:
//     vector<vector<int>> res;
//     vector<int> path;
//     vector<vector<int>> permute(vector<int> &nums)
//     {
//         trace_back(nums, path, res);
//         return res;
//     }

//     void trace_back(vector<int> &nums, vector<int> &path, vector<vector<int>> &res)
//     {
//         if (path.size() == nums.size())
//         {
//             res.push_back(path);
//             return;
//         }
//         for (int i = 0; i < nums.size(); i++)
//         {
//             if (count(path.begin(), path.end(), nums[i]) > 0)
//                 continue;
//             path.push_back(nums[i]);
//             trace_back(nums, path, res);
//             path.pop_back();
//         }
//         return;
//     }
// };

class Solution
{
public:
    void backtrack(vector<vector<int>> &res, vector<int> &output, int first, int len)
    {
        // 所有数都填完了
        if (first == len)
        {
            res.emplace_back(output);
            return;
        }
        for (int i = first; i < len; ++i)
        {
            // 动态维护数组
            swap(output[i], output[first]);
            // 继续递归填下一个数
            backtrack(res, output, first + 1, len);
            // 撤销操作
            swap(output[i], output[first]);
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;
        backtrack(res, nums, 0, (int)nums.size());
        return res;
    }
};

int main()
{
    vector<int> v{1, 2, 3};
    Solution a;
    vector<vector<int>> b = a.permute(v);
    for (int i = 0; i < b.size(); i++)
    {
        for (int j = 0; j < b[i].size(); j++)
        {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}