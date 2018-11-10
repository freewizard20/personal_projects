#include <vector>
#include <iostream>

using namespace std;

int n;
vector<int> buffer;

void solve(int m) {
	if (m == n) {
		for (int i = 0; i < buffer.size(); i++) {
			cout << buffer[i] << " ";
		}
		cout << endl;
		return;
	}

	buffer.push_back(0);
	solve(m + 1);
	buffer.pop_back();

	buffer.push_back(1);
	solve(m + 1);
	buffer.pop_back();
	return;
}

int main() {

	n = 5;
	solve(0);

	while(1){}

}
