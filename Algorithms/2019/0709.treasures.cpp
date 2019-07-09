// SWE 7829

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int z = 0; z < t; z++) {
		int p;
		cin >> p;
		vector<int> divisors(p,0);
		for (int i = 0; i < p; i++) {
			cin >> divisors[i];
		}
		sort(divisors.begin(), divisors.end());
		if (divisors.size()%2==0) {
			cout << "#" << (z + 1) << " " << divisors[divisors.size() / 2] * divisors[divisors.size() / 2 - 1];
		}
		else {
			cout << "#" << (z + 1) << " " << divisors[divisors.size() / 2] * divisors[divisors.size() / 2];
		}
	}
}
