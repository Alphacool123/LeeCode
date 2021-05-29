#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

void reverse_string(string &str, int left, int right)
{
    string sub_str = str.substr(left + 1, right - left - 1);
    for (int i = 0; i < sub_str.size(); i++)
    {
        str[left + 1 + i] = sub_str[sub_str.size() - 1 - i];
    }
}

int main()
{
    string str;
    stack<int> num_list;
    cin >> str;
    vector<string> result;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(')
            num_list.push(i);
        if (str[i] == ')')
        {
            int pre = num_list.top();
            num_list.pop();
            reverse_string(str, pre, i);
        }
    }
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(' || str[i] == ')')
            continue;
        cout << str[i];
    }
}