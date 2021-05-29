#include <vector>
#include <iostream>
#include <map>

using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int n = nums.size();
        int slow = 0, fast = 0;
        while (fast < n)
        {
            if (nums[fast] == 0)
            {
                fast++;
            }
            else if (nums[fast] != 0 || nums[slow] != 0)
            {
                if (fast != slow)
                    nums[slow] = nums[fast++];
                slow++;
            }
            else if (nums[fast] != 0 || nums[slow] == 0)
            {
                nums[slow] = nums[fast++];
                slow++;
            }
        }
        while (slow < n)
        {
            nums[slow++] = 0;
        }
    }
};

int main()
{
    vector<int> v{0, 1, 0, 1, 2, 3};
    Solution a;
    a.moveZeroes(v);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
    return 0;
}