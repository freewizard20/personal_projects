#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int init(vector<int> & data, vector<int> & segtree, int high, int low, int node) {
	// base case
	if (low == high) {
		segtree[node] = data[low];
		return data[low];
	}
	// general case
	int mid = (low + high) / 2;
	int left = init(data, segtree, mid, low, 2 * node + 1);
	int right = init(data, segtree, high, mid + 1, 2 * node + 2);
	segtree[node] = min(left, right);
	return segtree[node];
}

void preprocess(vector<int> & data, vector<int> & segtree) {
	segtree.resize(data.size() * 4);
	for (int i = 0; i < segtree.size(); i++) {
		segtree[i] = INT_MAX;
	}
	init(data, segtree, data.size()-1,0, 0);
}

int findmin(vector<int> & segtree, int low, int high, int clow, int chigh, int curr) {
	// base case
	if (low == clow && high == chigh) return segtree[curr];
	// general case
	int mid = (clow + chigh) / 2;
	if (low <= mid&& high >= mid + 1) {
		return min(findmin(segtree, low, mid, clow, mid, curr * 2 + 1), findmin(segtree, mid + 1, high, mid + 1, chigh, curr * 2 + 2));
	}
	else if (high <= mid) {
		return findmin(segtree, low, high, clow, mid, curr * 2 + 1);
	}
	else {
		return findmin(segtree, low, high, mid + 1, chigh, curr * 2 + 2);
	}
}

int findmin2(vector<int> & segtree, int low, int high, int m) {
	return findmin(segtree, low, high, 0, m-1, 0);
}

int main() {
	vector<int> v1 = { 1,3,2,7,9,11 };
	vector<int> segtree;
	preprocess(v1, segtree);
	for (int x : segtree) cout << x << " ";
	cout << endl;
	cout << findmin2(segtree, 1, 5, v1.size()) << endl;
	while(1){}
	return 0;
}
