#include <iostream>

using namespace std;

template <typename T>

int compare(const T &left, const T &right)
{

    if (left < right)
    {
        return -1;
    }
    if (right < left)
    {
        return 1;
    }

    return 0;
}

int main()
{
    cout << compare<int>(1, 2) << endl;

    return 0;
}