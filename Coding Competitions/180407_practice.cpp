#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <stack>
#include <map>
#include <unordered_map>
using namespace std;



int s4s44main() {
	string s = "abcdefghijklmn";
	string t = "sjin";
	cout << s << endl;
	s.erase(s.begin()+5,s.begin()+9);
	cout << s << endl;
	while(1){}
	return 0;
}

bool findsum(vector<int> & data, vector<vector<int>> & cache, int curr, int remain) {
	if (remain < 0) return false;
	if (remain == 0) return true;
	if (curr == 0) return false;
	// general case
	if (cache[curr][remain] != -1) return cache[curr][remain];
	cache[curr][remain] = findsum(data, cache, curr - 1, remain) || findsum(data, cache, curr - 1, remain - data[curr]);
	return cache[curr][remain];
}

int findmaxrod(vector<int> & prices, vector<int> & cache, int n) {
	if (n == 1) return prices[0];
	if (cache[n] != -1) return cache[n];
	int ret = 0;
	for (int i = 1; i < n; i++) {
		int tmp = prices[i - 1] + findmaxrod(prices, cache, n - i);
		if (ret < tmp) ret = tmp;
	}
	cache[n] = ret;
	return ret;
}

int findmaxsquare(vector<vector<int>> & board, vector<vector<int>> & cache, int m, int n) {
	if ((m == 0 || n == 0) && board[m][n] == 1) return 1;
	if ((m == 0 || n == 0) && board[m][n] == 0) return 0;
	if (cache[m][n] != -1) return cache[m][n];
	// general case
	int ret = min(board[m - 1][n - 1], board[m][n - 1]);
	ret = min(board[n - 1][n], ret);
	cache[m][n] = ret + 1;
	return ret + 1;
}

int findcases(vector<int> & coins, int curr, int total) {
	if (total == 0) return 1;
	if (total < 0) return 0;
	if (curr < 0) return 0;
	return findcases(coins, curr - 1, total) + findcases(coins, curr, total - coins[curr]);
}

class lru {
public:
	vector<int> v1;
};

int m2323ain() {
	lru sam;
	sam.v1.push_back(32);
	cout << sam.v1[0] << endl;
	while(1){}
	return 0;
}

// do it perfectly

int main221() {
	vector<int> t8 = { 1,2,3,4,5 };
	int & sam = t8.at(1);
	sam = 2323;
	cout << t8[1] << endl;
	multimap<int, int> map;
	map.insert(pair<int, int>(5, 3));
	map.insert(pair<int, int>(5, 100));
	map.insert(pair<int, int>(5, 2));
	map.insert(pair<int, int>(5, 1));
	map.insert(pair<int, int>(5, 4));
	map.insert(pair<int, int>(5, 5));
	map.insert(pair<int, int>(5, 3));
	multimap<int, int> map2;
	map2.insert(pair<int, int>(5, 3));
	map2.insert(pair<int, int>(5, 100));
	map2.insert(pair<int, int>(5, 3));
	map2.insert(pair<int, int>(5, 7));
	map2.insert(pair<int, int>(5, 4));
	map2.insert(pair<int, int>(5, 5));
	map2.insert(pair<int, int>(5, 3));
	if (map == map2) cout << "asdasdad" << endl;
	if (map >= map2) cout << "asdasdad2" << endl;
	if (map <= map2) cout << "asdasdad3" << endl;
	cout << map.find(5)->second << endl;
	pair<int, int> s = { 1,1 };
	pair<int, int> t = { 1,1 };
	if (s == t) {
		cout << "yeh" << endl;
	}
	vector<int> sa = { 1,2,3,8 };
	vector<int> sb = { 2,2,3, 4 };
	sb.reserve(100);
	if (sa < sb) {
		cout << "asd" << endl;
	}
	while(1){}
	return 0;
}

// do it fast and efficient. professionally

void func3() {
	vector<vector<int>> tmp = { {1,2,3},{4,5,6},{7,8,9} };
	vector<vector<int>> psum(3, vector<int>(3, 0));
	psum[0][0] = tmp[0][0];
	vector<vector<int>> psumx(3, vector<int>(3, 0));
	for (int j = 0; j < 3; j++) {
		psumx[0][j] = tmp[0][j];
		for (int i = 1; i < 3; i++) {
			psumx[i][j] = psumx[i - 1][j]+tmp[i][j];
		}
	}
	// make psum
	for (int i = 0; i < 3; i++) {
		psum[i][0] = psumx[i][0];
		for (int j = 1; j < 3; j++) {
			psum[i][j] = psum[i][j - 1] + psumx[i][j];
		}
	}
	// iterate through all members
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = i; k < 3; k++) {
				for (int l = j; l < 3; l++) {
					int sum;
					if (i == 0 && j == 0) {
						sum = psum[k][l];
					}
					else if (i == 0) {
						sum = psum[k][l] - psum[k][j - 1];
					}
					else if (j == 0) {
						sum = psum[k][l] - psum[i - 1][l];
					}
					else {
						sum = psum[k][l] - psum[i - 1][l] - psum[k][j - 1] + psum[i - 1][j - 1];
					}
					cout << "(" << i << "," << j << ")" << " to " << "(" << k << "," << l << ")" << " sum " << sum << endl;
				}
			}
		}
	}

}

void func2() {
	vector<int> v1 = { 1,2,3,4,5 };
	// make psum
	vector<int> psum(v1.size() + 1, 0);
	psum[0] = 0;
	for (int i = 1; i <= v1.size(); i++) {
		psum[i] = psum[i - 1] + v1[i - 1];
	}
	// find all partial sums
	for (int i = 0; i < v1.size(); i++) {
		for (int j = i; j < v1.size(); j++) {
			cout << "sum of " << i << " " << j << " " << psum[j + 1] - psum[i] << endl;
		}
	}
	// make psum without psum[-1] = 0;
	psum[0] = v1[0];
	for (int i = 1; i < v1.size(); i++) {
		psum[i] = psum[i - 1] + v1[i];
	}
	// find all partial sums
	for (int i = 0; i < v1.size(); i++) {
		for (int j = i; j < v1.size(); j++) {
			if (i == 0) cout << i << " " << j << " " << psum[j];
			else cout << i << " " << j << " " << psum[j] - psum[i - 1];
		}
	}
}

vector<int> func() {
	vector<int> v1 = { 1,2,3,4,5 };
	return vector<int>(v1.begin(), v1.begin() + 2);
}

int mai2323n() {
	func3();
	while(1){}
	return 0;
}

//--- do it professionally

string csort(string s) {
	vector<int> count(26, 0);
	// go through and count
	for (int i = 0; i < s.size(); i++) {
		count[s[i] - 'a']++;
	}
	// make new string using count
	string ret;
	ret.reserve(s.size());
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < count[i]; j++) {
			ret.push_back('a' + i);
		}
	}
	return ret;
}

vector<vector<string>> anagrams(vector<string> * data) {
	// use inner hash table
	unordered_map<string, vector<string>> tmp;
	// go through data and sort string, find key and append at vector
	for (int i = 0; i < data->size(); i++) {
		string s = csort(data->at(i));
		auto it = tmp.find(s);
		if (it != tmp.end()) {
			it->second.push_back(data->at(i));
		}
		else {
			// if this anagram is new
			vector<string> ss;
			ss.push_back(data->at(i));
			tmp.insert(pair<string, vector<string>>(s, ss));
		}
	}
	// append all vectors to return vector
	vector<vector<string>> ret;
	for (auto it = tmp.begin(); it != tmp.end(); it++) {
		ret.push_back(it->second);
	}
	return ret;
}

int main9909() {
	vector<string> data = { "eat", "tea", "tan", "ate", "nat", "bat" };
	vector<vector<string>> ret = anagrams(&data);
	for (int i = 0; i < ret.size(); i++) {
		for (int j = 0; j < ret.at(i).size(); j++) {
			cout << ret.at(i).at(j) << " ";
		}
		cout << endl;
	}
	while(1){}
	return 0;
}
