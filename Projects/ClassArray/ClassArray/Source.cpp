#include <iostream>
#include <string>
using namespace std;

class Human
{
private:
	int Age;
	string Name;

public:
	Human()
		: Name("x"), Age(0)
	{
		cout << "Constructed a Human called " << Name;
		cout << ", " << Age << " years old" << endl;
	}

	Human(string InputName, int InputAge = 0)
		: Name(InputName), Age(InputAge)
	{
		cout << "Constructed a Human called " << Name;
		cout << ", " << Age << " years old" << endl;
	}

	~Human()
	{
		cout << "Destroyed a Human called " << Name;
		cout << ", " << Age << " years old" << endl;
	}

	void IntroduceSelf() const
	{
		cout << "I am " + Name << " and am ";
		cout << Age << " years old" << endl;
	}
};

int main()
{
	Human FirstMan("Adam");
	Human FirstWoman("Eve", 28);
	Human* Family = new Human[5];

	FirstMan.IntroduceSelf();
	FirstWoman.IntroduceSelf();

	for (int i = 0; i<5; i++)
	{
		cout << "Family member #" << i + 1 << ": ";
		Family[i].IntroduceSelf();
	}

	delete[] Family;

	return 0;
}
