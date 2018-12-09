#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <set>

using namespace std;

int board[10][10];
int n;
int k;
int fill2[10][10];



int main() {

	int m;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> fill2[i][j];
		}
	}

	vector<vector<vector<int>>> trees(n, vector<vector<int>>(n, vector<int>()));

	for (int i = 0; i < m; i++) {

		int a, b, c;
		cin >> a >> b >> c;
		trees[a-1][b-1].push_back(c);

	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sort(trees[i][j].begin(), trees[i][j].end());
			board[i][j] = 5;
		}
	}

	for (int i = 0; i < k; i++) {
		// spring - summer
		for (int a = 0; a < n; a++) {
			for (int b = 0; b < n; b++) {
				vector<int> dead;
				for (int z = 0; z < trees[a][b].size(); z++) {
					if (board[a][b] >= trees[a][b][z]) {
						board[a][b] -= trees[a][b][z];
						trees[a][b][z]++;
					}
					else {
						dead.push_back(trees[a][b][z]);
						trees[a][b].erase(trees[a][b].begin() + z);
						z--;
					}
				}

				for (int i = 0; i < dead.size(); i++) {

					board[a][b] += dead[i] / 2;
				}

			}
		}

		// fall
		for (int a = 0; a < n; a++) {
			for (int b = 0; b < n; b++) {
				for (int z = 0; z < trees[a][b].size(); z++) {
					if (trees[a][b][z] % 5 == 0) {
						for (int y = -1; y <= 1; y++) {
							for (int z = -1; z <= 1; z++) {
								if (!(y == 0 && z == 0)) {
									int tmpx = a + y;
									int tmpy = b + z;
									if (tmpx >= 0 && tmpx < n && tmpy >= 0 && tmpy < n) {

										trees[tmpx][tmpy].push_back(1);
										
									
									}
								}
							}
						}
					}
				}
			}
		}

		// winter
		for (int a = 0; a < n; a++) {
			for (int b = 0; b < n; b++) {
				sort(trees[a][b].begin(), trees[a][b].end());
				board[a][b] += fill2[a][b];
			}
		}


	}

	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			count = count + trees[i][j].size();
		}
	}

	cout << count << endl;

}
