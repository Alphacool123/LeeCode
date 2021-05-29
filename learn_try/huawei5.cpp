#include <iostream>
#include <string>
#include <stack>
using namespace std;

void reverse_list(string &str, int left, int right)
{
    string sub_str = str.substr(left + 1, right - left - 1);
    for (int i = 0; i < sub_str.length(); i++)
    {
        str[left + i + 1] = sub_str[sub_str.length() - 1 - i];
    }
}

int main()
{
    string str;
    cin >> str;

    stack<int> seen;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(')
            seen.push(i);
        if (str[i] == ')')
        {
            reverse_list(str, seen.top(), i);
            seen.pop();
        }
    }

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(' || str[i] == ')')
            continue;
        cout << str[i];
    }

    return 0;
}