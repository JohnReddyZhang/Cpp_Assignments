#include <iostream>
using namespace std;

class Fish
{
public:
	void Swim()
	{
		cout << "Fish swims... !" << endl << endl;
	}
};

class Tuna : private Fish
{
public:
	void Sleep()
	{
		cout << "Tuna sleeps..." << endl;
		cout << "Called from the Tuna object: ";
		Swim(); // still accessible, but now considered as a private member
	}
};

class Yellowfin : private Tuna
{
public:
	void Eat()
	{
		cout << "Yellowfin eats..." << endl;
		//Swim(); // no longer accessible, as private in Tuna
		cout << "Called from the Yellowfin object: ";
		Sleep(); // still accessible, but now considered as a private member
		cout << endl;
	}
};
int main()
{
	Fish base;
	base.Swim(); // OK, as public in Fish

	Tuna myDinner;
	myDinner.Sleep(); // OK, as public in Tuna
					  //myDinner.Swim(); // not accessible, as now considered private in Tuna

	Yellowfin mySushi;
	mySushi.Eat(); // OK, as public in Yellowfin
				   //mySushi.Sleep(); // not accessible, as now considered private in Yellowfin
				   //mySushi.Swim(); // not accessible, as considered private in Tuna


	return 0;

}

