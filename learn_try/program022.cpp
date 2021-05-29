#include <iostream>
using namespace std;



int main()
{
    double pi = 3.14;
    double *ptr = &pi;
    const double *cptr = &pi;
    cptr = &pi;

    return 0;
}