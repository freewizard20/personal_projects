#include <iostream>
#include <string>
using namespace std;
int main() {
	int a, b;
	cin >> a >> b;
	int month[12] = { 0,31,28,31,30,31,30,31,31,30,31,30 };
	string day[7] = { "MON","TUE","WED","THU","FRI","SAT","SUN" };
	int tot = 0;
	for (int i = 0; i < a; i++)
	{
		tot = tot + month[i];
	}
	tot = tot + b -1;
	cout << day[tot % 7] << endl;
}
