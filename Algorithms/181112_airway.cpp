#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
int board[20][20];
int cnt;
int curr[20][2];

bool solve() {

	int dir = 1;
	for (int i = 0; i < n-1; i++) {
		if (curr[i][0] == curr[i + 1][0]) {
			dir++;
		}
		else if (curr[i][0] > curr[i + 1][0]) {
			for (int j = 0; j < k; j++) {
				if (curr[i][0] == curr[i + 1 + j][0]+1) {
					
				}
				else {
					return false;
				}
			}
			dir = 0;
			i += k-1;
		}
		else {
			if (dir >= k && curr[i][0] + 1 == curr[i + 1][0]) {
				dir = 1;
			}
			else {
				return false;
			}
		}
	}

}

int main() {

	int t;
	cin >> t;
	for (int z = 0; z < t; z++) {

		cnt = 0;
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> board[i][j];
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				curr[j][0] = board[i][j];
				curr[j][1] = 0;
			}
			if (solve()) {
				cnt++;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				curr[j][0] = board[j][i];
				curr[j][1] = 0;
			}
			if (solve()) {
				cnt++;
			}
		}

		cout << "#" << (z + 1) << " " << cnt << '\n';

	}

}
