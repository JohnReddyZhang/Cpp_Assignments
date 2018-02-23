#include <iostream>
using namespace std;

class myclass
{
public:
	myclass()
	{
		cout << "构造函数" << endl;
	}
	~myclass()
	{
		cout << "析构函数" << endl;
	}
};

int main()
{
	myclass mc;
	return 0;
}