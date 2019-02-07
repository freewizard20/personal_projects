#include <iostream>
#include <vector>

using namespace std;

int n;
int points[100];
int able[10001];
int max;

void touch(int m, vector<int> & tmp) {

	if (m == 0) {

		int curr = 0;
		for (int i = 0; i < tmp.size(); i++) {
			curr += tmp[i] * points[i];
		}

		able[curr] = 1;

		return;
	}

	tmp.push_back(1);
	touch(m - 1, tmp);
	tmp.pop_back();

	tmp.push_back(0);
	touch(m - 1, tmp);
	tmp.pop_back();

	return;


}

int main() {
	int t;
	cin >> t;

	for (int z = 0; z < t; z++) {

		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> points[i];
		}

		max = 0;
		for (int i = 0; i < n; i++) {
			max += points[i];
		}

		vector<int> tmp;
		touch(n, tmp);

		int res = 0;
		for (int i = 0; i <= max; i++) {
			if (able[i] == 1) {
				res++;
			}
		}

		cout << "#" << (z + 1) << " " << res << endl;

	}
}
