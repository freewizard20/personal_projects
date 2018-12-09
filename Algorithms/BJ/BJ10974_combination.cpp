#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>


using namespace std;

int n;

void solve(int m, vector<int> buffer, unordered_set<int> set) {
	if (m == 0) {
		for (int i = 0; i < buffer.size(); i++) {
			cout << buffer[i]+1 << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++) {
		if (set.find(i) == set.end()) {
			set.insert(i);
			buffer.push_back(i);
			solve(m - 1, buffer, set);
			set.erase(i);
			buffer.pop_back();
		}

	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	solve(n,vector<int>(),unordered_set<int>());
	while(1){}
}
