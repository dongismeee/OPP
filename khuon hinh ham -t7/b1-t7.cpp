#include <iostream>
using namespace std;

template <typename Type>
void Swap(Type& x, Type& y)
{
	Type Temp = x;
	x = y;
	y = Temp;
}

int main()
{
	int x = 5, y = 10;
	double a = 5.5, b = 3.5;

	Swap(x, y);
	Swap(a, b);
	cout<<x;
	cout<<y;
	
	int c = 5, d = 10;
	Swap(c, d);

	return 0;
}
