#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int board[10][10];
int n;

int solve(int m, unordered_set<int> set, vector<int> buffer) {
	if (m == 0) {
		int tot = 0;
		int size = buffer.size();
		for (int i = 0; i < size; i++) {
			if (i == buffer.size() - 1) {
				if (board[buffer[i]][buffer[0]] == 0) {
					tot = 999999999;
					break;
				}
				else {
					tot += board[buffer[i]][buffer[0]];
				}
			}
			else {
				if (board[buffer[i]][buffer[i + 1]] == 0) {
					tot = 999999999;
					break;
				}
				else {
					tot += board[buffer[i]][buffer[i + 1]];
				}
			}
		}
		if (tot == 30) {
			for (int i = 0; i < buffer.size(); i++) {
				cout << buffer[i] << " ";
			}
			cout << endl;
		}
		return tot;
	}

	int ret = 999999999;
	for (int i = 0; i < n; i++) {
		if (set.find(i) == set.end()) {

			set.insert(i);
			buffer.push_back(i);
			ret = min(ret, solve(m - 1, set, buffer));
			buffer.pop_back();
			set.erase(i);

		}
	}
	return ret;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	vector<int> tmp;
	tmp.reserve(10);
	cout << solve(n, unordered_set<int>(), tmp) << '\n';
	while(1){}
}
