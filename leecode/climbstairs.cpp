#include <iostream>
using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        int step1 = 1;
        int step2 = 2;
        int step3;
        for (int i = 3; i <= n; i++)
        {
            step3 = step1 + step2;
            step1 = step2;
            step2 = step3;
        }
        return step3;
    }
};

int main()
{
    Solution a;
    int n;
    cin >> n;
    cout << a.climbStairs(n);
    return 0;
}