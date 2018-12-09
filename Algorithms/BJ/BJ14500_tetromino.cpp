#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int board[500][500];
int n, m;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };


bool colored(vector<pair<int,int>> & filled, int currx, int curry){
	for (int i = 0; i < filled.size(); i++) {
		if (filled[i].first == currx && filled[i].second == curry) {
			return true;
		}
	}
	return false;
}

int solve(vector<pair<int,int>> filled, int todo, int total) {
	if (todo == 0) {
		return total;
	}

	int ret = 0;
	int currx, curry;

	for (int i = 0; i < filled.size(); i++) {
		for (int k = 0; k < 4; k++) {
			currx = filled[i].first + dx[k];
			curry = filled[i].second + dy[k];
			if (currx > 0 && curry > 0 && currx < n&&curry < m) {
				if (!colored(filled,currx,curry)) {

					filled.push_back(pair<int, int>(currx, curry));
					ret = max(ret, solve(filled, todo - 1, total + board[currx][curry]));
					filled.pop_back();

				}
			}
		}
	}
		
	

	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	vector<pair<int,int>> filled;

	int ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			filled.push_back(pair<int, int>(i, j));
			ret = max(ret, solve(filled, 3, board[i][j]));
			filled.pop_back();
		}
	}

	cout << ret << '\n';
	
}
