#include <vector>
#include <unordered_set>
#include <iostream>
#include <algorithm>

using namespace std;

int nums[11];
int n;
char args[10];

pair<int, int> solve(int m, vector<int>& buffer, unordered_set<int> & set) {
	if (m == 0) {

		int ret = nums[0];

		for (int i = 1; i < n; i++) {
			char curr = args[buffer[i - 1]];
			switch (curr) {
			case '+':
				ret += nums[i];
				break;
			case '-':
				ret -= nums[i];
				break;
			case '*':
				ret *= nums[i];
				break;
			case '/':
				ret /= nums[i];
				break;
			}
		}

		return pair<int, int>(ret, ret);
	}

	int retmax = INT_MIN;
	int retmin = INT_MAX;

	for (int i = 0; i < n - 1; i++) {
		if (set.find(i) == set.end()) {
			set.insert(i);
			buffer.push_back(i);
			auto it = solve(m - 1, buffer, set);
			retmax = max(retmax, it.first);
			retmin = min(retmin, it.second);
			set.erase(i);
			buffer.pop_back();
		}
	}

	return pair<int, int>(retmax, retmin);
}

int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	int arg[4];
	cin >> arg[0] >> arg[1] >> arg[2] >> arg[3];
	
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < arg[i]; j++) {
			if (i == 0) {
				args[cnt] = '+';
				cnt++;
			}
			else if (i == 1) {
				args[cnt] = '-';
				cnt++;
			}
			else if (i == 2) {
				args[cnt] = '*';
				cnt++;
			}
			else {
				args[cnt] = '/';
				cnt++;
			}
		}
	}

	vector<int> tmp;
	unordered_set<int> tmp2;
	auto it = solve(n - 1, tmp, tmp2);
	cout << it.first << endl;
	cout << it.second << endl;

}
