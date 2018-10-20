#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[20];
int target;
int n;

int solve(vector<int> buffer, int m) {
	if (m == 0) {
		int tot = 0;
		for (int i = 0; i < buffer.size(); i++) {
			tot += arr[buffer[i]];
		}
		if (tot == target) return 1;
		else return 0;
	}

	int curr = buffer.size() == 0 ? 0 : buffer.back() + 1;
	int ret = 0;

	for (int i = curr; i < n; i++) {
		buffer.push_back(i);
		ret += solve(buffer, m - 1);
		buffer.pop_back();
	}

	return ret;
}

int main() {
	cin >> n >> target;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int ret = 0;
	for (int i = 1; i <= n; i++) {
		ret += solve(vector<int>(), i);
	}
	cout << ret << endl;
}
