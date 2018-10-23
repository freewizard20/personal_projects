#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int n;
int arr[1001];
int cache[1001];

int solve(int m) {
	if (m <= 0) return 0;
	if (m == 1) return arr[1];
	if (cache[m] != -1) return cache[m];

	int ret = 0;
	for (int i = 1; m-i>=0; i++) {
		ret = max(ret, arr[i] + solve(m - i));
	}

	cache[m] = ret;
	return ret;
}

int main() {

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		cache[i] = -1;
	}

	cout << solve(n) << endl;
}
