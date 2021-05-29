#include <iostream>
using namespace std;

class Base3
{
public:
     int m_A;

protected:
     int m_B;

private:
     int m_C;
};
class Son3 : private Base3
{
public:
     void func()
     {
          m_A; //可访问 private权限
          m_B; //可访问 private权限
               //m_C; //不可访问
     }
};

int main()
{
     return 0;
}