#include <iostream>
using namespace std;

class Solution
{
public:
    int numWays(int n)
    {
        if (n == 0)
            return 1;
        if (n == 1)
            return 1;
        int step1 = 1;
        int step2 = 1;
        int step3;
        for (int i = 2; i <= n; i++)
        {
            step3 = (step1 + step2) % 1000000007;
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
    cout << a.numWays(n);

    return 0;
}