#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;

int n = 5;

void solve (int m, vector<int> & buffer) {
	if (m == 0) {
		for (int i = 0; i < buffer.size(); i++) {
			cout << buffer[i] << " ";
		}
		cout << '\n';
		return;
	}

	int curr = buffer.size() == 0 ? 0 : buffer.back();

	for (int i = curr; i < n; i++) {
		buffer.push_back(i);
		solve(m-1, buffer);
		buffer.pop_back();
	}
}

void solve2(int m, unordered_set<int> &set, vector<int> & buffer) {
	if (m == 0) {
		for (int i = 0; i < buffer.size(); i++) {
			cout << buffer[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++) {
		if (set.find(i) == set.end()) {
			set.insert(i);
			buffer.push_back(i);
			solve2(m - 1, set, buffer);
			set.erase(i);
			buffer.pop_back();
		}
	}


}

int main() {

	vector<int> tmp;
	unordered_set<int> tmp2;
	solve2(3, tmp2, tmp);

	while(1){}
}
