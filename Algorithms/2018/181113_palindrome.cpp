#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

char board[8][8];
int n;

int isp2(int a, int b) {

	for (int i = 0; i < n; i++) {
		if (board[a + i][b] == board[a + n - i - 1][b]) {
			continue;
		}
		else {
			return 0;
		}
	}

	return 1;
}

int isp1(int a, int b) {

	for (int i = 0; i < n; i++) {
		if (board[a][b + i] == board[a][b + n - i - 1]) {
			continue;
		}
		else {
			return 0;
		}
	}

	return 1;

}

int main() {

	for (int z = 0; z < 10; z++) {

		cin >> n;
		for (int i = 0; i < 8; i++) {
			string tmp;
			cin >> tmp;
			for (int j = 0; j < 8; j++) {
				board[i][j] = tmp[j];
			}
		}

		int cnt = 0;

		for (int i = 0; i < 8; i++) {

			for (int j = 0; j < 9 - n; j++) {

				cnt += isp1(i, j);

			}

		}

		for (int j = 0; j < 8; j++) {
			for (int i = 0; i < 9 - n; i++) {
				cnt += isp2(i, j);
			}
		}

		cout << "#" << (z + 1) << " " << cnt << endl;

	}

}
