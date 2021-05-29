#include <iostream>
using namespace std;

// extern int d = 10; 默认外部链接

int a = 10;        //全局区
static int b = 20; //静态区，全局区和静态区是相邻的

// 内部链接和外部链接的区别？
// 1、如果变量是内部链接的话，那么这个变量只能在文件内部访问
// 2、如果变量是外部链接，那么此变量可以被其他文件使用

void test01()
{
    int c = 30; //静态区
    cout << &c << endl;
}

int main()
{
    cout << &a << endl;
    cout << &b << endl;
    test01();
    return 0;
}