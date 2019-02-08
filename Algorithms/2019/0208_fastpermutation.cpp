#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int a[9];
int b[9];
int win;
int lose;

void swap(int *a, int *b) {
	int tmp;
	tmp = *b;
	*b = *a;
	*a = tmp;
}

void solve(int n, int r, int depth) {

	if (depth == r) {

		// play game
		int totala = 0;
		int totalb = 0;
		for (int i = 0; i < 9; i++) {
			if (a[i] > b[i]) {
				totala = totala + a[i] + b[i];
			}
			else {
				totalb = totalb + a[i] + b[i];
			}
		}
		if (totala > totalb) {
			win++;
		}
		else {
			lose++;
		}
		return;
	}

	for (int i = depth; i < n; i++) {
		swap(&b[i], &b[depth]);
		solve(n, r, depth + 1);
		swap(&b[i], &b[depth]);
	}
}

int main() {

	int t;
	cin >> t;
	for (int z = 0; z < t; z++) {
		
		// fill a and b
		for (int i = 0; i < 9; i++) {
			cin >> a[i];
		}

		int count = 0;
		for (int i = 1; i <= 18; i++) {
			int contains = 0;
			for (int j = 0; j < 9; j++) {
				if (a[j] == i) {
					contains = 1;
					break;
				}
			}
			if (contains == 0) {
				b[count] = i;
				count++;
			}
		}

		// do combination
		win = 0;
		lose = 0;
		solve(9, 9, 0);
		cout << "#" << (z + 1) << " " << win << " " << lose << endl;


	}

}
