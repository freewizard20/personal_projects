#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>


using namespace std;



int a[9];
int b[9];
int win;
int lose;

void solve(int m, unordered_set<int> & set, vector<int> & tmp) {

	if (m == 9) {
		
		// play game
		int totala = 0;
		int totalb = 0;

		for (int i = 0; i < 9; i++) {
			if (a[i] > b[tmp[i]]) {
				totala = totala + a[i] + b[tmp[i]];
			}
			else {
				totalb = totalb + a[i] + b[tmp[i]];
			}

		}

		if (totala > totalb) {
			win++;
		}
		else {
			lose++;
		}


		return;
	}

	for (int i = 0; i < 9; i++) {
		if (set.find(i) == set.end()) {
			set.insert(i);
			tmp.push_back(i);
			solve(m+1, set, tmp);
			tmp.pop_back();
			set.erase(i);
		}
	}

}

int main() {

	int t;
	cin >> t;
	for (int z = 0; z < t; z++) {

		for (int i = 0; i < 9; i++) {
			cin >> a[i];
		}

		// fill b
		int counter = 0;
		for (int i = 1; i <= 18; i++) {
			int contains = 0;
			for (int j = 0; j < 9; j++) {
				if (a[j] == i) {
					contains = 1;
				}
			}
			if (contains != 1) {
				b[counter] = i;
				counter++;
			}
		}

		// iterate and play game
		win = 0;
		lose = 0;
		vector<int> tmp;
		unordered_set<int> set;
		solve(0, set, tmp);
		
		cout << "#" << (z + 1) << " " << win << " " << lose << endl;
	}
	while(1){}
}
