#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.size() == 1)
            return intervals;
        sort(intervals.begin(), intervals.end());
        vector<int> v = intervals[0];
        vector<vector<int>> result;
        for (int i = 1; i < intervals.size(); i++)
        {
            if (v[1] >= intervals[i][0])
            {
                v = {v[0], max(v[1], intervals[i][1])};
            }
            else
            {
                result.push_back(v);
                v = intervals[i];
            }
        }
        result.push_back(v);
        return result;
    }
};

int main()
{
    vector<vector<int>> v1{{1, 4}, {4, 5}};
    Solution a;
    vector<vector<int>> v2 = a.merge(v1);
    for (int i = 0; i < v2.size(); i++)
    {
        for (int j = 0; j < v2[i].size(); j++)
            cout << v2[i][j] << " ";
        cout << endl;
    }
    return 0;
}