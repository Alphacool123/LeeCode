#include <iostream>
#include <ctime>
using namespace std;

#define n 10000

int main()
{
    int c = 0;
    clock_t start, end;
    start = clock();
    for (int i = 0; i < n; i++)
    {
        c++;
    }
    end = clock();
    cout << "The run time is: " << (double)(end - start) / CLOCKS_PER_SEC << "s" << endl;
    return 0;
}