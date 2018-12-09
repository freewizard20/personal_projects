#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>
#include <string>

using namespace std;

int board[25][25];
int n;
int nock;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0, -1, 1 };


void dfs(int a, int b) {
	nock++;
	board[a][b] = 0;

	for (int i = 0; i < 4; i++) {
		if (a + dx[i] >= 0 && b + dy[i] >= 0 && a + dx[i] < n&&b + dy[i] < n) {
			if (board[a + dx[i]][b + dy[i]] == 1) {
				dfs(a + dx[i], b + dy[i]);
			}
		}
	}

}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < tmp.size(); j++) {
			board[i][j] = tmp[j] - '0';
		}
	}
	int count2 = 0;
	vector<int> cnt;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 1) {
				count2++;
				nock = 0;
				dfs(i, j);
				cnt.push_back(nock);
			}
		}
	}

	sort(cnt.begin(), cnt.end());

	cout << count2 << '\n';
	for (int i = 0; i < cnt.size(); i++) {
		cout << cnt[i] << '\n';
	}

	while(1){}
	
}
