#include <iostream>
#include <string>
using namespace std;

int recursion(string const str, int n)
{
    if (n == 1)
        return 1;
    if (n == 2)
        return recursion(str, 1) + (atoi(str.substr(0, 2).c_str()) <= 26 ? 1 : 0);
    return recursion(str, n - 1) + (atoi(str.substr(n - 2, 2).c_str()) <= 26 ? recursion(str, n - 2) : 0);
}

int main()
{
    string str;
    cin >> str;
    int *a = new int(str.size());

    a[0] = 1;
    a[1] = a[0] + (atoi(str.substr(0, 2).c_str()) <= 26 ? 1 : 0);

    for (int i = 2; i < str.size(); i++)
    {
        a[i] = a[i - 1] + (atoi(str.substr(i - 1, 2).c_str()) <= 26 ? a[i - 2] : 0);
    }
    cout << a[str.size() - 1] << endl;

    cout << recursion(str, str.size());
    return 0;
}