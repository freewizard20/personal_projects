#include <iostream>

using namespace std;

template<typename Any> void Swap(Any &a, Any &b);

int main()
{
	int i = 10;
	int j = 20;
	cout << "i, j = " << i << " , " << j << ".\n";
	Swap(i, j);
	cout << i << " , " << j << endl;

	double x = 24.5;
	double y = 81.7;
	cout << x << " , " << y << endl;
	Swap(x, y);
	cout << x << " , " << y << endl;
	return 0;
}

template <typename Any> void Swap(Any &a, Any &b)
{
	Any temp;
	temp = a;
	a = b;
	b = temp;
}
