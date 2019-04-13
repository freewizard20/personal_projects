#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <stack>
#include <unordered_set>

using namespace std;

int calcthree(string tmp) {
	int multiplier = 1;
	int ret = 0;
	for (int i = tmp.size() - 1; i >= 0; i--) {
		ret += multiplier * (tmp[i] - '0');
		multiplier *= 3;
	}
	return ret;
}

int calctwo(string tmp) {
	int multiplier = 1;
	int ret = 0;
	for (int i = tmp.size() - 1; i >= 0; i--) {
		ret += multiplier * (tmp[i] - '0');
		multiplier *= 2;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for (int z = 0; z < t; z++) {
		string two;
		string three;
		string tmp;
		int result = 0;
		cin >> two;
		cin >> three;
		unordered_set<int> madefromthrees;
		for (int i = 0; i < three.size(); i++) {
			if (three[i] == 1) {
				tmp = three;
				tmp[i] = '0';
				madefromthrees.insert(calcthree(tmp));
				tmp = three;
				tmp[i] = '2';
				madefromthrees.insert(calcthree(tmp));
			}
			else if (three[i] == 2) {
				tmp = three;
				tmp[i] = '1';
				madefromthrees.insert(calcthree(tmp));
				tmp = three;
				tmp[i] = '0';
				madefromthrees.insert(calcthree(tmp));
			}
			else {
				tmp = three;
				tmp[i] = '1';
				madefromthrees.insert(calcthree(tmp));
				tmp = three;
				tmp[i] = '2';
				madefromthrees.insert(calcthree(tmp));
			}
		}
		for (int i = 0; i < two.size(); i++) {
			if (two[i] == '0') {
				tmp = two;
				tmp[i] = '1';
				int sam = calctwo(tmp);
				if (madefromthrees.find(sam) != madefromthrees.end()) {
					result = sam;
				}
			}
			else {
				tmp = two;
				tmp[i] = '0';
				int sam = calctwo(tmp);
				if (madefromthrees.find(sam) != madefromthrees.end()) {
					result = sam;
				}
			}
		}
		cout << "#" << (z + 1) << " " << result << endl;
	}
	return 0;
}
