#include <iostream>
using namespace std;

class MyString
{
private:
	char* Buffer;

public:
	// default constructor
	MyString(const char* InitialInput = NULL)
	{
		cout << "Default constructor: creating new MyString\n";
		if (InitialInput != NULL)
		{
			Buffer = new char[strlen(InitialInput) + 1];
			strcpy_s(Buffer, strlen(InitialInput) + 1, InitialInput);

			// Display memory address pointed by local buffer
			cout << "Buffer points to: 0x" << hex;
			cout << (unsigned int*)Buffer << endl;
		}
		else
			Buffer = NULL;
	}

	// Destructor
	~MyString()
	{
		cout << "Invoking destructor, clearing up" << endl;
		if (Buffer != NULL)
		{
			cout << "Buffer to be deleted points to: 0x" << hex;
			cout << (unsigned int*)Buffer << endl;
			delete[] Buffer;
		}
	}

	int GetLength() const
	{
		return strlen(Buffer);
	}

	const char* GetString() const
	{
		return Buffer;
	}
};

void UseMyString(MyString Input)
{
	cout << "String buffer in MyString is " << Input.GetLength();
	cout << " characters long" << endl;

	cout << "Buffer contains: " << Input.GetString() << endl;
	return; // Optional statement
}

int main()
{
	MyString SayHello("Hello from String Class");

	// Pass SayHello as a parameter by value to the function (will be copied)
	UseMyString(SayHello);

	return 0;
}
