#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int n, m;
int board[8][8];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };

int dfs(int a, int b, vector<vector<int>> & visited) {

	int ret = 0;
	for (int i = 0; i < 4; i++) {
		int tmpx = a + dx[i];
		int tmpy = b + dy[i];
		if (tmpx >= 0 && tmpy >= 0 && tmpx < n&&tmpy < n) {
			if (visited[tmpx][tmpy] == 0 && board[a][b] > board[tmpx][tmpy]) {
				visited[tmpx][tmpy] = 1;
				ret = max(ret, 1 + dfs(tmpx, tmpy, visited));
				visited[tmpx][tmpy] = 0;
			}
		}
	}

	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;

	for (int z = 0; z < t; z++) {

		cin >> n >> m;

		int mh = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> board[i][j];
				mh = max(mh, board[i][j]);
			}
		}

		int ret = 1;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k <= m; k++) {
					for (int x = 0; x < n; x++) {
						for (int y = 0; y < n; y++) {
							if (board[x][y] == mh) {
								board[i][j] -= k;
								vector<vector<int>> tmp(n, vector<int>(n, 0));
								tmp[x][y] = 1;
								ret = max(ret, 1 + dfs(x, y, tmp));
								board[i][j] += k;
							}
						}
					}
				}
			}
		}


		cout << "#" << (z + 1) << " " << ret << '\n';
	}
}
