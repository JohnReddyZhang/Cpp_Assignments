#include <iostream>
using namespace std;

class MyString
{
private:
	char* Buffer;

public:
	// Constructor
	MyString(const char* InitialInput = NULL)
	{
		if (InitialInput != NULL)
		{
			Buffer = new char[strlen(InitialInput) + 1];
			strcpy_s(Buffer, strlen(InitialInput) + 1, InitialInput);
		}
		else
			Buffer = NULL;
	}

	// Copy Constructor
	MyString(const MyString& CopySource)
	{
		if (CopySource.Buffer != NULL)
		{
			Buffer = new char[strlen(CopySource.Buffer) + 1];
			strcpy_s(Buffer, strlen(CopySource.Buffer) + 1, CopySource.Buffer);
		}
		else
			Buffer = NULL;
	}

	~MyString()
	{
		if (Buffer != NULL)
			delete[] Buffer;
	}

	// accessor methods:
	int GetLength() const
	{
		return strlen(Buffer);
	}

	const char* GetString() const
	{
		return Buffer;
	}
};

class Human
{
private:
	int Age;
	bool Gender;
	MyString Name;

public:
	Human(const MyString& InputName, int InputAge, bool InputGender)
		: Name(InputName), Age(InputAge), Gender(InputGender) {}
	// accessor method:
	int GetAge() const
	{
		return Age;
	}
};

int main()
{
	MyString FirstManName("Johnny");
	MyString FirstWomanName("Eve");

	cout << "sizeof(MyString) = " << sizeof(MyString) << endl;
	cout << "sizeof(FirstManName) = " << sizeof(FirstManName) << endl;
	cout << "sizeof(FirstWomanName) = " << sizeof(FirstWomanName) << endl;

	Human FirstMaleHuman(FirstManName, 25, true);
	Human FirstFemaleHuman(FirstWomanName, 18, false);

	cout << "sizeof(Human) = " << sizeof(Human) << endl;
	cout << "sizeof(FirstMaleHuman) = " << sizeof(FirstMaleHuman) << endl;
	cout << "sizeof(FirstFemaleHuman) = " << sizeof(FirstFemaleHuman) << endl;
	system("pause");
	return 0;
}
