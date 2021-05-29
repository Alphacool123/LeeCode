#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    int *b = new int[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    b[0] = 0;
    for (int i = 1; i < n; i++)
    {
        b[i] = b[i - 1] + 1;
        for (int j = 0; j < i; j++)
        {
            if ((i - j) <= a[j])
                b[i] = min(b[i], b[j] + 1);
        };
    }

    cout << b[n - 1];

    delete[] a;
    delete[] b;
    return 0;
}