#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

vector<vector<int>> findthree(vector<int> * data, int target) {
	sort(data->begin(), data->end());
	vector<vector<int>> ret;
	ret.reserve(data->size());
	// iterate data array from start
	for (int i = 0; i < data->size();) {
		if (i != data->size() - 1 && data->at(i) == data->at(i + 1)) {
			// pass same elements until end
			i++;
		}
		else {
			// last same element at i, pick that and do double sum search from there
			int tofind = target - data->at(i);
			// find array range 0 ~ i-1
			unordered_set<int> s;
			for (int j = 0; j < i; j++) {
				if (s.find(tofind - data->at(j)) != s.end()) {
					// found corresponding element
					// cout << "found" << data->at(i) << endl;
					auto it = s.find(tofind - data->at(j));
					vector<int> tmp = { *it, data->at(j),data->at(i) };
					ret.push_back(tmp);
				}
				else {
					//cout << "notfound" << " " << data->at(i) << " " << data->at(j) << " "<< tofind-data->at(j) << endl;
					s.insert(data->at(j));
				}
			}
			i++;
		}
	}
	return ret;
}

int main() {
	vector<int> data = { -1,0,1,2,-1,-4 };
	vector<vector<int>> tmp = findthree(&data, 0);
	for (int i = 0; i < tmp.size(); i++) {
		cout << "( ";
		for (int j = 0; j < tmp.at(i).size(); j++) {
			cout << tmp.at(i).at(j) << " ";
		}
		cout << " )" << endl;
	}
	while(1){}
	return 0;
}
