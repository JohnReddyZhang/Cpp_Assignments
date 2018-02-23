//Assignment_4_1.cpp (3 points)

//Write a program that accepts an integer and adds the square of all integers from 1 to the number entered.Make sure to use a loop¡­

//For instance if 4 is entered, your program should compute 1 + 2 * 2 + 3 * 3 + 4 * 4 = 30.  Your program should display the result, 30 with this example.



#include <iostream>
using namespace std;

void computation(int&, int&);
int main(){
	int UserInput = 0;
	cout << "Enter a number here:";
	cin >> UserInput;
	int result = 0;
	computation(UserInput, result);
	cout << "Result is " << result << endl;
	return 0;
}

void computation(int &Number, int &Result){
	for (int i = 1; i <= Number; i ++)
		Result += i*i;
}