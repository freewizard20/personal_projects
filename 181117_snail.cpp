#include <iostream>
#include <vector>

using namespace std;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };


int main() {

	int t;
	cin >> t;
	for (int z = 0; z < t; z++) {
		cout << "#" << (z + 1) << endl;
		int n;
		cin >> n;
		vector<vector<int>> result(n, vector<int>(n, 0));
		int itx = 0;
		int ity = -1;
		int count = 1;
		int dir = 0;
		while (count <= n * n) {
			int tmpx = itx + dx[dir];
			int tmpy = ity + dy[dir];
			if (tmpx < 0 || tmpy < 0 || tmpx >= n || tmpy >= n || result[tmpx][tmpy] != 0) {
				dir = (dir + 1) % 4;
				continue;
			}

			result[tmpx][tmpy] = count;
			itx = tmpx;
			ity = tmpy;
			count++;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << result[i][j] << " ";
			}
			cout << '\n';
		}

	}
}
