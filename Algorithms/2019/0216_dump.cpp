#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <chrono>
#include <ctime>

using namespace std;

int board[12][12];
int cores[12][2];
int coresz[12][2];
int numz;
int num;
int n;
int tot;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int maxfull;
int maxlength;

int noteligible(int k) {

	int south=0;
	int north=0;
	int west=0;
	int east=0;
	for (int i = 0; i < numz; i++) {
		if (coresz[k][0] == coresz[i][0] && coresz[k][1] > coresz[i][1]) {
			east = 1;
		}
		if (coresz[k][0] == coresz[i][0] && coresz[k][1] < coresz[i][1]) {
			west = 1;
		}
		if (coresz[k][0] > coresz[i][0] && coresz[k][1] == coresz[i][1]) {
			north = 1;
		}
		if (coresz[k][0] < coresz[i][0] && coresz[k][1] == coresz[i][1]) {
			south = 1;
		}
	}

	if (north&&south&&east&&west) return 1;
	else return 0;

}

void solve(int m, vector<int> & tmp) {
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

		if (maxfull < totalconnected) {
			maxfull = totalconnected;
			maxlength = totallength;
		}
		else if (maxfull == totalconnected && maxlength > totallength) {
			maxlength = totallength;
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		tmp.push_back(i);
		solve(m + 1, tmp);
		tmp.pop_back();
	}
	return;
}

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	for (int z = 0; z < t; z++) {

		maxlength = 0;
		maxfull = 0;
		cin >> n;
		num = 0;
		numz = 0;
		tot = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> board[i][j];
				if (board[i][j] == 1) {
					coresz[numz][0] = i;
					coresz[numz][1] = j;
					numz++;					
				}
			}
		}

		for (int i = 0; i < numz; i++) {
			if (noteligible(i) || (coresz[i][0] == 0 || coresz[i][0] == n - 1 || coresz[i][1] == 0 || coresz[i][1] == n - 1)) {
				
			}
			else {
				cores[num][0] = coresz[i][0];
				cores[num][1] = coresz[i][1];
				num++;
			}
		}

		//cout << "num " << num << endl;

		vector<int> tmp;

		chrono::time_point<chrono::high_resolution_clock> start, end;
		start = chrono::high_resolution_clock::now();

		solve(0, tmp);

		end = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsed_seconds = end - start;
		cout << elapsed_seconds.count() << "s" << endl;

		cout << "#" << " " << maxlength << '\n';

	}
	
}
