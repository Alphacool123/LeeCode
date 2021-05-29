#include <iostream>
#include <cstring>

using namespace std;

int main()
{

    char site[7] = {'R', 'U', 'N', 'O', 'O', 'B', '\0'};
    string str1 = "runoobe";
    string str2 = "google";

    cout << strlen(site) << endl;

    cout << str1 + str2 << endl;

    cout << site << endl;

    return 0;
}