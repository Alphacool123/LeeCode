#include <iostream>
#include <string>
#include <set>
using namespace std;

int solution(string &S)
{
    int *letter = new int[26];
    for (int i = 0; i < 26; i++)
        letter[i] = 0;
    for (int i = 0; i < S.length(); i++)
    {
        letter[(int)(S[i] - 'a')] += 1;
    }
    set<int> num_used;
    for (int i = 0; i < 26; i++)
    {
        if (letter[i] != 0)
        {
            while(num_used.find(letter[i])!=num_used.end())
            {
                letter[i]--;
            }
            
        }
    }

    int main()
    {
        string str;
        cin >> str;
        solution(str);
        return 0;
    }