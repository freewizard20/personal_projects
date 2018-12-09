#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ans[3];
int max2[3];
int curr[3] = { 1,1,1 };
int curry = 1;

bool issame() {
	for (int i = 0; i < 3; i++) {
		if (ans[i] != curr[i]) return false;
	}
	return true;

}

void add() {
	curry++;
	for (int i = 0; i < 3; i++) {
		if (curr[i] == max2[i]) curr[i] = 1;
		else curr[i]++;
	}
}

int main() {
	max2[0] = 15;
	max2[1] = 28;
	max2[2] = 19;
	cin >> ans[0] >> ans[1] >> ans[2];
	while (!issame()) {
		add();
	}
	cout << curry << endl;

}
