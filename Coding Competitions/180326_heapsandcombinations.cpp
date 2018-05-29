#include "stdafx.h"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <functional>
#include <unordered_set>
using namespace std;

pair<int, int> test() {y
	multimap<int, int> t;
	t.insert(pair<int, int>(2, 3));
	return pair<int, int>(100, 200);
}

int main() {
	pair<int, int> t = test();
	cout << t.first << " " << t.second << endl;
	while(1){}
	return 0;
}

int main8() {
	multimap<int, int> t;
	t.size();
	unordered_set<int> test;
	test.insert(5);
	test.insert(4);
	test.insert(3);
	test.insert(2);
	test.insert(1);
	//unordered_set<int>::iterator it2 = test.begin() + 4; 덧셈 안됨.
	for (unordered_set<int>::iterator it = test.begin(); it != test.end(); it++) {
		cout << *it << endl;
	}
	unordered_multiset<int> sma;
	sma.insert(1);
	sma.insert(2);
	sma.insert(5);
	sma.insert(5);
	sma.insert(1);
	for (unordered_multiset<int>::iterator it = sma.begin(); it != sma.end(); it++) {
		cout << *it << endl;
	}
	while (1) {}
	return 0;
}

int main7() {
	unordered_multimap<int, int> yeah;
	multimap<int, int> test3;
	// test3[1] = 2; 불가능
	//test3.insert(pair<int, int>(1, 2));
	test3.insert(pair<int, int>(1, 3));
	test3.insert(pair<int, int>(1, 4));
	test3.insert(pair<int, int>(1, 5));
	test3.insert(pair<int, int>(1, 2));
	cout << (*test3.find(1)).second << endl;
	cout << (*test3.begin()).second << endl;
	unordered_map<int, int> test2;
	test2[1] = 1;
	test2[2] = 2;
	test2[3] = 3;
	cout << test2[2] << endl;
	map<int, int> test;
	test[1] = 2;
	test[2] = 3;
	test[3] = 4;
	cout << test[2] << endl;
	while (1) {}
	return 0;
}


void func(vector<int> &data) {
	data.push_back(1);
}

int main6() {
	vector<int>t = { 1,2,3,4,5 };
	func(t);
	for (int i : t) {
		cout << i << endl;
	}
	while (1){}
	return 0;
}

void allsubsets(vector<int> *data) {
	for (int i = 0; i < pow(2, data->size()); i++) {
		int tmp = i;
		int k = 0;
		while (tmp != 0) {
			if (tmp % 2 != 0) {
				cout << data->at(k) <<", ";
			}
			k++;
			tmp /= 2;
		}
		cout << endl;
	}
}

int main5() {
	vector<int> data = { 6,4,7,1,5 };
	allsubsets(&data);
	while (1) { }
	return 0;
}

int main4() {
	priority_queue<pair<int, int>> z;
	z.push(pair<int,int>(3, 1));
	z.push(pair<int, int>(1, 2));
	z.push(pair<int, int>(1, 19));
	z.push(pair<int, int>(1, 12));
	z.push(pair<int, int>(1, 39));
	z.push(pair<int, int>(1, 1));
	z.push(pair<int, int>(2, 4));
	z.push(pair<int, int>(1, 4));
	while (z.size() != 0) {
		cout << z.top().first << " " << z.top().second << endl;
		z.pop();
	}
	while (1) {}
	/*priority_queue<int> wtf;
	wtf.push(1);
	wtf.push(9);
	wtf.push(8);
	wtf.push(6);
	while (1) {}*/
	vector<int> v2 = { 5,4,3,6,7,6,5,4,65,76,12 };
	make_heap(v2.begin(), v2.end());
	v2[0] = 32;
	//list <int> l2 = { 5,4,3,6,7,6,5,4,65,76,12 };
	//make_heap(l2.begin(), l2.end());
	//cout << l2.front() << endl;
	while (1) {}
	vector<int> v1 = { 5,4,3,6,7,6,5,4,65,76,12 };
	make_heap(v1.begin(), v1.end());
	cout << v1.front() << endl;
	v1.push_back(99);
	push_heap(v1.begin(), v1.end());
	cout << v1[0] << endl;
	for (int i : v1) {
		cout << i << " ";
	}
	cout << endl;
	pop_heap(v1.begin(), v1.end());
	pop_heap(v1.begin(), v1.end()-1);
	pop_heap(v1.begin(), v1.end()-2);
	cout << v1.front() << endl;
	for (int i : v1) {
		cout << i << " ";
	}
	cout << endl;
	while (1) {}
	map<int, int> t;
	t[1] = 2;
	t.insert(pair<int, int>(2, 3));
	t.insert(map<int, int>::value_type(4, 5));
	
	vector<int> v;
	v.push_back(3);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v[1] = 23;
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
	

	priority_queue<pair<double, int>,vector<pair<double,int>>,greater<pair<double,int>>> given;
	priority_queue<int, vector<int>, greater<int>>q2;
	// priority queue는 
	given.push(pair<double, int>(1.34, 3));
	given.push(pair<double, int>(4.43, 2));
	given.push(pair<double, int>(0.93, 1));
	cout << given.top().first <<" " << given.top().second << endl;
	while (1) {}
	multiset <int> tmp;
	tmp.insert(3);
	tmp.insert(2);
	tmp.insert(1);
	tmp.insert(2);
	tmp.insert(2);
	for (multiset<int>::iterator it = tmp.begin(); it != tmp.end(); it++) {
		cout << *it << endl;
	}
	while(1){}
	multimap<int, int> test;
	test.insert(pair<int, int>(3, 4));
	test.insert(pair<int, int>(2, 4));
	test.insert(pair<int, int>(1, 4));
	test.insert(pair<int, int>(1, 1));
	test.insert(pair<int, int>(1, 2));
	// 두번째 인자로는 정렬안함
	for (multimap<int, int>::iterator it = test.begin(); it != test.end(); it++) {
		cout << (*it).first << " " << (*it).second << endl;
	}
	while(1){ }
	map<int, int> namemap;
	namemap.insert(pair<int, int>(2, 3));
	namemap.insert(map<int, int>::value_type(4, 3));
	namemap[5] = 3;
	namemap[5] = 2; // 후자로 바꿔버리네.
	for (map<int, int>::iterator it = namemap.begin(); it != namemap.end(); it++) {
		cout << (*it).first << " " << it->second << endl;
	}
	while (1) {}
	return 0;
}


int main3() {
	vector<pair<int,int>> sam;
	for (int i = 0; i < 10; i++) {
		pair<int, int> tmp;
		tmp.first = 100 - i * 3;
		tmp.second = 12 * i;
		sam.push_back(tmp);
	}
	for (pair<int, int> i : sam) {
		cout << i.first << " " << i.second << endl;
	}
	sort(sam.begin(), sam.end());
	for (pair<int,int> i : sam) {
		cout << i.first << " " << i.second << endl;
	}
	while (1) {}
	return 0;
}


int main2() {
	unordered_map<int, string> test;
	test.insert(unordered_map<int, string>::value_type(1, "ddas1"));
	test.insert(unordered_map<int, string>::value_type(2, "ddas2"));
	test.insert(unordered_map<int, string>::value_type(3, "ddas3"));
	test.insert(unordered_map<int, string>::value_type(4, "ddas4"));
	test.insert(unordered_map<int, string>::value_type(5, "ddas5"));
	string s = test.find(3)->second;
	string s2 = "hello world";
	cout << s << endl;
	while (1) {}
	return 0;
}




// n이 주어졌을 때, n쌍의 괄호로 만들 수 있는 모든 합당한 조합
// )( x >> ()
// "출력" >> 자료구조에 저장할 필요 x
// n = 0  >> 0
// n = 1 >> )(, () 2 가능 : 1
// n = 2 >> 0011 >> 0101 1001 1010 1100
// x0x0x >> 11 12 13 22 23 33
// 그 중에서 "옳은" 괄호는 0 > ( 1 > ) (()) ()() )()(
// 1100 0101 1010
// 갯수가 동일할 것은 보장되므로, 무조건 (이 )보다 같거나 많아야 한다.
// 알고리즘
// 모든 조합을 생성한다.
// 맞는 괄호를 찾는다.
// 맞으면 출력한다.
// 11 12 13 22 23 33 >> 숫자 출력 >> "맞는 괄호"
// 11 >> )), (( , 33 >> (())
// 굳이 이거를 괄호로 변형 >> 괄호를 검사
// 바로 11 에서 정답을 알 수 있나?
// 구현이 매우 간단해집니다.
// 11 >> 1 있으면 무조건 안된다
// 2 한개 이상 있으면 안된다
// 3 은 두개 이상 있으면 안된다.
// 맞으면 괄호로 출력..
// OK!!

// 알고리즘
// n 인 경우 n+1까지 n개를 컴비네이션으로 구한다.
// 값을 분석해서 맞는 괄호인지 확인한다.
// 맞으면 괄호로 변형해서 출력한다.
// 00 01 02 11 12 22

void brackets(int n,vector<int> buffer) {
	if (buffer.size() == n) {
		
		// count and check bracket rule
		int * tmp = new int[n+1];
		memset(tmp, 0, (n+1) * sizeof(int));
		for (int i = 0; i < buffer.size(); i++) {
			tmp[buffer.at(i)]++;
			if (i >= buffer.at(i)) {
				return;
			}
		}
		//print brackets
		for (int i = 0; i < n+1; i++) {
			for (int j = 0; j < tmp[i]; j++) {
				cout << ')';
			}
			if(i!=n)
				cout << '(';
		}
		cout << endl;
		//delete[] tmp;
		return;
	}
	//generate combinations
	int min;
	if (buffer.size() == 0) {
		min = 0;
	}
	else {
		min = buffer.at(buffer.size() - 1);
	}
	for (int i = min ; i < n + 1; i++) {
		buffer.push_back(i);
		brackets(n, buffer);
		buffer.erase(buffer.end() - 1);
	}
}
// time complexity : O(n*2nCn)
// space compelxity : O(n)


int main1() {
	vector<int> test;
	brackets(4, test);
	while(1){}
	return 0;
}
