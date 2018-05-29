#include "stdafx.h"
#include <iostream>
#include <map>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <queue>
#include <functional>
#include <cmath>

using namespace std;

void pushnew(priority_queue<int> * mins, priority_queue<int,vector<int>,greater<int>> * maxs, int x) {
	if (maxs->size() == 0 && mins->size() == 0) {
		mins->push(x);
		return;
	}
	else {
		if (x > mins->top()) {
			maxs->push(x);
		}
		else {
			mins->push(x);
		}
		// rebalance if unbalanced to find mid
		if ((int)abs((int)(mins->size() - maxs->size())) > 1) {
			if (mins->size() > maxs->size()) {
				maxs->push(mins->top());
				mins->pop();
			}
			else {
				mins->push(maxs->top());
				maxs->pop();
			}
		}
	}
}

// 자료구조를 업데이트 하면서 가는거면 이런식으로 그냥 인자 포인터로 정의해 버리자.
int findmid(priority_queue<int> * mins, priority_queue<int,vector<int>,greater<int>> * maxs) {
	// return -1 if nothing in line
	if (mins->size() == 0 && maxs->size() == 0) {
		return -1;
	}
	// when heaps are unbalanced by one
	if (mins->size() - maxs->size() != 0) {
		return mins->size() > maxs->size() ? mins->top() : maxs->top();
	}
	else {
	// when equal numbers
		return (mins->top() + maxs->top()) / 2;
	}
}


int main() {
	priority_queue<int> mins;
	priority_queue<int, vector<int>, greater<int>> maxs;
	for (int i = 0; i < 20; i++) {
		pushnew(&mins, &maxs, i * 3);
		cout << findmid(&mins, &maxs) << endl;
	}
	while(1){}
	return 0;
}
//---

int main888() {
	priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> tmp;
	tmp.push(pair<int, int>(1, 4));
	tmp.push(pair<int, int>(1, 3));
	tmp.push(pair<int, int>(1, 2));
	tmp.push(pair<int, int>(1, 1));
	tmp.push(pair<int, int>(2, 2));
	tmp.push(pair<int, int>(3, 2));
	tmp.push(pair<int, int>(4, 2));
	tmp.push(pair<int, int>(5, 2));
	while (tmp.size() != 0) {
		cout << tmp.top().first << " " << tmp.top().second << endl;
		tmp.pop();
	}
	while(1){}
	queue<int> sam;
	for (int i = 0; i < 10; i++) {
		sam.push(i);
	}
	int t = sam.front();
	t--;
	sam.front() -= 10;
	cout << sam.front() << endl;
	// 특이하게 int & 형태의 값을 리턴해서 이 값대로 바로 변경하면 값이 바뀐다.
	cout << sam.front() << endl;
	for (int i = 0; i < 5; i++) {
		sam.pop();
	}
	while(1){}
	return 0;
}

// 음수를 포함하는 정수형인가요? >> 네
// 중복이 있나요? >> 네
// 정렬되어 있나요? >> 아니요
// 숫자가 홀수인 경우 중간의 값인데,
// 숫자가 짝수인 경우 중간 두개 중에 어느건가요? >> 그 둘의 평균으로 합시다
// 처음부터 하나씩 주어진다고 할까요? >> 맘대로

// 자료구조를 유지하면서 트래킹 하는 경우 클래스를 만들어서 멤버 함수를 써야 한다.
// 아니면 메인 함수에 자료구조를 정의해 놓고 따다 쓰던가..

// 두개의 힙을 만들어서 min heap와 max heap을 사용한다.

int main999() {
	pair<int, int> p1(2, 3);
	pair<int, int> p2(2, 4);
	if (p1 == p2) {
		cout << 0;
	}
	else if (p1 > p2) {
		cout << 1;
	}
	else {
		cout << -1; // 이쪽으로 2차까지 대소비교 한다.
	}
	cout << endl;
	vector<pair<int, int>> v1;
	v1.push_back(pair<int, int>(1, 4));
	v1.push_back(pair<int, int>(1, 3));
	v1.push_back(pair<int, int>(1, 2));
	v1.push_back(pair<int, int>(1, 1));
	v1.push_back(pair<int, int>(2, 2));
	v1.push_back(pair<int, int>(3, 2));
	v1.push_back(pair<int, int>(4, 2));
	v1.push_back(pair<int, int>(5, 2));
	sort(v1.begin(), v1.end());
	for (auto i : v1) {
		cout << i.first << " " << i.second << endl;
	}
	cout << "---" << endl;
	// 2차까지 해서 정렬해 준다.
	multimap<int, int> tmp;
	tmp.insert(pair<int, int>(1, 4));
	tmp.insert(pair<int, int>(1, 3));
	tmp.insert(pair<int, int>(1, 2));
	tmp.insert(pair<int, int>(1, 1));
	tmp.insert(pair<int, int>(2, 4));
	tmp.insert(pair<int, int>(3, 4));
	tmp.insert(pair<int, int>(4, 4));
	tmp.insert(pair<int, int>(5, 4));
	for (auto it = tmp.begin(); it != tmp.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}
	while(1){}
	return 0;
}



//---

void mergesortrec(vector<int> * data, int low, int high) {
	// base case : if one left, return without any work
	if (low == high) {
		return;
	}
	// starting from length 2 ; split with 0 and 1 , 
	int mid = (low + high) / 2;
	mergesortrec(data, low, mid);
	mergesortrec(data, mid + 1, high);
	vector<int> buf;
	buf.reserve(high - low + 1);
	int highit = mid + 1;
	int lowit = low;
	for (int i = low; i <= high; i++) {
		if (lowit <= mid && highit <= high) {
			if (data->at(highit) > data->at(lowit)) {
				buf.push_back(data->at(lowit));
				lowit++;
			}
			else {
				buf.push_back(data->at(highit));
				highit++;
			}
			
		}else if (highit == high + 1) {
			buf.push_back(data->at(lowit));
			lowit++;
		}else if (lowit == mid + 1) {
			buf.push_back(data->at(highit));
			highit++;
		}
	}
	for (int i = low; i <= high; i++) {
		data->at(i) = buf.at(i - low);
	}
}

void mergesort(vector<int> * data) {
	mergesortrec(data, 0, data->size() - 1);
}

int main77() {
	vector<int> v1 = { 5,3,1,9,10,4,2,8,8,7,6 };
	mergesort(&v1);
	for (int i : v1) {
		cout << i << " ";
	}
	while(1){}
	return 0;
}

//---

void quicksortrec(vector<int> * v1, int low, int high) {
	if (low == high) {
		return;
	}
	vector<int> buf;
	buf.reserve(high - low);
	int pivot = v1->at(high - 1);
	buf.push_back(pivot);
	int count = 0;
	for (int i = low; i < high - 1; i++) {
		if (pivot < v1->at(i)) {
			buf.push_back(v1->at(i));
		}
		else {
			buf.insert(buf.begin(), v1->at(i));
			count++;
		}
	}
	for (int i = low; i < high; i++) {
		v1->at(i) = buf.at(i - low);
	}
	quicksortrec(v1, low, low+count);
	quicksortrec(v1, low+count + 1, high);
}

void quicksort(vector<int> * v1) {
	return quicksortrec(v1,0,v1->size());
}

int main1212() {
	vector<int> v1 = { 3,1,4,10,3,13,9,8,7 };
	quicksort(&v1);
	for (int i : v1) {
		cout << i << " ";
	}
	while(1){}
	return 0;
}

//

int main445() {
	string s = "helloworld";
	string s2(s.begin(), s.begin() + 4);
	cout << s2 << endl;
	sort(s.begin(), s.end());
	cout << s << endl;
	while(1){}
	return 0;
}

//-----------

pair<int, int> matermindgame(string ans, string given) {
	int hit = 0;
	int phit = 0;
	// iterate through all elements to count hits
	for (int i = 0; i < given.size(); i++) {
		if (given.at(i) == ans.at(i)) {
			hit++;
			continue;
		}
		for (int j = 0; j < ans.size(); j++) {
			if (given.at(i) == ans.at(j)) {
				phit++;
				break;
			}
		}
	}
	return pair<int, int>(hit, phit);
}

pair<int, int> mastermindgamefaster(string ans, string given) {
	// fill hash table
	unordered_set<int> buffer;
	for (int i = 0; i < ans.size(); i++) {
		buffer.insert(ans.at(i));
	}
	// if same, hit, if hash table has value, phit
	int hit = 0;
	int phit = 0;
	for (int i = 0; i < given.size(); i++) {
		if (given.at(i) == ans.at(i)) {
			hit++;
			continue;
		}
		if (buffer.find(given.at(i)) != buffer.end()) {
			phit++;
		}
	}
	return pair<int, int>(hit, phit);
}

int findrank(map<int,int> *data, int n) {
	auto it = data->find(n);
	if (it!= data->end()) {
		return it->second;
	}
	else {
		return -1;
	}
}

void push_new(map<int, int> *data, int n) {
	for (auto it = data->begin(); it != data->lower_bound(n); it++) {
		it->second++;
	}
	if (data->find(n) == data->end()) {
		data->insert(pair<int, int>(n, 1));
	}
}

int main29() {
	// 값을 새로 넣는 함수
	// 특정 key의 값을 찾는 함수
	map<int, int> data;
	push_new(&data, 3);
	push_new(&data, 4);
	push_new(&data, 5);
	cout << findrank(&data, 4) << endl;
	while (1) {}
	return 0;
}
