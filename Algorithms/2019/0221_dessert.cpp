#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <unordered_set>

using namespace std;


int board[20][20];
int n;

int dx[4] = {-1,1,1,-1};
int dy[4] = {1,1,-1,-1};

int tot;

void solve(int x, int y, vector<int> & xx, unordered_set<int> & tmp, int dir, int length0, int length1) {

	if (dir == 0) {

		// go straight
		int nextx = x + dx[dir];
		int nexty = y + dy[dir];
		if (nextx >= 0 && nextx < n && nexty >= 0 && nexty < n && tmp.find(board[nextx][nexty]) == tmp.end()) {
			
				tmp.insert(board[nextx][nexty]);
				xx.push_back(board[nextx][nexty]);
				solve(nextx, nexty, xx, tmp, dir, length0 + 1, length1);
				tmp.erase(board[nextx][nexty]);
				xx.pop_back();
			
		}

		// turn right
		if (length0 != 0) {
			dir++;
			int nextx = x + dx[dir];
			int nexty = y + dy[dir];
			if (nextx >= 0 && nextx < n && nexty >= 0 && nexty < n) {
				if (tmp.find(board[nextx][nexty]) == tmp.end()) {
					tmp.insert(board[nextx][nexty]);
					xx.push_back(board[nextx][nexty]);
					solve(nextx, nexty, xx, tmp, dir, length0, 1);
					tmp.erase(board[nextx][nexty]);
					xx.pop_back();
				}
			}
		}

		return;
	}

	if (dir == 1) {

		// go straight
		int nextx = x + dx[dir];
		int nexty = y + dy[dir];
		if (nextx >= 0 && nextx < n && nexty >= 0 && nexty < n) {
			if (tmp.find(board[nextx][nexty]) == tmp.end()) {
				tmp.insert(board[nextx][nexty]);
				xx.push_back(board[nextx][nexty]);
				//cout << "dir1 " << nextx << " " << nexty << " " << board[nextx][nexty] << endl;
				solve(nextx, nexty, xx, tmp, dir, length0, length1+1);
				tmp.erase(board[nextx][nexty]);
				xx.pop_back();
			}
		}

		// turn right
		if (length1 != 0) {
			dir++;
			int nextx = x + dx[dir];
			int nexty = y + dy[dir];
			if (nextx >= 0 && nextx < n && nexty >= 0 && nexty < n) {
				if (tmp.find(board[nextx][nexty]) == tmp.end()) {
					tmp.insert(board[nextx][nexty]);
					xx.push_back(board[nextx][nexty]);
					solve(nextx, nexty, xx, tmp, dir, length0, length1);
					tmp.erase(board[nextx][nexty]);
					xx.pop_back();
				}
			}
		}

		return;
	}

	if (dir == 2) {
		int nextx = x;
		int nexty = y;
		unordered_set<int> bug;
		vector<int> bugx;
		for (auto it = tmp.begin(); it != tmp.end(); it++) {
			bug.insert(*it);
		}
		for (int i = 0; i < xx.size(); i++) {
			bugx.push_back(xx[i]);
		}
		for (int i = 1; i < length0; i++) {
			nextx = nextx + dx[dir];
			nexty = nexty + dy[dir];
			if (nextx >= 0 && nextx < n && nexty >= 0 && nexty < n && tmp.find(board[nextx][nexty]) == tmp.end()) {
					
					xx.push_back(board[nextx][nexty]);
					tmp.insert(board[nextx][nexty]);
				
				
			}
			else {
				tmp.clear();
				for (auto it = bug.begin(); it != bug.begin(); it++) {
					tmp.insert(*it);
				}
				xx.clear();
				for (int i = 0; i < bugx.size(); i++) {
					xx.push_back(bugx[i]);
				}
				return;
			}
		}
		dir++;
		for (int i = 0; i < length1; i++) {
			nextx = nextx + dx[dir];
			nexty = nexty + dy[dir];
			if (nextx >= 0 && nextx < n && nexty >= 0 && nexty < n && tmp.find(board[nextx][nexty]) == tmp.end()) {
				
					xx.push_back(board[nextx][nexty]);
					tmp.insert(board[nextx][nexty]);
				
				
			}
			else {
				cout << "boom " << nextx << " " << nexty << " " << board[nextx][nexty] << endl;
				tmp.clear();
				for (auto it = bug.begin(); it != bug.begin(); it++) {
					tmp.insert(*it);
				}
				xx.clear();
				for (int i = 0; i < bugx.size(); i++) {
					xx.push_back(bugx[i]);
				}
				return;
			}
		}

		int sam = tmp.size();
		if (tot < sam) {
			cout << "----- found one -----" << endl;
			cout << "lengths " << length0 << " " << length1 << endl;
			cout << tot << " " << tmp.size() << " " << xx.size() << endl;
			for (int i = 0; i < xx.size(); i++) {
				cout << xx[i] << " ";
			}
			cout << endl;
			tot = sam; 
		}
		tmp.clear();
		for (auto it = bug.begin(); it != bug.begin(); it++) {
			tmp.insert(*it);
		}
		xx.clear();
		for (int i = 0; i < bugx.size(); i++) {
			xx.push_back(bugx[i]);
		}
		return;
	}
}

int main() {

	int t;
	cin >> t;
	for (int z = 0; z < t; z++) {

		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> board[i][j];
			}
		}
		
		
		tot = -1;
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << i << " " << j << endl;
				unordered_set<int> tmp;
				vector<int> xx;
				solve(i, j, xx, tmp, 0, 0, 0);
			}
		}
		cout << "#" << (z + 1) << " " << tot << endl;

	}

}

