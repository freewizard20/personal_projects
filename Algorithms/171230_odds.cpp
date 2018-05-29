#include <iostream>
#include <string>
using namespace std;

int main() {
	int num[7];
	int tot=0;
	int min = 0;
	for (int i = 0; i < 7; i++) {
		cin >> num[i];
		if (num[i] % 2 != 0) {
			tot = tot + num[i];
			if (min == 0) {
				min = num[i];
			}
			else {
				if (min > num[i]) {
					min = num[i];
				}
			}
		}
		
	}
	if (tot == 0) {
		cout << "-1" << endl;
	}
	else {
		cout << tot << endl;
		cout << min << endl;
	}
	
}
