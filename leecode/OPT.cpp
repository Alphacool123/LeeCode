#include <iostream>
#include <vector>
using namespace std;

int rec_opt(vector<int> &array, int n)
{
    if (n == 0)
        return array[0];
    if (n == 1)
        return max(array[0], array[1]);
    return max(rec_opt(array, n - 1), array[n] + rec_opt(array, n - 2));
}

int dp_opt(vector<int> &array, vector<int> &options, int n)
{
    if (n == 0)
        return array[0];
    if (n == 1)
        return max(array[0], array[1]);
    if (n > 1)
    {
        options[0] = array[0];
        options[1] = max(array[1], array[0]);
        for (int i = 2; i < n + 1; i++)
        {
            options[i] = max(options[i - 1], array[i] + options[i - 2]);
        }
        return options[n];
    }
}

int main()
{
    vector<int> v1 = {1, 2, 4, 1, 7, 8, 3};
    vector<int> v2 = {0, 0, 0, 0, 0, 0, 0};
    cout << rec_opt(v1, 6) << endl;
    cout << dp_opt(v1, v2, 6) << endl;
    return 0;
}