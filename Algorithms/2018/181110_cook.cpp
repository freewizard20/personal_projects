#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

int n;
int board[16][16];

int getsum(int m, vector<int> & ref, unordered_set<int> & order, vector<int> & buffer) {

	if (m == 0) {
		return board[ref[buffer[0]]][ref[buffer[1]]];
	}

	int tot = 0;
	for (int i = 0; i < n/2; i++) {
		if (order.find(i) == order.end()) {
			order.insert(i);
			buffer.push_back(i);
			tot += getsum(m - 1, ref, order, buffer);
			buffer.pop_back();
			order.erase(i);
		}
	}

	return tot;
}

int solve(int m, vector<int> & buffer) {
	if (m == 0) {
		vector<int> rebuffer;
		for (int i = 0; i < n; i++) {
			int flag = 0;
			for (int j = 0; j < buffer.size(); j++) {
				if (buffer[j] == i) {
					flag = 1;
					break;
				}
			}
			if (flag == 0) {
				rebuffer.push_back(i);
			}
		}
		vector<int> tmp;
		unordered_set<int> set;
		int sum1 = getsum(2,buffer, set, tmp);
		int sum2 = getsum(2,rebuffer, set, tmp);

		/*cout << "---" << endl;
		for (int i = 0; i < buffer.size(); i++) {
			cout << buffer[i] << " ";
		}
		cout << endl;
		for (int i = 0; i < rebuffer.size(); i++) {
			cout << rebuffer[i] << " ";
		}
		cout << endl;
		cout << "res " << sum1 << " " << sum2 << " " << abs(sum1 - sum2) << endl;*/

		return abs(sum1 - sum2);


	}

	int small = buffer.size() == 0 ? 0 : buffer.back() + 1;
	int ret = 99999999;

	for (int i = small; i < n; i++) {
		buffer.push_back(i);
		ret = min(ret,solve(m - 1, buffer));
		buffer.pop_back();
	}

	return ret;
}

int main() {

	int t;
	cin >> t;
	for (int z = 0; z < t; z++) {

		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> board[i][j];
			}
		}
		vector<int> tmp;
		cout << "#" << (z + 1) << " " << solve(n/2,tmp) << endl;

	}

}
