#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    /**
     * @param A: An array of non-negative integers
     * @return: The maximum amount of money you can rob tonight
     */
    long long houseRobber(vector<int> &A)
    {
        // write your code here
        int n = A.size();
        if (n == 0)
            return 0;
        int *dp = new int[n + 1];
        dp[0] = 0;
        dp[1] = A[0];
        for (int i = 2; i <= n; i++)
        {
            dp[i] = max(A[i - 1] + dp[i - 2], dp[i - 1]);
        }
        return dp[n];
    }
};

int main()
{
    Solution a;
    vector<int> v{5, 2, 1, 3};
    cout << a.houseRobber(v);

    return 0;
}