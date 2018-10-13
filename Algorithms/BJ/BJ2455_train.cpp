#include <iostream>

using namespace std;

int on[4];
int off[4];

int main() {

	ios::sync_with_stdio(false);
	for (int i = 0; i < 4; i++) {
		cin >> off[i] >> on[i];
	}

	int max = 0;
	int curr = 0;
	for (int i = 0; i < 4; i++) {
		curr = curr + on[i] - off[i];
		if (curr > max) max = curr;
	}

	cout << max << endl;


}
