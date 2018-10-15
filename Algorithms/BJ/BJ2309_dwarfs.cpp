#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int flag = 0;

void solve(const vector<int> & height, vector<int> buffer, int curr) {
	if (curr == 9) {
		if (flag == 0) {
			int tot = 0;
			for (int i = 0; i < buffer.size(); i++) {
				if (buffer[i] == 1) tot += height[i];
			}
			if (tot == 100) {
				vector<int> tmp;
				for (int i = 0; i < buffer.size(); i++) {
					if (buffer[i] == 1) {
						tmp.push_back(height[i]);
					}
				}
				sort(tmp.begin(), tmp.end());
				for (int i = 0; i < tmp.size(); i++) {
					cout << tmp[i] << '\n';
				}
				flag = 1;
			}
		}
		return;
	}

	buffer.push_back(1);
	solve(height, buffer, curr + 1);
	buffer.pop_back();
	buffer.push_back(0);
	solve(height, buffer, curr + 1);
	buffer.pop_back();
}
