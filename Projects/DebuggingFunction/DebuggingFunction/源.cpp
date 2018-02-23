#include <iostream>
using namespace std;

void up_and_down(int);

int main(){
	up_and_down(1);
	return 0;
}

void up_and_down(int n){
	cout << "Level " << n << '\n';
	if (n < 4)
		up_and_down(n + 1);
	cout << "LEVEL " << n << endl;
}	