#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <string>

using namespace std;

int main() {
	int z = stoi("132323");
	cout << z << endl;
	while(1){}
	return 0;
}

// do your best until the last moment

string sam() {
	string s = "hello";
	string g = "sad";
	string z = "asdasd";
	return s+g+z;
}

string sam(int n) {
	string ret = "";
	while (n != 0) {
		ret.insert(ret.begin(), n % 3 + '0');
		n /= 3;
	}
	return ret;
}

int mai554n() {
	cout << sam(13231212) << endl;
	cout << (1 > 0 ? 32 : 23) + (1 < 0 ? 11 : 11) << endl;
	while(1){}
	string ss = "hello";
	string dd = "bueees";
	ss += string(dd.begin(), dd.end());
	ss += string(5, 'z');
	cout << ss << endl;
	while(1){}
	string s = "hello world";
	unordered_set<char> test(s.begin(), s.end());
	for (auto it = test.begin(); it != test.end(); it++) {
		cout << *it << endl;
	}

	while(1){}
	return 0;
}

// know everything

int dividemoney(vector<int> & data) {
	// calculate sum
	int sum = 0;
	for (int i = 0; i < data.size(); i++) {
		sum += data[i];
	}
	// re calculate delta
	for (int i = 0; i < data.size(); i++) {
		data[i] = data[i] - sum/data.size();
		if (data[i] % 3 != 0) return -1;
	}
	// calculate min transactions
	sort(data.begin(), data.end());
	int fill = 0; int push = data.size() - 1;
	int count = 0;
	while (fill < push) {
		if (data[fill] == 0) {
			fill++; continue;
		}
		if (data[push] == 0) {
			push--; continue;
		}
		cout << fill << " " << push << endl;
		// fill and push is not zero
		if (data[fill] + data[push] == 0) {
			data[fill] = 0;
			data[push] = 0;
		}
		else if (data[fill] + data[push] > 0) {
			// push is bigger
			data[push] = data[push] + data[fill];
			data[fill] = 0;
		}
		else {
			// fill is bigger
			data[fill] = data[push] + data[fill];
			data[push] = 0;
		}
		count++;
	}
	return count;
}

int ma323in() {
	vector<int> v1 = { 5, 8, 11 };
	cout << dividemoney(v1) << endl;
	while(1){}
	return 0;
}
