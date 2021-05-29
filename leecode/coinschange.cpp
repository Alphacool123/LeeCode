#include <iostream>
#include <vector>
using namespace std;

const int coins_max = 10000;

class Solution
{
public:
    /**
     * @param coins: a list of integer
     * @param amount: a total amount of money amount
     * @return: the fewest number of coins that you need to make up
     */
    int coinChange(vector<int> &coins, int amount)
    {
        // write your code here
        int *dp = new int[amount + 1];
        dp[0] = 0;
        for (int i = 1; i <= amount; i++)
        {
            dp[i] = coins_max;
            for (int j = 0; j < coins.size(); j++)
                if (i - coins[j] < 0)
                    dp[i] = min(dp[i], coins_max);
                else
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
        }
        if (dp[amount] == coins_max)
            return -1;
        else
            return dp[amount];
    }
};

int main()
{
    Solution a;
    vector<int> v{2};
    cout << a.coinChange(v, 3);
    return 0;
}