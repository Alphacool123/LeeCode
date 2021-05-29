#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() <= 1)
            return nums.size();
        int slow = 0;
        int fast = 1;
        while (fast < nums.size())
        {
            if (nums[slow] == nums[fast])
            {
                fast++;
                continue;
            }
            if (nums[fast] != nums[slow])
            {
                slow++;
                nums[slow] = nums[fast];
                fast++;
            }
        }
        return slow + 1;
    }
};

int main()
{
    Solution a;
    vector<int> b{1, 1, 2};
    cout << a.removeDuplicates(b);

    return 0;
}