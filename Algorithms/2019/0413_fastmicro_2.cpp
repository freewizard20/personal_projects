#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for (int z = 0; z < t; z++) {
		int s, t, a, b;
		cin >> s >> t >> a >> b;
		int result = -1;
		if (b == 1) {
			if((t-s)%a == 0) result = (t - s) / a;
		}
		else {
			result = 0;
			while (t != s) {
				result++;
				if (t%b == 0) {
					if (t / b < s) t -= a;
					else t /= b;
				}
				else {
					t -= a;
				}
				if (t < s) {
					result = -1;
					break;
				}
			}
		}
		cout << "#" << (z+1) << ' ' << result << endl;
	}
	return 0;
}
