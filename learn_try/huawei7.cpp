#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, max_tables;
    cin >> n >> max_tables;
    int(*p)[3] = new int[n][3];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> p[i][j];
        }
    }
    int *time = new int[24];
    for (int i = 0; i < 24; i++)
        time[i] = 0;
    for (int i = 0; i < n; i++)
    {
        int start = p[i][0];
        int end = p[i][1];
        int people = p[i][2];
        bool flag = true;
        for (int j = start; j < end; j++)
        {
            if ((time[j] + people) > max_tables)
                flag = false;
        }
        if (flag)
        {
            for (int j = start; j < end; j++)
                time[j] = time[j] + people;
        }
    }
    for (int i = 0; i < 24; i++)
        cout << time[i] << " ";

    return 0;
}