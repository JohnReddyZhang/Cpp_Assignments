#include <iostream>
using namespace std;

class myclass
{
public:
	myclass()
	{
		cout << "���캯��" << endl;
	}
	~myclass()
	{
		cout << "��������" << endl;
	}
};

int main()
{
	myclass mc;
	return 0;
}