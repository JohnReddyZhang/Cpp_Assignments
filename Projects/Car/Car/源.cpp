#include <iostream>
using namespace std;

class Fish
{
public:
	virtual void Swim()
	{
		cout << "Fish swims!" << endl;
	}
};

class Tuna : public Fish
{
public:
	// override Fish::Swim
	void Swim()
	{
		cout << "Tuna swims!" << endl;
	}
};

class Carp : public Fish
{
public:
	// override Fish::Swim
	void Swim()
	{
		cout << "Carp swims!" << endl;
	}
};

void MakeFishSwim(Fish& InputFish)
{
	cout << "MFS Obj ADD: " << &InputFish << endl;
	// calling Fish::Swim
	InputFish.Swim();
}

int main()
{
	Tuna myDinner;
	Carp myLunch;
	Fish Anything;
	// calling Tuna::Swim
	myDinner.Swim();
	cout << "main myDinner add " << &myDinner << endl;
	cout << "main myLunch add " << &myLunch << endl;
	// sending Tuna as Fish
	MakeFishSwim(myDinner);
	MakeFishSwim(myLunch);
	MakeFishSwim(Anything);

	return 0;
}
