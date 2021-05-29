#include <iostream>
#include <cmath>
using namespace std;

const double EPS = 0.0000001;

double sqrt1(double x)
{
    if (x < -EPS)
        return NAN;
    double low = 0.0;
    double high, num, mid;
    if (x >= 1)
    {
        high = x;
        num = x;
    }
    else
    {
        high = 1 / x;
        num = 1 / x;
    }

    while ((high - low) > EPS)
    {
        mid = (high + low) / 2;
        if (mid * mid > num)
            high = mid;
        else
            low = mid;
    }

    if (x > 1.0)
        return (high + low) / 2;
    else
        return 2 / (high + low);
}

int main()
{

    int n;
    cin >> n;
    double test = 0;
    cout << "sqrt\tsqrt1\t" << endl;
    for (int i = 0; i < n; i++)
    {
        test = rand() / 10000;
        double s = sqrt(test);
        double s1 = sqrt1(test);
        cout << s << "\t" << s1 << "\t" << endl;
    }

    return 0;
}
