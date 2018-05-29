#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int findmax(vector<int> * tmp, int n, int max) {
	if (n == tmp->size()) {
		return max;
	}
	if (max < tmp->at(n)) {
		return findmax(tmp, n + 1, tmp->at(n));
	}
	else {
		return findmax(tmp, n + 1, max);
	}
}

int findmax2(vector<int> *tmp, int n) {
	if (n == tmp->size()) {
		return INT_MIN;
	}
	return tmp->at(n) > findmax2(tmp, n + 1) ? tmp->at(n) : findmax2(tmp, n + 1);
}

int findmaxsum(vector<int> * data, vector<int> * tmp, int curr) {
	if (curr == data->size()) {
		return findmax(tmp, 0, INT_MIN);
	}
	if (curr == 0) {
		tmp->push_back(data->at(0));
		return findmaxsum(data, tmp, curr + 1);
	}
	if (data->at(curr) > tmp->at(curr - 1) + data->at(curr)) {
		tmp->push_back(data->at(curr));
	}
	else {
		tmp->push_back(data->at(curr) + tmp->at(curr - 1));
	}
	return findmaxsum(data, tmp, curr + 1);
}

int findmaxsumiterator(vector<int> * data, int low, int high) {
	// base case
	if (low == high) {
		return data->at(low);
	}
	int mid = (low + high) / 2;
	// get three partitions
	int lw = findmaxsumiterator(data, low, mid);
	int hw = findmaxsumiterator(data, mid + 1, high);
	int mw = data->at(mid) + data->at(mid + 1);
	// to find mw, find sum until element and save at arr, find max sum in them
	int t = mid-1;
	vector<int> arr;
	arr.reserve(mid - low);
	// go low
	arr.push_back(mw);
	while (t >= low) {
		arr.push_back(arr.at(arr.size() - 1) + data->at(t));
		t--;
	}
	for (int i = 0; i < arr.size(); i++) {
		if (mw < arr.at(i)) {
			mw = arr.at(i);
		}
	}
	// go high
	t = mid + 2;
	arr.clear();
	arr.push_back(mw);
	while (t <= high) {
		arr.push_back(arr.at(arr.size() - 1) + data->at(t));
		t++;
	}
	for (int i = 0; i < arr.size(); i++) {
		if (mw < arr.at(i)) {
			mw = arr.at(i);
		}
	}
	return max(lw, max(hw, mw));
}

int findmaxsum2(vector<int> * data) {
	return findmaxsumiterator(data, 0, data->size() - 1);
}

int main() {
	vector<int> data = { 1,3,-2,4,-13,8,-1,10,-4,-8,-14 };
	vector<int> tmp;
	tmp.reserve(data.size());
	cout << findmaxsum2(&data);
	while (1) {}
	return 0;
	//find maximum continuous sum subsequence

}




int findfirstmin(vector<pair<int,int>> * data, int target, int low, int high) {
	// base case
	if (low == high - 1) {
		return low;
	}
	int mid = (low + high) / 2;
	if (data->at(mid).second == target) {
		while (data->at(mid).second == target && mid <= high) {
			mid++;
		}
		return mid - 1;
	}
	else if (data->at(mid).second < target) {
		return findfirstmin(data, target, mid , high);
	}
	else {
		return findfirstmin(data, target, low,mid);
	}
}

bool comparitor(pair<int, int> a, pair<int, int>b) {
	if (a.first > b.first) {
		return true;
	}
	else if (a.first < b.first) {
		return false;
	}
	else {
		if (a.second > b.second) {
			return true;
		}
		else {
			return false;
		}
	}
}

vector<pair<int, int>> findmaxtower(vector<pair<int, int>> * data) {
	//sort in decending order
	sort(data->begin(), data->end(), comparitor);
	//look for maximum stack
	vector<vector<pair<int,int>>> tmp;
	tmp.reserve(data->size());
	vector<pair<int, int>> t;
	t.reserve(data->size());
	t.push_back(data->at(0));
	tmp.push_back(t);
	for (int i = 1; i < data->size(); i++) {
		// cap new element in all buffer stacks when new is smaller than one before(there is at least one stack to cap)
		if (data->at(i - 1).second >= data->at(i).second) {
			for (int j = 0; j < tmp.size(); j++) {
				if (tmp.at(j).at(tmp.at(j).size() - 1).second >= data->at(i).second) {
					tmp.at(j).push_back(data->at(i));
				}
			}
		}
		// there cannot be any stack to cap because the smaller before element capped all possible, create new max stack with new element
		else {
			vector<pair<int, int>> max;
			for (int j = 0; j < tmp.size(); j++) {
				int firstmin = findfirstmin(&tmp.at(j), data->at(i).second, 0, tmp.at(j).size());
				if (max.size() < firstmin+1) {
					vector<pair<int, int>> m(tmp.at(j).begin(), tmp.at(j).begin() + firstmin+1);
					max = m;
				}
			}
			max.push_back(data->at(i));
			tmp.push_back(max);
		}
	}
	// find max length stack and return;
	// N^2logN
	int maxindex = 0;
	for (int i = 1; i < tmp.size(); i++) {
		if (maxindex < tmp.at(i).size()) {
			maxindex = tmp.at(i).size();
		}
	}
	return tmp.at(maxindex);
}

vector<pair<int, int>> findmaxtower2(vector<pair<int, int>> *data) {
	// sort array in descending order
	sort(data->begin(), data->end(), comparitor);
	vector<vector<pair<int, int>>> tmp;
	tmp.reserve(data->size());
	// iterate through elements and find maximum stack for every element, and use it to find next
	for (int i = 0; i < data->size(); i++) {
		vector<pair<int, int>> t;
		// go through all previous elements 
		for (int j = 0; j < tmp.size(); j++) {
			if (tmp.at(j).at(tmp.at(j).size() - 1).second > data->at(i).second) {
				if (t.size() < tmp.at(j).size()) {
					t = tmp.at(j);
				}
			}
		}
		t.push_back(data->at(i));
		tmp.push_back(t);
	}
	vector<pair<int, int>> ret;
	for (int i = 0; i < tmp.size(); i++) {
		if (ret.size() < tmp.at(i).size()) {
			ret = tmp.at(i);
		}
	}
	return ret;
}

bool comparitor2(int a, int b) {
	return a < b;
}



int main89() {
	vector<int> t = { 3,5,7,1,3,5,4,6,8 };
	sort(t.begin(), t.end(), comparitor2);
	for (int i : t) {
		cout << i << endl;
	}
	while (1) {}
	return 0;
}

void printv(vector<string> v1, int n) {
	if (n == v1.size()) {
		return;
	}
	printv(v1, n + 1);
	cout << v1[n] << endl;
}

int main98() {
	vector<string> v1 = { "hello", "gooelg", "selsel", "wqeqweqw" };
	printv(v1,0);
	while (1) {}
	return 0;
}
