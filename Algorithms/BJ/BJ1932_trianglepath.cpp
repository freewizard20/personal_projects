#include <iostream>
#include <vector>

using namespace std;


int board[501][501];
int cache[501][501];
int n;

int max(int a, int b) {
	return a > b ? a : b;
}

int solve(int x, int y) {
	if (x >= n) return 0;
	if (cache[x][y] != -1) return cache[x][y];

	int ret = 0;
	ret = board[x][y] + max(solve(x + 1, y), solve(x + 1, y + 1));
	cache[x][y] = ret;
	return ret;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i+1; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < 501; i++) {
		for (int j = 0; j < 501; j++) {
			cache[i][j] = -1;
		}
	}
	cout << solve(0, 0) << endl;
}
