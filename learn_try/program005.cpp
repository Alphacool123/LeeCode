#include <iostream>

using namespace std;

class Line
{
public:
    int getLength(void);
    Line(int len);
    Line(const Line &obj);
    ~Line();

private:
    int *ptr;
};

Line::Line(int len)
{
    cout << "调用构造函数" << endl;
    //为指针分配内存
    ptr = new int;
    *ptr = len;
}

Line::Line(const Line &obj)
{
    cout << "调用拷贝构造函数为指针ptr分配内存" << endl;
    ptr = new int;
    *ptr = *obj.ptr;
}

Line::~Line(void)
{
    cout << "释放内存" << endl;
}
int Line::getLength(void)
{
    return *ptr;
}

void display(Line obj)
{
    cout << "Line的大小" << obj.getLength() << endl;
}

int main()
{
    Line line1(10);
    Line line2 = line1;

    display(line1);
    display(line2);

    return 0;
}
