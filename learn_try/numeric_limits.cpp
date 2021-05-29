#include <iostream>
#include <limits>
#include <string>
using namespace std;

int main()
{
    cout << numeric_limits<short>::max() << endl;
    cout << numeric_limits<short>::min() << endl;
    cout << numeric_limits<int>::max() << endl;
    cout << numeric_limits<int>::min() << endl;
    cout << numeric_limits<long>::max() << endl;
    cout << numeric_limits<long>::min() << endl;

    cout << numeric_limits<float>::max() << endl;
    cout << numeric_limits<float>::min() << endl;
    cout << numeric_limits<double>::max() << endl;
    cout << numeric_limits<double>::min() << endl;

    return 0;
}