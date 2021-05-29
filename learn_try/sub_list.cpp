#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

void print(vector<int> const &nums)
{
    cout << "{ ";
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << "}";
    cout << " ";
}

void sub_list(vector<int> const &nums, int path, vector<int> result)
{
    if (path == nums.size())
    {
        print(result);
        return;
    }
    vector<int> no = result;
    sub_list(nums, path + 1, no);
    result.push_back(nums[path]);
    vector<int> yes = result;
    sub_list(nums, path + 1, yes);
}

void permutation(vector<int> const &nums, vector<int> path)
{
    if (path.size() == nums.size())
    {
        print(path);
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (count(path.begin(), path.end(), nums[i]) > 0)
            continue;
        path.push_back(nums[i]);
        permutation(nums, path);
        path.pop_back();
    }
}

// 内存空间更小
void permutation2(vector<int> &nums, int i)
{
    if (i == nums.size())
    {
        print(nums);
        return;
    }
    for (int j = i; j < nums.size(); j++)
    {
        swap(nums[i], nums[j]);
        permutation2(nums, i + 1);
        swap(nums[i], nums[j]);
    }
}

void permutation3(vector<int> &nums, int i)
{
    if (i == nums.size())
    {
        print(nums);
        return;
    }
    map<int, bool> visited;
    for (int j = i; j < nums.size(); j++)
    {
        if (!visited[nums[j]] || visited.empty())
        {
            visited[nums[j]] = true;
            swap(nums[i], nums[j]);
            permutation3(nums, i + 1);
            swap(nums[i], nums[j]);
        }
    }
}

int main()
{
    vector<int> nums{1, 1, 3};
    // print(nums);
    // int path = 0;
    // vector<int> result;
    // sub_list(nums, path, result);
    // cout << endl;
    // vector<int> paths;
    // permutation(nums, paths);
    // cout << endl;
    // permutation2(nums, 0);
    // cout << endl;
    permutation3(nums, 0);

    return 0;
}