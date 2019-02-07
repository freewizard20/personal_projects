#include "stdafx.h"
#include <iostream>
#include <math.h>

using namespace std;

int main() {
	int T;
	int Ans[10000];
	cin >> T;
	int i;
	for (i = 0; i < T; i++) {
		int x1, x2, y1, y2, r1, r2;
		double d;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		if (x1 == x2 && y1 == y2) {
			d = 0;
		}
		else {
			d = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
		}
		if (d == 0 && r1 == r2) {
			Ans[i] = -1;
		}
		else if (d >(r1 + r2) || (d == 0 && (r1 != r2))) {
			Ans[i] = 0;
		}
		else if (d == (r1 + r2)) {
			Ans[i] = 1;
		}
		else {
			Ans[i] = 2;
		}
	}

	for (i = 0; i < T; i++) {
		cout << Ans[i] << endl;
	}
	while (1) {}
}
