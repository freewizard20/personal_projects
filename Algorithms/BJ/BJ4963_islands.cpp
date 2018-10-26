#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>
#include <string>

using namespace std;

int n, m;
int board[50][50];
int count2 = 0;
int dx[8] = { -1,1,0,0, 1,-1,1,-1 };
int dy[8] = { 0,0,1,-1, 1,-1,-1,1 };


void bfs(int a, int b) {
	count2++;
	queue<pair<int, int>> buffer;
	buffer.push(pair<int, int>(a,b));
	

	while (buffer.size() != 0) {
		
		auto it = buffer.front();
		buffer.pop();
		board[it.first][it.second] = 0;

		for (int i = 0; i < 8; i++) {
			int tmpx = it.first + dx[i];
			int tmpy = it.second + dy[i];
			if (tmpx >= 0 && tmpy >= 0 && tmpx < n&&tmpy < m) {
				if (board[tmpx][tmpy] == 1) {
					buffer.push(pair<int, int>(tmpx, tmpy));
				}
			}
		}


	}


}

int main() {

	while (true) {

		cin >> m >> n;
		if (n == 0 && m == 0) break;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> board[i][j];
			}
		}
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 1) {
					bfs(i, j);
				}
			}
		}

		cout << count2 << '\n';
		count2 = 0;

	}
	while(1){}
}
