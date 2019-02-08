#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {

	int t;
	cin >> t;
	for (int z = 0; z < t; z++) {

		int n;
		cin >> n;
		double total = 0;
		for (int i = 0; i < n; i++) {

			double prob;
			double money;
			cin >> prob;
			cin >> money;
			total = total + prob * money;

		}

		cout << fixed << setprecision(7);
		cout << "#" << (z + 1) << " " << total << endl;

	}

}
