#include <iostream>

using namespace std;

int cache[1000001];

int min(int a, int b) {
	return a > b ? b : a;
}

int solve(int n) {
	if (n == 1) return 0;
	if (cache[n] != -1) return cache[n];
	int can1, can2, can3;
	if (n % 3 == 0) {
		can1 = solve(n / 3)+1;
	}
	else {
		can1 = 999999999;
	}
	if (n % 2 == 0) {
		can2 = solve(n / 2) + 1;
	}
	else {
		can2 = 999999999;
	}
	
	can3 = solve(n - 1) +1;

	int ret = min(can1, min(can2, can3));
	cache[n] = ret;
	return ret;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < 1000001; i++) {
		cache[i] = -1;
	}
	cout << solve(n) << endl;
}
