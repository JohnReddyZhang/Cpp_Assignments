#include <iostream>
#include "myStack.h"
using namespace std;

class number
{
	int inputNumber; //IS THIS NECESSARY?
public:
	virtual void compute(int Base) = 0;
	virtual void print_it() = 0;
	virtual ~number() {};
};

class binary: public number
{
protected:
	int IntNumber;
	int binary_count = 0;
public:
	binary(int InputNumber) :IntNumber(InputNumber){};
	void print_it(){
		cout << "The binary value is: ";
		compute(2);
		cout << endl;
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
			binary_count++;
			if (binary_count == 4)
			{
				cout << ' ';
				binary_count = 0;
			}
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
		cout << "The hexadecimal value is: ";
		compute(16);
		cout << endl;
	}
	void compute(int Base)
	{
		myStack a_stack;
		int intValue = IntNumber;
		//cout << "hex " << intValue << endl; //for test
		int intBuffer = 0;
		while (intValue != 0)
		{
			intBuffer = intValue % Base;
			//cout << "pushing intBuffer: " << intBuffer << endl; //for test
			a_stack.push(intBuffer);
			intValue = intValue / Base;
			//cout << "now intValue is " << intValue << endl; //for test

		}
		
		while (a_stack.getCount())
		{
			int output = a_stack.pop();
//			cout << "popping output: " << output << endl; //for test
			if (output > 9) cout << (char)('A' + output - 10);
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
	//number n(intInput); // to demonstrate abstract class //passed
	system("pause");
	return 0;
}
