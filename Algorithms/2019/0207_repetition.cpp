#include <iostream>
#include <string>


using namespace std;

int main() {

	int t;
	cin >> t;
	for (int z = 0; z < t; z++) {

		string curr;
		cin >> curr;
		int candidate = 0;
		for (int i = 0; i < 30; i++) {
			// check until i if candidate holds, if not assign candidate = i
			int runner = 0;
			int cycler = 0;
			int holds = 1;
			while (runner <= i) {
				if (curr[runner] != curr[cycler]) {
					holds = 0;
					break;
				}
				runner++;
				cycler++;
				if (cycler >= candidate) {
					cycler = 0;
				}
			}

			if (holds == 0) {
				candidate = i;
			}
		}

		cout << "#" << (z + 1) << " " << candidate << endl;

	}

}
