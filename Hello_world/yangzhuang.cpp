#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{

    string s;
    cin >> s;

    vector<int> dp(s.size(), 0);

    int n = s[0] - '0';
    dp[0] = n % 3 == 0 ? 1 : 0;

    for (int i = 1; i < s.size(); i++)
    {
        n = s[i] - '0';
        dp[i] = n % 3 == 0 ? dp[i - 1] + 1 : dp[i - 1];
        for (int j = i - 1; j > 0; j--)
        {
            n = atoi(s.substr(j, i - j + 1).c_str());
            if (n % 3 == 0)
                dp[i] = max(dp[j - 1] + 1, dp[i]);
        }
    }
    cout << dp[s.size() - 1] << endl;

    return 0;
}