#include <iostream>
#include "myStack.h"
using namespace std;

class number
{
	int inputNumber;
public:
	virtual void compute(int Base) = 0;
	virtual void print_it() = 0;
	virtual ~number() {};
};

class binary: public number
{
protected:
	int IntNumber;
public:
	binary(int InputNumber) :IntNumber(InputNumber){};
	void print_it(){
		compute(2);
	};
	void compute(int Base)
	{
		myStack a_stack;
		int intValue = IntNumber;
		int intBuffer = 0;
		while (intValue != 0)
		{
			intBuffer = intValue % Base;
			a_stack.push(intBuffer);
			intValue = intValue / Base;
		}
		while (a_stack.getCount())
		{
			int output = a_stack.pop();
			cout << output;
		}
	}
	~binary() {};
};

class hexadecimal: public number
{
protected:
	int IntNumber;
public:
	hexadecimal(int InputNumber) :IntNumber(InputNumber) {};
	void print_it()
	{
		compute(16);
	}
	void compute(int Base)
	{
		myStack a_stack;
		int intValue = IntNumber;
		int intBuffer = 0;
		while (intValue != 0)
		{
			intBuffer = intValue % Base;
			a_stack.push(intBuffer);
			intValue = intValue / Base;
		}
		while (a_stack.getCount())
		{
			int output = a_stack.pop();
			if (output > 9) cout << ('A' + output - 10) << endl;
			else cout << output;		
		}
	}
	~hexadecimal() {};
};

int main()
{
	int inputNumber = 0;
	cout << "Please enter the number you want to convert: ";
	cin >> inputNumber;
	number* pNumber;
	pNumber = new binary(inputNumber);
	pNumber->print_it();
	delete pNumber;
	pNumber = new hexadecimal(inputNumber);
	pNumber->print_it();
	delete pNumber;
	return 0;
}
