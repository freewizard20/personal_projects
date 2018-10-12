#include <iostream>

using namespace std;

int main() {
	//cin.tie(NULL);
	//ios::sync_with_stdio(false);

	int t,x,y;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> x >> y;
		cout << x + y << "\n";
	}
}
