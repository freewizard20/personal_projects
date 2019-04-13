#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <stack>
#include <algorithm>
#include <unordered_set>

using namespace std;

int board[1000][1000];
int n, m;
int dx[4] = { -2, 2, 0, 0 };
int dy[4] = { 0, 0, -2, 2 };

int main() {
	int t;
	cin >> t;
	for (int z = 0; z < t; z++) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				board[i][j] = 0;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 0) {
					board[i][j] == 1;
					for (int k = 0; k < 4; k++) {
						if (i + dx[k] >= 0 && i + dx[k] < n && j + dx[k] >= 0 && j + dy[k] < n) {
							board[i + dx[k]][j + dy[k]] = -1;
						}
					}
				}
			}
		}
		int result = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 1) result++;
			}
		}
		cout << "#" << (z + 1) << " " << result << endl;
	}
}
