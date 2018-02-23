#include <iostream>
using namespace std;

const int MYSTACK_SIZE = 100;

class myStack
{
private:
	int count;			// number of items in the myStack
	int data[MYSTACK_SIZE];
public:
	myStack();
	~myStack();
	void push(const int item);	// push an item on the myStack
	int pop();			// pop item off the myStack
	int getCount() const;	// return count
};

myStack::myStack()	// constructor
{
	count = 0;	// zero the myStack
}

myStack::~myStack() {}	// destructor

void myStack::push(const int item)
{
	if (count < MYSTACK_SIZE)
	{
		data[count] = item;
		++count;
	}
	else cout << "Overflow!\n";
}

int myStack::pop()
{
	if (count >0)
	{
		--count;
		return (data[count]);
	}
	else
	{
		cout << "Underflow!\n";
		return 0;
	}
}

int myStack::getCount() const
{
	return count;
}

#pragma once
