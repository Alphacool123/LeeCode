#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    /**
     * @param A: A list of integers
     * @return: A boolean
     */
    bool canJump(vector<int> &A)
    {
        bool *dp = new bool[A.size()]();
        dp[0] = true;
        for (int i = 1; i < A.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (A[j] >= (i - j) && dp[j])
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[A.size() - 1];
    }
};

int main()
{
    Solution a;
    vector<int> v{0, 8, 2, 0, 9};
    cout << a.canJump(v);
    return 0;
}