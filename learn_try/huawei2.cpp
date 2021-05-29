#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string str1;
    vector<int> nums;
    getline(cin, str1);
    int pos = 0;
    int found = str1.find(",");
    while (found != string::npos)
    {
        nums.push_back(atoi(str1.substr(pos, found - pos).c_str()));
        pos = found + 1;
        found = str1.find(",", found + 1);
    }
    nums.push_back(atoi(str1.substr(pos, str1.size() - pos).c_str()));

    for (int i = 0; i < nums.size(); i++)

    {
        cout << nums[i];
        if (i == nums.size() - 1)
            continue;
        cout << ",";
    }

    return 0;
}