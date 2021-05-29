#include <iostream>
#include <cmath>
using namespace std;

int number(int *Array, int left, int right)
{
    int count = 0;
    int sum = 0;
    while (left <= right)
        sum += Array[right--] * pow(10, count++);
    return sum;
}

void print(int **array, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << array[i][j] << "\t"
                 << " ";
        }
        cout << endl;
    }
}

int main()
{
    int num[] = {1, 9, 2, 1, 6, 8, 0, 1};
    int length = sizeof(num) / sizeof(num[0]);
    int **DP = new int *[5];
    for (int i = 0; i < 5; i++)
        DP[i] = new int[length];

    // 初始化
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < length; j++)
        {
            if (i == 0 || j == 0 || i > j)
                DP[i][j] = 0;
        }
    }

    print(DP, 5, length);

    for (int i = 0; i < 5; i++)
        delete[] DP[i];
    delete[] DP;
    return 0;
}