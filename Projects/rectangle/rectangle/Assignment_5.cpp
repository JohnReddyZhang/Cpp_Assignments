#include <iostream>
using namespace std;
class rectangle
{
private:
	float length;
	float width;
public:
	rectangle() :
		length(1), width(1)
	{
		cout << "A new rectangle is created with the length of " << length << "\nand the width of" << width << endl;
		cout << "The area is " << area() << "\nand the perimeter is " << perimeter() << endl;
		draw();
	}
	float perimeter() const
	{
		float perimeter = 0;
		perimeter = 2*(length + width);
		return perimeter;
	}
	
	float area() const
	{
		float area = 0;
		area = length * width;
		return area;
	}

	float get_length() const
	{
		return length;
	}

	float get_width() const
	{
		return width;
	}
	
	void set_width()
	{
		do
		{
			cout << "Enter the width of the rectangle: ";
			cin >> width;
		}
		while ((width<=1.0)|(width > 20.0));
	}

	void set_length()
	{
		
		do
		{
			cout << "Enter the length of the rectangle: ";
			cin >> length;
		} while ((length < 1.0) | (length >= 20.0));
	}

	void draw() const
	{
		int length_int = (int)length;
		int width_int = (int)width;
		for (int i = 0; i < length_int; i++)
		{
			for (int j = 0; j < width_int; j++)
				cout << '+';
			cout << "\n";
		};
	}
};

int main(){
	char repeat = 'y';
	rectangle New;
	do {
		New.set_width();
		New.set_length();
		cout << "A new rectangle is created with the length of " << New.get_length() << "\nand the width of" << New.get_width() << endl;
		cout << "The area is " << New.area() << "\nand the perimeter is " << New.perimeter() << endl;
		New.draw();
		cout << "Do you want to do that again? (y/n)";
		cin >> repeat;
	} while (repeat == 'y');
	system("pause");
	return 0;
}