#include <iostream>
using namespace std;

void convert_from_miuntes(int&);
int main()
{
	int minutes = 0;
	cout << "This program converts minutes to hours and minutes.\
	\nPlease enter a number of minutes(an integer) to be converted:";
	cin >> minutes;
	convert_from_miuntes(minutes);
	system("pause");
	return 0;
}

void convert_from_miuntes(int& totalMin)
{
	int hour = totalMin / 60;
	int minute = totalMin % 60;
	cout << totalMin << " equals ";
	if (hour == 1) cout << "1 hour and ";
	else cout << hour << " hours and ";
	if (minute == 1) cout << "1 minute." << endl;
	else cout << minute << " minutes." << endl;
}