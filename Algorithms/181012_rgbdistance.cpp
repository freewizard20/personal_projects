#include <iostream>
#include <vector>

using namespace std;

int min(int a, int b) {
	return a < b ? a : b;
}

int solve(int next, int curr, vector<vector<int>> & price, vector<vector<int>> & cache) {
	if (curr == -1) return 0;
	if (next != -1) {
		if (cache[curr][next] != -1) return cache[curr][next];
	}

	int ret = 99999999;

	for (int i = 0; i < 3; i++) {
		if (next != i) {

			ret = min(ret, solve(i, curr - 1, price, cache) + price[curr][i]);

		}

	}

	if(next!=-1) cache[curr][next] = ret;
	return ret;

}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<vector<int>> price(n, vector<int>(3, 0));
	vector<vector<int>> cache(n, vector<int>(3, -1));
	for (int i = 0; i < n; i++) {
		cin >> price[i][0] >> price[i][1] >> price[i][2];
	}

	cout << solve(-1, n-1, price, cache) << endl;
	while(1){}
}
