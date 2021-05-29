#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices)
    {
        // write your code here
        int n = prices.size();
        if (n == 0 || n == 1)
            return 0;
        int *dp = new int[n];
        int min_price = prices[0];
        dp[0] = 0;
        for (int i = 1; i < n; i++)
        {
            if (prices[i] > min_price)
                dp[i] = dp[i - 1] + prices[i] - min_price;

            else
                dp[i] = dp[i - 1];
            min_price = prices[i];
        }
        return dp[n - 1];
    }
};

int main()
{
    Solution a;
    vector<int> v{2, 1, 2, 0, 1};
    cout << a.maxProfit(v);

    return 0;
}