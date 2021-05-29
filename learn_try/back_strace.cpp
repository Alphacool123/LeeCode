#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print(vector<int> nums)
{
    cout << "[";
    for (int i = 0; i < nums.size(); i++)
    {
        if (i == nums.size() - 1)
            cout << " " << nums[i] << "]";
        else
        {
            cout << " " << nums[i] << ",";
        }
    }
    cout << endl;
}

void trace_back(vector<int> &nums, vector<int> &path)
{
    if (path.size() == nums.size())
    {
        print(path);
        return;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (count(path.begin(), path.end(), nums[i]))
            continue;
        path.push_back(nums[i]);
        trace_back(nums, path);
        path.pop_back();
    }
}

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<int> path;
    trace_back(nums, path);

    return 0;
}