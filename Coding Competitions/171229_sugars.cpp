#include <iostream>
#include <string>
using namespace std;
/*
int main()
{
	int n;
	int tmp;
	int bags;
	int ret;
	cin >> n;
	bags = n / 5;
	tmp = n % 5;
	bags = bags + tmp / 3;
	tmp = tmp % 3;
	if (tmp != 0) {
		ret = -1;
	}
	else {
		ret = bags;
	}
	cout << ret << endl;
	return 0;
}
*/

int main() {
	int n;
	int tmp;
	int ret5=-1;
	int ret3=-1;
	cin >> n;
	for (int i = 0; i <= n / 5; i++) {
		tmp = n - i * 5;
		if (tmp % 3 == 0) {
			ret5 = i;
			ret3 = tmp / 3;
		}
	}
	if (ret5 == -1) {
		cout << -1 << endl;
	}
	else {
		cout << ret3 + ret5 << endl;
	}
}
