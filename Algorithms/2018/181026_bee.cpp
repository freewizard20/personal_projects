#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;

int n, m, c;
int board[10][10];

int solve(int left, int curr, vector<int> & cost) {
	if (left <= 0) return 0;
	if (curr >= cost.size()) return 0;

	int ret = solve(left, curr + 1, cost);
	if(left>=cost[curr])
	ret = max(ret, cost[curr] * cost[curr] + solve(left - cost[curr], curr+1, cost));
	
	return ret;
}

int main() {

	int t;
	cin >> t;
	for (int z = 0; z < t; z++) {

		cin >> n >> m >> c;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> board[i][j];
			}
		}

		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= n - m; j++) {
				for (int k = 0; k < n; k++) {
					for (int l = 0; l <= n - m; l++) {
						//cout << i << " " << j << " " << k << " " << l << endl;
						if (i != k || abs(j - l) >= m ) {
							//cout << "working..." << abs(j-l) << " " << m << endl;
							int tmp = 0;
							vector<int> select1;
							for (int x = j; x < j + m; x++) {
								//cout << "board1 " << board[i][x] << endl;
								select1.push_back(board[i][x]);
							}
							tmp += solve(c, 0, select1);
							//cout << tmp << endl;
							vector<int> select2;
							for (int x = l; x < l + m; x++) {
								//cout << "board2 " << board[k][x] << endl;
								select2.push_back(board[k][x]);
							}
							tmp += solve(c, 0, select2);
							//cout << tmp << endl;
							ans = max(ans, tmp);
						}
					}
				}
			}

		}

		cout << "#" << (z + 1) << " " << ans << '\n';

	}
	
}
