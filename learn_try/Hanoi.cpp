#include <iostream>
#include <cstdio>

using namespace std;
 
void hannoi (int n, char A, char B, char C)
{
    if (n == 1)
    {
        cout << A << C << endl;
    }
    else
    {
        hannoi (n-1, A, C, B);
        cout << A << C << endl;
        hannoi (n-1, B, A, C);
    }
}
 
int main()
{
    int n;
    cin >> n;
    hannoi (n, 'a', 'b', 'c');
    return 0;
}