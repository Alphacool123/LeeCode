#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

void merge(char *a, int n, char *b, int m)
{
    strcat(a, b);
}

int main()
{
    char a = 'b';
    char b = 'a'; 
    if (a > b)
        cout << "ture";
    else
        cout << "false";
    return 0;
}