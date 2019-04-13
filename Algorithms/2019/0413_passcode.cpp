#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

string code;
int n, ki;
vector<int> numberpool;

void rotate(string &s) {
	char tmp = s.back();
	s.pop_back();
	s = tmp + s;
	return;
}

int converter(char letter) {
	if (letter >= 'A' && letter <= 'F') {
		return 10 + letter - 'A';
	}
	else {
		return letter - '0';
	}
}

int main() {
	int t;
	cin >> t;
	for (int z = 0; z < t; z++) {
		numberpool.clear();
		cin >> n >> ki;
		cin >> code;
		for (int i = 0; i < n / 4; i++) {
			for (int j = 0; j <= 3; j++) {
				int curr = 0;
				for (int k = n/4; k >= 1; k--) {
					//cout << code[3*j + 3 - k];
					curr += (int) pow(16, k-1) * converter(code[(n/4)*j + (n/4) - k]);
				}
				//cout << endl;
				numberpool.push_back(curr);
			}
			rotate(code);
		}
		
		sort(numberpool.begin(), numberpool.end(), greater<int>());
		//cout << "s" << numberpool.size() << endl;

		int answer = 0;
		int line = 0;
		
		for (int i = 0; i < numberpool.size(); i++) {
			if (i != numberpool.size() - 1 && numberpool[i] != numberpool[i + 1]) {
				line++;
			}
			if (i == numberpool.size()-1) line++;
			if (line == ki) {
				answer = numberpool[i];
				break;
			}
		}

		cout << "#" << (z + 1) << " " << answer << endl;
	}

	return 0;
}
