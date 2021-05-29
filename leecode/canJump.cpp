#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int i = 0;
        while (i < nums.size())
        {
            if (i == nums.size() - 1)
                return true;
            if (nums[i] == 0)
                return false;
            i += nums[i];
        }
        return false;
    }
};

int main()
{
    Solution a;
    vector<int> v = {2, 3, 1, 1, 4};
    int b = a.canJump(v);
    cout << bool(b);
    return 0;
}