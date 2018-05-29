#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	int low;
	int high=9999;
	int tmp;
	cin >> n;
	tmp = n;
	for (int i = 0; i < 10000; i++) {
		if (i*(i + 1) / 2 >= n) {
			low = i;
			break;
		}
	}
	for (int i = low; i > 0; i--) {
		tmp = tmp - i;
		if (tmp <= i - 1) {
			if (tmp == 0) {
				high = i;
				break;
			}
			else {
				high = tmp;
				break;
			}
		}
	}
	cout << low << " " << high << endl;
}
