#include <iostream>
using namespace std;

int main()
{

    // 一维数组
    // 静态,定义好数组array1，未对数据初始化
    int array1[100];
    // 静态，定义并初始化数组array2
    int array2[100] = {1, 2};

    // 动态，分配了长度为100的数组array3,delete[]很重要
    int *array3 = new int[100];
    delete[] array3;
    // 动态，分配了长度为100的数组array4，并初始化
    int *array4 = new int[100]{11, 2};
    delete[] array4;

    // 二维数组
    // 静态
    int array5[10][10];
    // 静态，定义并初始化
    int array6[10][10] = {{1, 1}, {2, 2}};
    // 动态,但数组坐标的列坐标要确定
    int m;
    int n;
    int(*array7)[10] = new int[m][10];
    delete[] array7;
    // 动态，多次析构
    int **array8 = new int *[m];
    for (int i = 0; i < m; i++)
        array8[i] = new int[n];

    for (int i = 0; i < m; i++)
        delete[] array8[i];

    // 动态,按行存储
    int *array9 = new int[m * n];
    delete[] array8;

    return 0;
}