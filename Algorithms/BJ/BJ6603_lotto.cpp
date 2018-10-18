#include <vector>
#include <iostream>

using namespace std;

int n;
int num[13];

void solve(vector<int> buffer, int m) {
	if (m == 0) {
		for (int i = 0; i < 6; i++) {
			cout << num[buffer[i]] << " ";
		}
		cout << "\n";
		return;
	}
	
	int small = buffer.size() == 0 ? 0 : buffer.back() + 1;
	for (int i = small; i < n; i++) {
		buffer.push_back(i);
		solve(buffer, m - 1);
		buffer.pop_back();
	}


}

int main() {

	while (true) {
		cin >> n;
		if (n == 0) break;
		for (int i = 0; i < n; i++) {
			cin >> num[i];
		}
		solve(vector<int>(), 6);
		cout << '\n';
	}

}
