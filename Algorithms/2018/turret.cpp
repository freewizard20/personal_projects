#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

/*
int main() {
	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int x1, y1, r1, x2, y2, r2;
		double d;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		d = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
		if (d==0) {
			if (r1 == r2) {
				cout << "-1" << endl;
			}
			else {
				cout << "0" << endl;
			}
		}
		else if (d < abs(r2 - r1)) {
			cout << "0" << endl;
		}
		else if (d == abs(r2 - r1)) {
			cout << "1" << endl;
		}
		else {
			if (d > r1 + r2) {
				cout << "0" << endl;
			}
			else if (d == r1 + r2) {
				cout << "1" << endl;
			}
			else {
				cout << "2" << endl;
			}
		}
	}
	return 0;
}
*/
