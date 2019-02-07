#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int n;

int arr[100001][2];
int cache[100001][2];


int solve(int curr, int mode) {
	
	if (curr == n) return 0;
	if (cache[curr][mode] != -1) return cache[curr][mode];

	int ret = 0;
	if (mode == 0) {
		ret = max(ret, solve(curr + 1, 1) + arr[curr][0]);
		ret = max(ret, solve(curr + 1, 2) + arr[curr][1]);
		ret = max(ret, solve(curr + 1, 0));
	}
	else if (mode == 1) {
		ret = max(ret, solve(curr + 1, 2) + arr[curr][1]);
		ret = max(ret, solve(curr + 1, 0));
	}
	else {
		ret = max(ret, solve(curr + 1, 1) + arr[curr][0]);
		ret = max(ret, solve(curr + 1, 0));
	}

	cache[curr][mode] = ret;
	cout << curr << " " << mode << " " << ret << endl;
	return ret;

}


int main() {

	
	int t;
	cin >> t;
	for (int z = 0; z < t; z++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i][0];
		}
		for (int i = 0; i < n; i++) {
			cin >> arr[i][1];
		}

		for (int i = 0; i < 100001; i++) {
			for (int j = 0; j < 2; j++) {
				cache[i][j] = -1;
			}
		}

		cout << solve(0, 0) << endl;
		while(1){}
	}
}
