#include <vector>
#include <iostream>

using namespace std;

int solve(int n) {

	bool able[10001] = { 0, };
	able[0] = 1;

	int maxscore = 0;

	for (int i = 0; i < n; i++) {

		int score = 0;
		cin >> score;
		maxscore += score;

		for (int j = maxscore; j >= 0; j--) {

			if (able[j]) able[j + score] = true;

		}

	}

	int ret = 0;
	for (int i = 0; i < 10001; i++) {
	
		if (able[i]) ret++;

	}

	return ret;
}

int main() {

	int t;
	cin >> t;

	for (int z = 0; z < t; z++) {

		int n = 0;
		cin >> n;
		cout << "#" << (z + 1) << " " << solve(n) << endl;

	}

}
