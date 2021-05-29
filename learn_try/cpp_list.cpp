#include <iostream>
using namespace std;

int main()
{

    // 一维数组
    int value1[100]; //value[i]的值不确定，没有初始化

    int *value2 = new int[100]; //未初始化
    delete[] value2;            //一定不能忘了删除数组空间

    // 二维数组
    int value3[9][9];
    // int *value4 = new int[9][9];
    // int * value = new int[3][4];
    delete[] value4;

    return 0;
}