#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int n, m;
int arr[8];

void solve(vector<int> buffer, unordered_set<int> set, int k) {
	if (k == 0) {
		for (int i = 0; i < buffer.size(); i++) {
			cout << arr[buffer[i]] << " ";
		}
		cout << '\n';
		return;
	}
	
	for (int i = 0; i < n; i++) {
		if (set.find(i) == set.end()) {
			buffer.push_back(i);
			set.insert(i);
			solve(buffer, set, k - 1);
			buffer.pop_back();
			set.erase(i);
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	solve(vector<int>(), unordered_set<int>(), m);
}
