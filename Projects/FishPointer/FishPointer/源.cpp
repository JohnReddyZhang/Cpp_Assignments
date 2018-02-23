
#include <iostream>
using namespace std;

class Fish
{
public:
	Fish()
	{
		cout << "Constructed Fish" << endl;
	}

	virtual ~Fish() // declaring destructor virtual
	//~Fish()
	{
		cout << "Destroyed Fish" << endl;
	}
};

class Tuna : public Fish
{
public:
	Tuna()
	{
		cout << "Constructed Tuna" << endl;
	}
	~Tuna()
	{
		cout << "Destroyed Tuna" << endl;
	}
};

void DeleteFishMemory(Fish* pFish) // passing Fish*
{
	delete pFish;
}

int main()
{
	cout << "Allocating a Tuna on the free store:\n";
	Tuna* pTuna = new Tuna;
	cout << "\nDeleting the Tuna!!!:\n";
	DeleteFishMemory(pTuna);

	cout << "\nInstantiating a Tuna on the stack:\n";
	Tuna myDinner;
	cout << "\nAutomatic destruction as it goes out of scope:\n";

	return 0;
}
