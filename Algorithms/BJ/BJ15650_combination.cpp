#include <iostream>
#include <vector>

using namespace std;

void solve(int n, int m, vector<int> buffer) {
	if (m == 0) {
		for (int i = 0; i < buffer.size(); i++) {
			cout << buffer[i]+1 << " ";
		}
		cout << '\n';
		return;
	}

	int small = buffer.size() == 0 ? 0 : buffer.back()+1;


	for (int i = small; i < n; i++) {
		buffer.push_back(i);
		solve(n, m - 1, buffer);
		buffer.pop_back();
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	solve(n, m, vector<int>());
	while(1){}
}
