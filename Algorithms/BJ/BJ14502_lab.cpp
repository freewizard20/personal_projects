#include "stdafx.h"
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int board[8][8];
int n, m;
vector<pair<int, int>> zeros;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int solve(int k, vector<int> & buffer) {

	if (k == 0) {

		queue<pair<int, int>> q;
		int buf[8][8];

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				buf[i][j] = board[i][j];
				if (buf[i][j] == 2) {
					q.push(pair<int, int>(i, j));
				}
			}
		}

		for (int i = 0; i < buffer.size(); i++) {
			buf[zeros[buffer[i]].first][zeros[buffer[i]].second] = 1;
		}

		// fill virus
		while (q.size() != 0) {

			int currx = q.front().first;
			int curry = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int tmpx = currx + dx[i];
				int tmpy = curry + dy[i];
				if (tmpx >= 0 && tmpx < n && tmpy >= 0 && tmpy < m && buf[tmpx][tmpy] == 0) {
					buf[tmpx][tmpy] = 2;
					q.push(pair<int, int>(tmpx, tmpy));
				}
			}

		}

		int count = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {				
				if (buf[i][j] == 0) count++;
			}
		}
		
		return count;
	}

	int ret = 0;

	int small = buffer.size() == 0 ? 0 : buffer.back() + 1;

	for (int i = small; i < zeros.size(); i++) {

		buffer.push_back(i);
		ret = max(ret, solve(k - 1, buffer));
		buffer.pop_back();

	}

	return ret;

}

int main() {
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 0) {
				zeros.push_back(pair<int, int>(i, j));
			}
		}
	}
	
	vector<int> tmp;
	cout << solve(3, tmp) << endl;

	
}
