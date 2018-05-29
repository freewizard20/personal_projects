#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

void permutation(vector<vector<char>> * result, vector<char> buffer, string s, int r) {
	if (r == 0) {
		result->push_back(buffer);
		return;
	}
	for (int i = 0; i < s.size(); i++) {
		char t = s.at(i);
		s.erase(s.begin() + i);
		buffer.push_back(t);
		permutation(result, buffer, s, r - 1);
		s.insert(s.begin() + i, t);
		buffer.erase(buffer.end() - 1);
	}
}
// time complexity : n * n-1 * ... n-r >> nPr O(nPr)
// space complexity : O(r*nPr)
// s = abcde, r = 2
// bcde r=1

void combination(vector<vector<char>> * result, vector<char> buffer, string s, int r) {
	if (r == 0) {
		result->push_back(buffer);
		return;
	}
	int min;
	if (buffer.size() == 0) {
		min = 0;
	}
	else {
		min = s.find(buffer.at(buffer.size() - 1)) + 1;
	}
	for (int i = min; i < s.size(); i++) {
		buffer.push_back(s.at(i));
		combination(result, buffer, s, r - 1);
		buffer.erase(buffer.end() - 1);
	}
}
// N * N-1 .... N-r / r! >> O(nCr)
// space complexity : O(r^2)
// abcde , r=2


void rotation(vector<vector<char>> * result, vector<char> buffer, string s, int r) {
	if (r == 0) {
		result->push_back(buffer);
		return;
	}
	for (int i = 0; i < s.size(); i++) {
		buffer.push_back(s.at(i));
		rotation(result, buffer, s, r - 1);
		buffer.erase(buffer.end() - 1);
	}
}


int main() {
	vector<vector<char>> result;
	vector<char> buffer;
	string s = "abcdefg";
	rotation(&result, buffer, s, 3);
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result.at(i).size(); j++) {
			cout << result.at(i).at(j);
		}
		cout << endl;
	}
	while (1) {}
	return 0;
}
