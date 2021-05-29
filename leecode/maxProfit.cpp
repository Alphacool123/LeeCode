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

        int *dp = new int[prices.size()];
        int min_price = prices[0];
        for (int i = 0; i < prices.size(); i++)
        {
            min_price = min_price < prices[i] ? min_price : prices[i];
            dp[i] = prices[i] - min_price;
        }
        int res = dp[0];
        for (int i = 0; i < prices.size(); i++)
        {
            res = max(res, dp[i]);
        }
        return res;
    }
};

int main()
{
    Solution a;
    vector<int> v{1, 2, 3, 4, 5};
    cout << a.maxProfit(v);
    return 0;
}