#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    /**
     * @param nums: An array of integers
     * @return: An integer
     */
    int maxProduct(vector<int> &nums)
    {
        // write your code here
        int *dp = new int[nums.size()];
        dp[0] = nums[0];
        cout << dp[0] << " ";
        for (int i = 1; i < nums.size(); i++)
        {
            if ((i - 2) < 0)
                dp[i] = max(dp[i - 1] * nums[i], nums[i]);
            else
                dp[i] = max(dp[i - 1] * nums[i], max(dp[i - 2], nums[i]));
            cout << dp[i] << " ";
        }
        return dp[nums.size() - 1];
    }
};

int main()
{
    Solution a;
    vector<int> v{2, 3, -2, 4};
    cout << endl;
    cout << a.maxProduct(v);

    return 0;
}