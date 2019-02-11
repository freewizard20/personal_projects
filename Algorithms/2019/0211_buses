// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWczm7QaACgDFAWn&categoryId=AWczm7QaACgDFAWn&categoryType=CODE

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {

	int t;
	cin >> t;
	for (int z = 0; z < t; z++) {

		int n;
		cin >> n;
		vector<vector<int>> tmp(5000, vector<int>(n, 0));
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			for (int j = a - 1; j <= b - 1; j++) {
				tmp[j][i] = 1;
			}
		}
		int p;
		cin >> p;
		vector<int> ans;
		for (int i = 0; i < p; i++) {
			int curr;
			cin >> curr;
			int tot = 0;
			for (int j = 0; j < n; j++) {
				tot += tmp[curr-1][j];
			}
			ans.push_back(tot);
		}

		cout << "#" << (z + 1) << " ";
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << " ";
		}
		cout << endl;
	}

}
