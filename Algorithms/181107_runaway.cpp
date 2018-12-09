#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;

int board[50][50];
int visited[50][50];
int n, m, l;

int dx[8][4][2] = {
	{{9999,9999},{9999,9999},{9999,9999},{9999,9999}},
	{{-1,0},{1,0},{0,1},{0,-1}},
	{{1,0},{-1,0},{9999,9999},{9999,9999}},
	{{0,1},{0,-1},{9999,9999},{9999,9999}},
	{{-1,0},{0,1},{9999,9999},{9999,9999}},
	{{0,1},{1,0},{9999,9999},{9999,9999}},
	{{0,-1},{1,0},{9999,9999},{9999,9999}},
	{{-1,0},{0,-1},{9999,9999},{9999,9999}}
};

bool cango(int x, int y, int a, int b) {
	int flag1 = 0;
	int flag2 = 0;
	for (int i = 0; i < 4; i++) {
		int tmpx = x + dx[board[x][y]][i][0];
		int tmpy = y + dx[board[x][y]][i][1];
		if (tmpx == a && tmpy == b) {
			flag1 = 1;
		}
	}
	for (int i = 0; i < 4; i++) {
		int tmpx = a + dx[board[a][b]][i][0];
		int tmpy = b + dx[board[a][b]][i][1];
		if (tmpx == x && tmpy == y) {
			flag2 = 1;
		}
	}
	return flag1&&flag2;
}

int main() {

	int t;
	cin >> t;

	for (int z = 0; z < t; z++) {

		int x, y;
		cin >> n >> m >> x >> y >> l;
		l--;
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> board[i][j];
				visited[i][j] = 9999;
			}
		}

		queue<pair<int, int>> buffer;
		buffer.push(pair<int, int>(x, y));
		visited[x][y] = 0;
		while (buffer.size() != 0) {
			auto it = buffer.front();
			buffer.pop();
			if (visited[it.first][it.second] < l) {
				for (int i = 0; i < 4; i++) {
					int tmpx = it.first + dx[board[it.first][it.second]][i][0];
					int tmpy = it.second + dx[board[it.first][it.second]][i][1];
					if (tmpx > 1000) {
						break;
					}
					if (tmpx >= 0 && tmpy >= 0 && tmpx < n&&tmpy < m && cango(it.first,it.second,tmpx,tmpy) && visited[tmpx][tmpy]>visited[it.first][it.second]) {
						visited[tmpx][tmpy] = visited[it.first][it.second] + 1;
						buffer.push(pair<int, int>(tmpx, tmpy));
					}
				}
			}
		}

		// count result
		int count = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (visited[i][j] <= l) {
					count++;
				}
				cout << visited[i][j] << " ";
			}
			cout << endl;
		}

		cout << "#" << (z + 1) << " " << count << '\n';

	}

}
