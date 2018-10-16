#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(int left) {
	if (left == 0) return 1;
	if (left < 0) return 0;
	int ret = solve(left - 1) + solve(left - 2) + solve(left - 3);
	return ret;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		cout << solve(tmp) << endl;
	}
}
