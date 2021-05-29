#include <iostream>
using namespace std;
const int Max = 3;

int main()
{
	int var[Max] = { 10,100,200 };
	int* ptr = NULL;

	ptr = var;
	for (int i = 0; i < Max; i++) {
		cout << "Address of var [" << i << "]=";
		cout << ptr << endl;

		cout << "Value of var [" << i << "]=";
		cout << *ptr << endl;
		ptr++;
	}

	return 0;
}