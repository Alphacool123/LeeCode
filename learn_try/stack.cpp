#include <iostream>
#include <stack>
#include <unordered_set>
using namespace std;

void newstack(stack<int> ss)
{
    stack<int> sg = ss;
    while (!sg.empty())
    {

        cout << "\t" << sg.top();
        sg.pop();
    }
    cout << "\n";
}

int main()
{
    unordered_set<int> seen;
    stack<int> newt;
    newt.push(55);
    newt.push(44);
    newt.push(33);
    newt.push(22);

    cout << newt.top() << endl;
    cout << newt.size() << endl;
    newt.pop();
    cout << newt.size() << endl;

    return 0;
}