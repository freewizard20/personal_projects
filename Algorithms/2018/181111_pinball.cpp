#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int board[100][100];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

int block[4][5] = {
	{2,3,1,1,1},
	{3,3,2,1,3},
	{1,3,2,1,1},
	{2,3,3,1,3}
};

int total;
int sx, sy;

vector < vector<pair<int, int>>> hall;

void ball(int x, int y, int dir, int count) {
	int mx = x;
	int my = y;
	int mdir = dir;

	while (1) {

		mx = mx + dx[mdir];
		my = my + dy[mdir];

		// 벽
		if (mx<0 || mx > n - 1 || my < 0 || my > n - 1) {
			mdir = (mdir + block[mdir][4]) % 4;
			count++;
			continue;
		}

		if (mx == sx && my == sy) {
			total = max(total, count);
			break;
		}

		int num = board[mx][my];

		if (num == 0) {
			continue;
		}
		else if (num == -1) {
			total = max(total, count);
			break;
		}
		else if (num < 6) {
			mdir = (mdir + block[mdir][num - 1]) % 4;
			count++;
			continue;
		}
		else {
			int hx1 = hall[num - 6][0].first;
			int hy1 = hall[num - 6][0].second;
			int hx2 = hall[num - 6][1].first;
			int hy2 = hall[num - 6][1].second;

			if (hx1 == mx && hy1 == my) {
				mx = hx2;
				my = hy2;
			}
			else {
				mx = hx1;
				my = hy1;
			}
		}

	}
}

int main() {
	int t;
	cin >> t;
	for (int z = 0; z < t; z++) {

		cin >> n;
		hall.resize(5);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> board[i][j];
				if (board[i][j] > 5) {
					hall[board[i][j] - 6].push_back(pair<int, int>(i, j));
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				sx = i;
				sy = j;
				if (board[i][j] != 0) continue;

				for (int k = 0; k < 4; k++) {
					ball(i, j, k, 0);
				}
			}
		}

		cout << "#" << (z + 1) << " " << total << '\n';

		total = 0;
		hall.clear();

	}

	return 0;
}
