#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<string> letterCasePermutation(string S)
    {
    }
};

int main()
{
    Solution a;
    string s("a1b2");
    vector<string> b = a.letterCasePermutation(s);
    for (int i = 0; i < b.size(); i++)
        cout << b[i] << endl;

    return 0;
}