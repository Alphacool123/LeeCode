#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    /**
     * @param s: a string,  encoded message
     * @return: an integer, the number of ways decoding
     */
    int numDecodings(string &s)
    {
        if (s.length() == 0 || s[0] == '0')
            return 0;
        vector<int> dp(s.length() + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= s.length(); i++)
        {
            if (s[i - 1] != '0')
                dp[i] += dp[i - 1];
            if (atoi(s.substr(i - 2, 2).c_str()) >= 10 && atoi(s.substr(i - 2, 2).c_str()) <= 26)
                dp[i] += dp[i - 2];
            if (!dp[i])
                return 0;
        }
        return dp.back();
    }
};

int main()
{
    Solution a;
    string s = "10";
    cout << a.numDecodings(s);
    return 0;
}