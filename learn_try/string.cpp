#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void print(string &s)
{
    cout << s << endl;
}

void test1()
{
    int n = 10;
    string s1;
    string s2("abc");
    string s3 = s2;
    string s4 = "abc";
    // string s5(n, "abc");
    print(s2);

    // 插入字符串,insert(int,string)
    s2.insert(s2.length(), "d");
    print(s2);

    // 字符长度
    cout << s2.size() << endl;
    cout << s2.length() << endl;

    // 换位置
    swap(s2[1], s2[2]);
    print(s2);

    // 判断是否为空
    cout << s2.empty() << endl;

    // 排序
    sort(s2.begin(), s2.end());
    print(s2);

    // 取其中一段
    string s5(s2.begin() + 1, s2.end());
    print(s5);

    // count
    cout << count(s2.begin(), s2.end(), s5[1]) << endl;

    // 添加元素
    s2 += "e";
    print(s2);

    // 删除元素
    s2.erase(s2.end() - 1);
    print(s2);
}

//string创建
void test2()
{
    string s1;
    const char *str = "hello world";
    string s2(str);
    string s3(s2);
    cout << s2 << endl;
    cout << s3 << endl;
    string s4(10, 'a');
    cout << s4 << endl;
}

//string赋值操作
void test3()
{
    string str1;
    str1 = "hello world";
    cout << str1 << endl;

    string str2 = str1;
    cout << str2 << endl;

    string str4;
    str4.assign("hello C++");
    cout << str4 << endl;

    string str5;
    str5.assign("hello world", 5);
    cout << str5 << endl;

    string str6;
    str6.assign(10, 'a');
    cout << str6 << endl;
}

int main()
{
    test3();
    return 0;
}