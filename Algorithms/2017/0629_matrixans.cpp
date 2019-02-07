#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int colsum[101][101];

void proc(int caseidx) {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			int v;
			scanf("%d", &v);
			colsum[i][j] = colsum[i - 1][j] + v;
		}
	}

	int ans = -100000000;
	for (int i = 1; i <= n; ++i) {
		for (int j = i; j <= n; ++j) {
			int sum = 0;
			for (int k = 1; k <= n; ++k) {
				int v = colsum[j][k] - colsum[i - 1][k];
				sum = max(sum + v, v);
				ans = max(ans, sum);
			}
		}
	}

	printf("Case #%d\n%d\n", caseidx, ans);
}

int main() {
	//freopen("input.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; ++i) {
		proc(i);
	}
	return 0;
}
