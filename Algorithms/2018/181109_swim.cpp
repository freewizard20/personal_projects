#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int a, b, c, d;
int days[12];
int filled[12];

int solve(int curr) {
	//cout << curr << endl;
	/*for (int i = 0; i < 12; i++) {
	cout << filled[i] << " ";
	}
	cout << endl;*/
	int tmp = 0;
	for (int i = 0; i < 12; i++) {
		tmp += filled[i];
	}
	if (tmp > 0) {
		//cout << "filled " << tmp << endl;
		return tmp;
	}

	int ret = 999999;

	// fill this with days
	filled[curr] = days[curr] * a;
	ret = min(ret, solve(curr == 11 ? 0 : curr + 1));
	filled[curr] = -999999;

	if (days[curr] == 0) {
		return ret;
	}

	// fill this with month
	filled[curr] = b;
	ret = min(ret, solve(curr == 11 ? 0 : curr + 1));
	filled[curr] = -999999;

	// fill this with 3month
	int prev = curr == 0 ? 11 : curr - 1;
	int next = curr == 11 ? 0 : curr + 1;
	filled[curr] = c;
	filled[prev] = 0;
	filled[next] = 0;
	ret = min(ret, solve((curr + 2) % 12));
	filled[curr] = -999999;
	filled[prev] = -999999;
	filled[next] = -999999;

	return ret;
}

int carry;

int solve2(int curr) {
	if (curr >= 12) {
		return carry;
	}

	int ret = 999999;
	ret = min(ret, solve2(curr + 1) + days[curr] * a);
	ret = min(ret, solve2(curr + 1) + b);
	ret = min(ret, solve2(curr + 3) + c);

	return ret;
}


int main() {
	int t;
	cin >> t;
	for (int z = 0; z < t; z++) {

		cin >> a >> b >> c >> d;
		for (int i = 0; i < 12; i++) {
			cin >> days[i];
			filled[i] = -999999;
		}

		int tot = d;
		tot = min(tot, solve2(0));
		cout << "#" << (z + 1) << " " << tot << '\n';

	}
}
