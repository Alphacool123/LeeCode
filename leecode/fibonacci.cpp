#include <iostream>
using namespace std;

class Solution
{
public:
    int fib(int n)
    {
        long *a = new long[n + 1];
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        if (n >= 2)
        {
            a[0] = 0;
            a[1] = 1;
            for (int i = 2; i < n + 1; i++)
            {
                a[i] = a[i - 1] + a[i - 2];
            }
        }
        return a[n] % 1000000007;
    }
};

int main()
{
    Solution a;
    cout << a.fib(48) << endl;

    return 0;
}