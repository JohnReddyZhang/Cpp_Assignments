#include <iostream>
using namespace std;

class sample
{
private:
	int ctr;
	// static member variables need to be defined outside of the class:
	static int static_ctr;
	// static constants do not need to be defined outside of the class:
	static const int myconst = 5;
public:
	sample() { ctr = 0; }
	static void increment_static_ctr() { static_ctr++; }
	void increment_ctr() { ctr++; }
	int get_ctr() const { return ctr; }
	// can and should be declared static:
	static int get_static_ctr() { return static_ctr; }
};

// definition of the static member of the sample class:
int sample::static_ctr = myconst;

int main()
{
	sample object1, object2;
	cout << "ctr and static_ctr in object1 and object2 are:\n";
	// static member method can be called from an object:
	cout << "object1: " << object1.get_ctr() << ", " << object1.get_static_ctr()
		<< endl;
	// preferred syntax, static member method is called from the class:
	cout << "object2: " << object2.get_ctr() << ", " << sample::get_static_ctr()
		<< endl << endl;

	cout << "Incrementing ctr and static_ctr in object1..." << endl;
	object1.increment_ctr();
	sample::increment_static_ctr();
	cout << "new ctr and static_ctr in object1: " << object1.get_ctr() << ", "
		<< sample::get_static_ctr() << endl;
	cout << "ctr and static_ctr in object2 now are: " << object2.get_ctr()
		<< ", " << sample::get_static_ctr() << endl << endl;

	cout << "Incrementing ctr and static_ctr in object2 twice..." << endl;
	object2.increment_ctr();
	object2.increment_ctr();
	sample::increment_static_ctr();
	sample::increment_static_ctr();
	cout << "new ctr and static_ctr in object2: " << object2.get_ctr() << ", "
		<< sample::get_static_ctr() << endl;
	cout << "and ctr and static_ctr in object1 now are: " << object1.get_ctr()
		<< ", " << sample::get_static_ctr() << endl << endl;

	return 0;
}

