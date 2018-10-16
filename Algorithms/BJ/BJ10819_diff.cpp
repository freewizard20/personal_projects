#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int n;
int arr[8];

int solve(int m, vector<int> buffer, unordered_set<int> set) {
	if (m == 0) {
		int tot = 0;
		for (int i = 0; i < n-1; i++) {
			//cout << arr[buffer[i]] << " " << arr[buffer[i + 1]] << endl;
			tot += abs(arr[buffer[i]] - arr[buffer[i + 1]]);
		}
		
		//cout << endl;
		return tot;
	}



	int ret = 0;
	for (int i = 0; i < n; i++) {
		if (set.find(i) == set.end()) {
			set.insert(i);
			buffer.push_back(i);
			ret = max(ret,solve(m - 1, buffer, set));
			buffer.pop_back();
			set.erase(i);
		}

	}
	return ret;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	cout << solve(n, vector<int>(), unordered_set<int>()) << endl;
	while(1){}
}
