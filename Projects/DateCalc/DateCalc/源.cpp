// contains prefix and postfix increment and decrement
#include <iostream>
#include <string>
#include <sstream> // for ostringstream
using namespace std;

enum type { none, preI, preD, postI, postD }; // type of operation

class Date
{
private:
	int Day;  // Range: 1 - 30 (lets assume all months have 30 days!
	int Month;
	int Year;

public:

	// Constructor that initializes the object to a day, month and year
	Date(int InputDay, int InputMonth, int InputYear)
		: Day(InputDay), Month(InputMonth), Year(InputYear) {};

	// Unary increment operator (prefix)
	Date& operator ++ ()
	{
		++Day;
		return *this;
	}

	// Unary decrement operator (prefix)
	Date& operator -- ()
	{
		--Day;
		return *this;
	}

	// postfix increment operator: differs from prefix in return-type and input param
	Date operator ++ (int) // int parameter used to differentiate between pre and post
	{
		// Store a copy of the current state of the object, before incrementing day
		Date Copy(Day, Month, Year);
		++Day;
		// Return the state before increment was performed
		return Copy;
	}

	Date operator -- (int) // int parameter used to differentiate between pre and post
	{
		Date Copy(Day, Month, Year);
		--Day;
		return Copy;
	}

	void DisplayDate()
	{
		cout << Day << " / " << Month << " / " << Year << "\n";
	}
};

int main()
{
	// Instantiate and initialize 2 date objects to 25 Dec 2011
	Date Holiday(25, 12, 2011);
	Date temp = Holiday;
	cout << "The date object is initialized to: ";
	Holiday.DisplayDate();

	// Applying the prefix increment operator
	cout << "\ntemp while using prefix-increment is: ";
	temp = ++Holiday;
	temp.DisplayDate();
	cout << "Date after prefix-increment is: ";
	Holiday.DisplayDate();

	// Applying the prefix decrement operator
	cout << "\ntemp while using prefix-decrement is: ";
	temp = --Holiday;
	temp.DisplayDate();
	cout << "Date after prefix-decrement is: ";
	Holiday.DisplayDate();

	// Applying the postfix increment operator
	cout << "\ntemp while using postfix-increment is: ";
	temp = Holiday++;
	temp.DisplayDate();
	cout << "Date after postfix-increment is: ";
	Holiday.DisplayDate();

	// Applying the postfix decrement operator
	cout << "\ntemp while using postfix-decrement is: ";
	temp = Holiday--;
	temp.DisplayDate();
	cout << "Date after postfix-decrement is: ";
	Holiday.DisplayDate();

	return 0;
}
