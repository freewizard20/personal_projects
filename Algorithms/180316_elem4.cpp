#include "stdafx.h"
#include <cstdio>
#include <algorithm>

using namespace std;

int wmoney[100];
int wtime[100];
int bmoney[100];
int btime[100];
int n;
int maxtime;

int solve(int ne, int w);

int main() {
	scanf("%d %d", &n, &maxtime);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &wtime[i], &wmoney[i], &btime[i], &bmoney[i]);
	}
	printf("%d",solve(0, maxtime));
}

int solve(int ne, int w) {
	if (ne == n) {
		return 0;
	}
	int ret = 0;
	if (w - wtime[ne] >= 0) {
		ret = solve(ne + 1, w - wtime[ne])+wmoney[ne];
	}
	if (w - btime[ne] >= 0) {
		ret = max(ret, solve(ne + 1, w - btime[ne]) + bmoney[ne]);
	}
	return ret;
}
