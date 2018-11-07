#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;

int board[15][25];
int t, w, d, k;


bool test() {

	for (int i = 0; i < w; i++) {
		int flag = 0;
		int pass = 0;
		for (int j = 0; j < d-1; j++) {
			if (board[j+1][i] == board[j][i]) {
				flag++;
			}
			else {
				flag = 0;
			}
			if (flag >= k-1) {
				pass = 1;
				break;
			}
		}
		if (flag >= k - 1) pass = 1;
		if (pass == 0) {
			return false;
		}
	}
	return true;

}

int solve(int left, int curr) {
	if (left == 0) {
		return test();
	}

	for (int i = 0; i < d; i++) {
		for (int j = 0; j < 2; j++) {
			int cp[25];
			for (int k = 0; k < w; k++) {
				cp[k] = board[i][k];
				board[i][k] = (j == 0) ? 0 : 1;
			}
			if (solve(left - 1, i + 1)) {
				return true;
			}
			for (int k = 0; k < w; k++) {
				board[i][k] = cp[k];
			}
		}
	}

	return false;

}


int main() {
	cin >> t;
	for (int z = 0; z < t; z++) {

		cin >> d >> w >> k;

		for (int i = 0; i < d; i++) {
			for (int j = 0; j < w; j++) {
				cin >> board[i][j];
			}
		}

		int ret = 0;
		if (k == 1) {
			
		}
		else if (test() == true) {

		}
		else {
			for (int i = 1; i <= d; i++) {
				if (i == k) {
					ret = k;
					break;
				}
				if (solve(i, 0)) {
					ret = i;
					break;
				}
			}
		}
		cout << "#" << (z + 1) << " " << ret << '\n';
	}
}
