#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<string> permutation(string s)
    {
        sort(s.begin(), s.end());
        vector<string> res;
        vector<int> check(s.length(), 0);
        string path;
        trace_back(s, res, path, check);
        return res;
    }

    void trace_back(string &s, vector<string> &res, string &path, vector<int> &check)
    {
        if (path.size() == s.size())
        {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < s.length(); i++)
        {
            if (check[i] == 1)
                continue;
            if (i > 0 && s[i] == s[i - 1] && check[i - 1] == 0)
                continue;
            check[i] = 1;
            path += s[i];
            trace_back(s, res, path, check);
            path.erase(path.end() - 1);
            check[i] = 0;
        }
    }
};

int main()
{
    Solution a;
    string s = "abc";
    vector<string> b = a.permutation(s);
    cout << b.size() << endl;
    for (int i = 0; i < b.size(); i++)
        cout << b[i] << endl;

    return 0;
}