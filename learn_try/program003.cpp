#include <iostream>
#include <vector>
using namespace std;


int main(){

    vector<int> v;
    v.push_back(0);
    v.push_back(1);
    cout << v[1]<<endl;
    cout << v.size()<<endl;
    cout << &v[0]<<endl;
    cout <<v.capacity()<<endl;
    v.push_back(1);
    cout << &v[0]<<endl;
    cout << v[0]<<endl;
    cout << v.size()<<endl;
    cout <<v.capacity()<<endl;


    return 0;
}