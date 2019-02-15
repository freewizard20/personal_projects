#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

int board[12][12];
int cores[12][2];
int num;
int n;
int tot;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

pair<int, int> solve(int m, vector<int> & tmp) {
	if (m == num) {
		// connect as numbered, check connections and total length and  return pair
		int test[12][12];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				test[i][j] = board[i][j];
			}
		}
		int totallength = 0;
		int totalconnected = 0;
		for (int i = 0; i < tmp.size(); i++) {
			// connect
			int tmpl = 0;
			int connected = 0;
			int currx = cores[i][0];
			int curry = cores[i][1];
			int sam[12][2];
			int sams = 0;
			while (1) {
				currx += dx[tmp[i]];
				curry += dy[tmp[i]];

				if (test[currx][curry] == 1 || test[currx][curry] == 2) {
					break;
				}
				if (currx == 0 || currx == n - 1 || curry == 0 || curry == n - 1) {
					connected = 1;
					tmpl++;
					for (int k = 0; k < sams; k++) {
						test[sam[k][0]][sam[k][1]] = 2;
					}
					test[currx][curry] = 2;
					break;
				}
				sam[sams][0] = currx;
				sam[sams][1] = curry;
				sams++;
				tmpl++;
			}
			if (connected) {
				totalconnected++;
				totallength += tmpl;
			}
		}

/*		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << test[i][j] << " ";
			}
			cout << endl;
		}

		cout << "--- " << totalconnected << " " << totallength << endl;*/
		return pair<int, int>(totalconnected, totallength);
	}

	pair<int, int> ret = { 0,99999999 };
	for (int i = 0; i < 4; i++) {
		tmp.push_back(i);
		auto it = solve(m + 1, tmp);
		if (it.first > ret.first) {
			ret = it;
		}
		else if (it.first == ret.first && it.second < ret.second) {
			ret = it;
		}
		tmp.pop_back();
	}
	return ret;
}

int main() {

	int t;
	cin >> t;
	for (int z = 0; z < t; z++) {

		cin >> n;
		num = 0;
		tot = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> board[i][j];
				if (board[i][j] == 1 && !(i == 0 || j == 0 || j == n - 1 || i == n - 1)) {
					cores[num][0] = i;
					cores[num][1] = j;
					num++;					
				}
			}
		}

		//cout << "num " << num << endl;

		vector<int> tmp;
		auto it = solve(0, tmp);
		cout << "#" << " " << it.second << endl;

	}
	
}
