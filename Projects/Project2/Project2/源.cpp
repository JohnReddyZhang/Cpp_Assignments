//
//  Assignment_2.cpp
//  Assignments
//	@Name: Zhenghong Zhang
//	@Exercise: Ex2
//  Created by ‡åÕýºë on 2016/10/16.
//  Copyright ? 2016Äê ‡åÕýºë. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main() {
	string FirstName = "null";
	string LastName = "null";
	int Year = 0;
	int Age = 0;

	cout << "What is your first name?" << endl;
	getline(cin, FirstName);
	cout << "What is your last name?" << endl;
	getline(cin, LastName);
	cout << "What year were you born?";
	cin >> Year;
	Age = 2016 - Year;

	cout << "Hello " << FirstName << " " << LastName << "," << endl;
	cout << "This year, you are " << Age << " years old." << endl;
	system("pause");
	return 0;
}
