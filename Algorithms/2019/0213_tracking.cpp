#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

int board[8][8];
int n, k;
int maxlength;
int maxes[64][2];
int maxnum;
int highest;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int solve(int a, int b) {
	int ret = 1;
	for (int i = 0; i < 4; i++) {
		int currx = a + dx[i];
		int curry = b + dy[i];
		if (currx >= 0 && currx < n && curry >= 0 && curry < n && board[a][b] > board[currx][curry]) {
			ret = max(ret, solve(currx, curry) + 1);
		}
	}

	return ret;
}

int main() {

	int t;
	cin >> t;
	for (int z = 0; z < t; z++) {
		
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> board[i][j];
			}
		}

		maxlength = 0;

		highest = 0;
		maxnum = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (highest < board[i][j]) {
					highest = board[i][j];
					maxnum = 1;
					maxes[0][0] = i;
					maxes[0][1] = j;
				}
				else if (highest == board[i][j]) {
					maxes[maxnum][0] = i;
					maxes[maxnum][1] = j;
					maxnum++;
				}
				else {

				}
			}
		}

		// carve C
		for (int a = 0; a < n; a++) {
			for (int b = 0; b < n; b++) {
				for (int c = 0; c <= k; c++) {

					// find peaks
					board[a][b] -= c;
					
					// do dfs on each peaks
					for (int i = 0; i < maxnum; i++) {
						int curr = solve(maxes[i][0], maxes[i][1]);
						if (curr > maxlength) maxlength = curr;
					}
					
					board[a][b] += c;

				}
			}
		}

		cout << "#" << (z + 1) << " " << maxlength << endl;

	}

}
