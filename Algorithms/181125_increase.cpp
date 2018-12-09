#include <iostream>
#include <vector>

using namespace std;

int n;
int arr[1000];

int max(int a, int b) {
	return a > b ? a : b;
}

bool test(int curr) {

	int smallest = 10;
	while (curr != 0) {
		int i = curr % 10;
		if (smallest < i) {
			return false;
		}
		smallest = i;
		curr /= 10;
	}

	return true;
}

int solve(int m, vector<int> & tmp) {

	if (m == 0) {
		
		int curr = arr[tmp[0]] * arr[tmp[1]];
		//cout << curr << endl;
		if (test(curr)) {
			return curr;
		}
		else {
			return -1;
		}

	}

	int small = tmp.size() == 0 ? 0 : tmp.back() + 1;
	int ret = -1;

	for (int i = small; i < n; i++) {
		tmp.push_back(i);
		ret = max(ret,solve(m - 1, tmp));
		tmp.pop_back();
	}

	return ret;

}

int main() {
	
	int t;
	cin >> t;

	for (int z = 0; z < t; z++) {

		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		vector<int> tmp;
		cout << "#" << (z+1) << " " << solve(2, tmp);


	}

	
}
