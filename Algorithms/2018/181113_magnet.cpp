#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int magnet[4][8];
int k;

void rotate(int n, int c) {

	if (c == -1) {
		int tmp = magnet[n][0];
		for (int i = 0; i < 7; i++) {
			magnet[n][i] = magnet[n][i + 1];
		}
		magnet[n][7] = tmp;
	}
	else if(c==1){
		int tmp = magnet[n][7];
		for (int i = 7; i > 0; i--) {
			magnet[n][i] = magnet[n][i - 1];
		}
		magnet[n][0] = tmp;
	}
	else {

	}

}

int rotatemark[4];

void move(int n, int c) {

	int sam1 = n - 1;
	int sam2 = n + 1;

	for (int i = 0; i < 4; i++) {
		rotatemark[i] = 0;
	}

	rotatemark[n] = c;

	while (sam1 >= 0 || sam2 <= 3) {

		c = -c;

		if (sam1>=0 && ((magnet[sam1][2] == 1 && magnet[sam1 + 1][6] == 0) || (magnet[sam1][2] == 0 && magnet[sam2][6] == 1))) {
			rotatemark[sam1] = c;
		}
		else {
			sam1 = -1;
		}

		if (sam2<=3 && ((magnet[sam2][6] == 1 && magnet[sam2 - 1][2] == 0) || (magnet[sam2][6] == 0 && magnet[sam2 - 1][2] == 1))) {
			rotatemark[sam2] = c;
		}
		else {
			sam2 = 4;
		}

	}

	for (int i = 0; i < 4; i++) {
		rotate(i, rotatemark[i]);
	}

}

int main() {

	int t;
	cin >> t;
	for (int z = 0; z < t; z++) {

		cin >> k;

		for (int j = 0; j < 4; j++) {
			for (int l = 0; l < 8; l++) {
				cin >> magnet[j][l];
			}
		}

		for (int i = 0; i < k; i++) {

			int c, n;
			cin >> n >> c;
			move(n-1, c, 2);

		}


		int tot = 0;
		for (int i = 0; i < 4; i++) {
			tot += (int)pow(2, i) * magnet[i][0];
		}

		cout << "#" << (z + 1) << " " << tot << '\n';

	}

}
