#include <iostream>
#include <string>
using namespace std;

int main()
{
    int N;
    cin >> N;
    string str = to_string(N);
    if (str[0] == '-')
    {
        for (int i = 1; i < str.length(); i++)
        {
            if ((int)(str[i] - '0') >= 5)
            {
                str.insert(str.begin() + i, '5');
                break;
            }
        }
    }
    else
    {
        for (int i = 0; i < str.length(); i++)
        {
            if ((int)(str[i] - '0') < 5)
            {
                str.insert(str.begin() + i, '5');
                break;
            }
        }
    }
    cout << atoi(str.c_str());
}