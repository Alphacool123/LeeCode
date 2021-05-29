#include <iostream>
#include <vector>
#include <set>
using namespace std;

int solution(vector<int> A)
{
    set<int> seen;
    for (int i = 0; i < A.size(); i++)
    {
        seen.insert(A[i]);
    }
    int length = seen.size();
    int max_len = A.size();
    set<int> seen2;
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = i; j < A.size(); j++)
        {
            seen2.insert(A[j]);
            if (seen2.size() == length)
            {
                max_len = min(max_len, j - i + 1);
                break;
            }
        }
        seen2.clear();
    }
    return max_len;
}

int main()
{
    int N;
    cin >> N;
    vector<int> res;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        res.push_back(a);
    }
    cout << solution(res);

    return 0;
}