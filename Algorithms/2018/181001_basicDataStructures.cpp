#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>


using namespace std;

int main() {
	
	/*
	
	basic arrays
	
	*/
	
	int arr[10];
	int arr3[10][3];
	int * arr2 = new int[10];

	// 2차원 배열 선언
	int ** arr4 = new int *[10];
	for (int i = 0; i < 10; i++) {
		arr4[i] = new int[15];
	}

	/*
	
	vectors
	
	*/

	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	
	//reverse(v.begin(), v.end());
	v.insert(v.begin() + 1, 4);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;


	/*
	
	basic QUEUES
	
	*/

	cout << "queues" << endl;

	queue<int> q;
	q.push(1);
	q.push(2);
	while (q.size() != 0) {
		cout << q.front();
		q.pop();
	}

	/*
	
	basic STACKS

	*/

	cout << "stacks" << endl;

	stack<int> s;
	s.push(1);
	s.push(2);
	while (s.size() != 0) {
		cout << s.top() << endl;
		s.pop();
	}

	/*
	
	priority queues
	
	*/

	cout << "max heap" << endl;
	priority_queue<int> pq;
	pq.push(32);
	pq.push(12);
	while (pq.size() != 0) {
		cout << pq.top() << " ";
		pq.pop();
	}

	cout << "min heap" << endl;
	priority_queue<int, vector<int>, greater<int>> mpq;
	mpq.push(32);
	mpq.push(12);
	while (mpq.size() != 0) {
		cout << mpq.top() << endl;
		mpq.pop();
	}

	/*
	
	maps

	*/

	unordered_map<int, int> map;
	map.insert(pair<int,int>(23,23));
	auto it = map.find(23);
	if (it != map.end()) {
		cout << it->first << " " << it->second << endl;
		map.erase(23);
	}

	/*
	
	sets
	
	*/

	unordered_set<int> set;
	set.insert(10);
	auto it2 = set.find(10);
	if (it2 != set.end()) {
		cout << *it2 << endl;
	}


	while(1){}
}

/*
int main2() {
	//char str[100];
	//scanf("%[^'\n']s", str);
	//printf("%s\n", str);
	int num,i;
	scanf("%d", &num);
	int * arr;
	arr = (int *)malloc(sizeof(int) * num);
	for (i = 0; i < num; i++) {
		scanf("%d", &arr[i]);
	}
	free(arr);
	while(1){}
}*/

