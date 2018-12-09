#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 0:life point 1: timer 2: status
int board[350][350][5];
int n, m, l;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void work() {
	//cout << "work" << endl;
	for (int i = 0; i < 350; i++) {		
		for (int j = 0; j < 350; j++) {

			if (board[i][j][3] == 1) {
				board[i][j][3] = 0;
				continue;
			}

			// dead
			if (board[i][j][2] == 2) {
				continue;
			}
			else if (board[i][j][2] == 1) {
				if (board[i][j][1] == 0) {
					board[i][j][2] = 2;
				}
				else {
					// expand here
					if (board[i][j][4] == 1) {
						for (int k = 0; k < 4; k++) {
							int tmpx = i + dx[k];
							int tmpy = j + dy[k];
							if (tmpx >= 0 && tmpy >= 0 && tmpx < 350 && tmpy < 350) {
								if (board[tmpx][tmpy][0] == 0 || (board[tmpx][tmpy][2] == 0 && board[tmpx][tmpy][1] == board[tmpx][tmpy][0] && board[tmpx][tmpy][0] < board[i][j][0])) {
									board[tmpx][tmpy][0] = board[i][j][0];
									board[tmpx][tmpy][1] = board[i][j][0];
									board[tmpx][tmpy][2] = 0;
									if (k == 1 || k == 3) {
										board[tmpx][tmpy][3] = 1;
									}
								}
							}
						}
						board[i][j][4] = 0;
					}
					board[i][j][1]--;
					if (board[i][j][1] == 0) {
						board[i][j][2] = 2;
					}
				}
			}
			else {
				if (board[i][j][0] == 0) {
					continue;
				}
				else {
					if (board[i][j][1] == 0) {
						board[i][j][1] = board[i][j][0];
						board[i][j][2] = 1;
					}
					else {
						board[i][j][1]--;
						if (board[i][j][1] == 0) {
							board[i][j][1] = board[i][j][0];
							board[i][j][2] = 1;
							board[i][j][4] = 1;
						}
					}
				}
			}
		}
	}
		
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	for (int z = 0; z < t; z++) {

		cin >> n >> m >> l;

		// init board
		for (int i = 0; i < 350; i++) {
			for (int j = 0; j < 350; j++) {
				for (int k = 0; k < 5; k++) {
					board[i][j][k] = 0;
				}
			}
		}

		for (int i = 155; i < 155 + n; i++) {
			for (int j = 155; j < 155 + m; j++) {
				cin >> board[i][j][0];
				board[i][j][1] = board[i][j][0];
				board[i][j][2] = 0;
				// 0: waiting 1: active 2: dead
			}
		}

		for (int i = 0; i < l; i++) {

			/*cout << "---" << endl;
			for (int i = 325; i < 375; i++) {
				for (int j = 325; j < 375; j++) {
					cout << board[i][j][0] << board[i][j][1] << board[i][j][2] << " ";
				}
				cout << endl;
			}*/

			work();
		}

		int count = 0;
		for (int i = 0; i < 350; i++) {
			for (int j = 0; j < 350; j++) {
				if ((board[i][j][0]!=0 && board[i][j][2] == 0) || board[i][j][2] == 1) count++;
			}
		}

		cout << "#" << (z + 1) << " " << count << '\n';
	}

}
