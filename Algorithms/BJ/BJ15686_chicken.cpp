#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int n, m;
int board[50][50];
vector<pair<int,int>> chicken;
vector<pair<int,int>> house;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int solve(int m, vector<int> & buffer) {
	if (m == 0) {
		int tmp[50][50];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				tmp[i][j] = 9999;
			}
		}

		queue<pair<int, int>> q;

		for (int i = 0; i < buffer.size(); i++) {		
			tmp[chicken[buffer[i]].first][chicken[buffer[i]].second] = 0;
			q.push(pair<int, int>(chicken[buffer[i]].first, chicken[buffer[i]].second));
		}

		while (q.size() != 0) {

			int tmpx = q.front().first;
			int tmpy = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int currx = tmpx + dx[i];
				int curry = tmpy + dy[i];
				if (currx >= 0 && currx < n && curry >= 0 && curry < n && tmp[currx][curry]==9999) {
					tmp[currx][curry] = tmp[tmpx][tmpy] + 1;
					q.push(pair<int, int>(currx, curry));
				}
			}


		}

		int cdis = 0;
		for (int i = 0; i < house.size(); i++) {
			cdis += tmp[house[i].first][house[i].second];
		}

		return cdis;
	}

	int ret = 99999999;
	int small = buffer.size() == 0 ? 0 : buffer.back() + 1;
	for (int i = small; i < chicken.size(); i++) {
		buffer.push_back(i);
		ret = min(ret, solve(m - 1, buffer));
		buffer.pop_back();
	}

	return ret;
}

int main() {

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) {
				house.push_back(pair<int, int>(i, j));
			}
			if (board[i][j] == 2) {
				chicken.push_back(pair<int, int>(i, j));
			}
		}
	}

	vector<int> tmp;
	cout << solve(m, tmp) << endl;


}
