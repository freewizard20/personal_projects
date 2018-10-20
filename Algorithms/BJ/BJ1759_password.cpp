#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

char arr[15];
int l, c;

void solve(vector<int> buffer, int m) {
	if (m == 0) {
		int ja = 0;
		int mo = 0;
		for (int i = 0; i < l; i++) {
			if (arr[buffer[i]] == 'a' || arr[buffer[i]] == 'i' || arr[buffer[i]] == 'e' || arr[buffer[i]] == 'o' || arr[buffer[i]] == 'u') {
				mo++;
			}
			else {
				ja++;
			}
		
		}
		if (ja >= 2 && mo >= 1) {
			for (int i = 0; i < l; i++) {
				cout << arr[buffer[i]];
			}
			cout << '\n';
		}
		return;
	}
	int curr = buffer.size() == 0 ? 0 : buffer.back() + 1;
	for (int i = curr; i < c; i++) {
		buffer.push_back(i);
		solve(buffer, m - 1);
		buffer.pop_back();
	}
}

int main() {
	
	cin >> l >> c;
	for (int i = 0; i < c; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + c);
	solve(vector<int>(), l);
	while(1){}
}
