#include <iostream>
#include <list>
using namespace std;

struct Person
{
    int happy;
    list<Person> college;
    Person(int happy, list<Person> &A) : happy(happy), college(A) {}
};

struct info
{
    int yes;
    int no;

    info(int x, int y) : yes(x), no(y) {}
};

info *process(Person *root)
{
    if (root->college.empty())
    {
        return new info(root->happy, 0);
    }
    int yes = 0;
    int no = 0;
    for (auto itr = root->college.begin(); itr != root->college.end(); itr++)
    {
        yes += process(&(*itr))->no;
        no += max(process(&(*itr))->yes, process(&(*itr))->no);
    }

    return new info(yes + root->happy, no);
}

int main()
{

    return 0;
}