#include <iostream>
#include <vector>
using namespace std;

int maxWater(vector<int> &heights)
{
    int n = heights.size();
    int left = 0, num = 0;
    vector<int> zero_pos;
    while (left < n)
    {
        if (heights[left] == 0)
            zero_pos.push_back(left);
        left++;
    }
    if (zero_pos.size() == 0 || zero_pos.size() == 1)
        return n - 1;
    int count = zero_pos.size();
    for (int i = 1; i < count; i++)
    {
        if (i == 1)
            num = max(num, zero_pos[i] - 1);
        else
            num = max(num, zero_pos[i] - zero_pos[i - 2] - 1);
    }
    return max(num, n - zero_pos[count - 2] - 2);
}

int main()
{
    int a;
    vector<int> v1;
    vector<vector<int>> v2;
    for (int i = 0; i < a; i++)
    {
        int b;
        cin >> b;
        int c;
        for (int j = 0; j < b; j++)
        {
            cin >> c;
            v1.push_back(c);
        }
        v2.push_back(v1);
        v1.clear();
    }

    vector<int> result;

    for (int i = 0; i < v2.size(); i++)
    {
        result.push_back(maxWater(v2[i]));
    }

    return 0;
}