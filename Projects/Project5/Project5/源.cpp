#include <iostream>
using namespace std;

int main() {
	int Age = 30;
	const double Pi = 3.1416;

	cout << "Inter Age is at: 0x" << &Age << endl;
	cout << "Double Pi at 0x" << &Pi << endl;
	return 0;
}