#include <iostream>
// next statement optional, header file included by default (.h !)
#include <string.h>
using namespace std;

int main()
{
	const int MaxLength = 10;
	char String1[] = "123 56 89012345";
	char String2[MaxLength + 1] = { '\0' }; // Leaves room for the additional NULL
	cout << "String1 length: " << strlen(String1) << endl;
	strncpy_s(String2, String1, MaxLength); // Safer than strcpy_s
	cout << "String1: " << String1 << endl;
	cout << "String2: " << String2 << endl;
	return 0;
}