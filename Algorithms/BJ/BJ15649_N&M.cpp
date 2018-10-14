#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

void solve(int n, int m, vector<int> buffer) {

	if (m == 0) {
		for (int i = 0; i < buffer.size(); i++) {
			cout << buffer[i]+1 << " ";
		}
		cout << endl;
		return;
	}

	int small = buffer.size() == 0 ? -1 : buffer.back();
	//cout << "small " << small << endl;
	for (int i = small + 1; i < n; i++) {
		//cout << n << " " << m << " " << i << endl;
		buffer.push_back(i);
		solve(n, m - 1, buffer);
		buffer.pop_back();
	}
}

void permutation(int n, int m, unordered_set<int> set, vector<int> buf) {
	if (m == 0) {
		for (int i = 0; i < buf.size(); i++) {
			cout << buf[i]+1 << " " ;
		}
		cout << '\n';
	}

	for (int i = 0; i < n; i++) {
		if (set.find(i) == set.end()) {
			set.insert(i);
			buf.push_back(i);
			permutation(n, m - 1, set, buf);
			buf.pop_back();
			set.erase(i);
		}
	}

}

int main() {

	int n, m;
	cin >> n >> m;
	//solve(n, m, vector<int>());
	permutation(n, m, unordered_set<int>(), vector<int>());
	while(1){}

}
