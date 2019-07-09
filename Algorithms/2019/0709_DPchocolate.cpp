// BJ 2163

#include <iostream>
#include <algorithm>

int cache[301][301];

using namespace std;

int solve(int n, int m) {
	if (n == 1 && m == 1) return 0;
	if (cache[n][m] != -1) return cache[n][m];
	int ret = 99999999;
	for (int i = 1; i < n; i++) {
		ret = min(ret, solve(i, m) + solve(n - i, m) + 1);
	}

	for (int i = 1; i < m; i++) {
		ret = min(ret, solve(n, i) + solve(n, m - i) + 1);
	}

	cache[n][m] = ret;
	return ret;
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < 301; i++) {
		for (int j = 0; j < 301; j++) {
			cache[i][j] = -1;
		}
	}
	cout << solve(n, m) << endl;
}
