#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    /**
     * @param A: An array of Integer
     * @return: an integer
     */

    int longestIncreasingContinuousSubsequence(vector<int> &A)
    {
        // write your code here
        int inc = 1;
        int dec = 1;
        int p1 = 1;
        int p2 = 1;
        for (int i = 1; i < A.size(); i++)
        {
            if (A[i] > A[i - 1])
                p1++;
            else
                p1 = 1;

            if (A[i] < A[i - 1])
                p2++;
            else
                p2 = 1;
            inc = max(inc, p1);
            dec = max(dec, p2);
        }
        return max(inc, dec);
    }
};

int main()
{
    Solution a;
    vector<int> v{5, 1, 2, 3, 4};
    cout << a.longestIncreasingContinuousSubsequence(v);

    return 0;
}