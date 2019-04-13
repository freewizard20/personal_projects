#include <iostream>
#include <vector>
#define MAX 99999999;
#define MIN -99999999;

using namespace std;

int numbers[12];
int op[4];
int n;
int max;
int min;

void solve(int m, vector<int> & tmp, vector<int> & opcount) {
	if (m == n - 1) {
		// calculate
		int result = numbers[0];
		for (int i = 0; i < n-1; i++) {
			if (tmp[i] == 0) {
				result += numbers[i+1];
			}
			else if (tmp[i] == 1) {
				result -= numbers[i+1];
			}
			else if (tmp[i] == 2) {
				result *= numbers[i+1];
			}
			else {
				result /= numbers[i+1];
			}
		}
		if (result > max) max = result;
		if (result < min) min = result;
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (opcount[i] < op[i]) {
			opcount[i]++;
			tmp.push_back(i);
			solve(m + 1, tmp, opcount);
			tmp.pop_back();
			opcount[i]--;
		}
	}
}

int main() {
	int t;
	cin >> t;
	for (int z = 0; z < t; z++) {
		max = MIN;
		min = MAX;
		cin >> n;
		cin >> op[0] >> op[1] >> op[2] >> op[3];
		for (int i = 0; i < n; i++) {
			cin >> numbers[i];
		}
		vector<int> tmp;
		vector<int> opcount(4,0);
		solve(0, tmp, opcount);
		cout << "#" << (z + 1) << " " << max - min << endl;
	}
	return 0;
}
