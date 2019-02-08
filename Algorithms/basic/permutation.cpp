#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


void solve(int m, vector<int> & tmp) {
	if (m == 0) {
		for (int i = 0; i < tmp.size(); i++) {
			cout << tmp[i] << " ";
		}
		cout << endl;
		return;
	}

	int small = tmp.size() == 0 ? 0 : tmp.back() + 1;

	for (int i = small; i < 5; i++) {
		tmp.push_back(i);
		solve(m - 1, tmp);
		tmp.pop_back();
	}
	return;
}

int main() {

	vector<int> tmp;
	solve(3, tmp);
	while(1){}

}
