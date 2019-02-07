#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <stack>
#include <bitset>
#include <iomanip>

using namespace std;

struct trienode {
	trienode * next[26];
	bool isend;
	trienode() : isend(false) {
		memset(next, 0, sizeof(next));
	}
	~trienode() {
		for (int i = 0; i < 26; i++) {
			if (next[i] != NULL) delete next[i];
		}
	}
	void insert(string s, int curr) {
		if (curr == s.length() - 1) {
			isend = true;
			return;
		}
		if (next[s[curr] - 'a'] != NULL) {
			next[s[curr] - 'a']->insert(s, curr + 1);
		}
		else {
			next[s[curr] - 'a'] = new trienode();
			next[s[curr] - 'a']->insert(s, curr + 1);
		}
	}
	trienode * find(string s, int curr) {
		if (curr = s.length() - 1) {
			return this;
		}
		else {
			if (next[s[curr] - 'a'] == NULL) return NULL;
			else return next[s[curr] - 'a']->find(s, curr + 1);
		}
	}
};

int main() {
	trienode sam;
	sam.insert("hello", 0);
	sam.insert("helly", 0);
	sam.insert("kely", 0);
	if (sam.find("kely", 0) != NULL) cout << " found " << endl;
	while(1){}
	return 0;
}

template<typename K, typename V>
class HashNode {
private:
	HashNode * next;
	K key;
	V value;
public :
	HashNode(K k, V v) : key(k), value(v), next(NULL){}
	K getkey() { return key;  }
	V getvalue() { return value;  }
	HashNode * getnext() { return next; }
	void setvalue(V v) { value = v; }
	void setnext(HashNode * n) { next = n; }
	void removenext() { next = next->getnext(); }
};

template <typename K, typename V>
class myhashtable {
private:
	HashNode<K,V> ** table;
	int tablesize;
	int hash(K key) {
		return reinterpret_cast<int>(key) % tablesize;
	}
public:
	myhashtable(int size) : tablesize(size) {
		table = new HashNode<K, V> * [tablesize];
		for (int i = 0; i < tablesize; i++) {
			table[i] = NULL;
		}
	}
	void put(K key, V value) {
		if (table[hash(key)] == NULL) {
			table[hash(key)] = new HashNode<K,V>(key, value);
		}
		else {
			HashNode<K, V> *runner = table[hash(key)];
			while (runner->getnext() != NULL) {
				if (runner->getvalue() == value) return;
			}
			runner->setnext(new HashNode<K, V>(ket, value));
		}
	}
	HashNode<K, V> * get(K key, V value) {
		HashNode<K, V> * runner = table[hash(key)];
		while (runner != NULL) {
			if (runner->getvalue() == value) return runner;
		}
		return NULL;
	}
	void remove(K key, V value) {
		HashNode<K, V> * runner = table[hash(key)]->getnext();
		HashNode<K, V> * prev = table[hash(key)];
		while(runner!=NULL){}
	}
};

int ai88() {
	vector<int> * sam = NULL;
	vector<int> * ha;
	ha = sam;
	ha = new vector<int>();
	ha->push_back(32);
	cout << sam->at(0) << endl;
	while(1){}
	int * a;
	cout << a << endl;
	while(1){}
	int ** arr2 = new int *[13];
	cout << arr2[10] << endl;
	arr2[10] = NULL;
	cout << arr2[10] << endl;
	if (arr2[10] != NULL) cout << "hello world";
	while(1){}
	vector<int> ** arr = new vector<int> *[100];
	arr[13] = new vector<int>();
	arr[13]->push_back(13);
	cout << arr[13]->at(0) << endl;
	while(1){}
	return 0;
}

// do your best

int mai44n() {
	cout << bitset<32>(~1) << endl;
	while(1){}
	long long a = 0b110111;
	cout << a << endl;
	while(1){}
	return 0;
}

// be professional

int findMSB(int n) {
	int m = INT_MIN;
	int count = 0;
	while ((m&n) == 0) {
		count++;
		m=m >> 1;
	}
	return 32 - count;
}

union test {
	double f;
	long long i;
};

int m999ai1n() {
	double fa = 1;
	for (int i = 0; i < 30; i++) {
		fa /= 3;
		cout << setprecision(32) << fa << endl;
	}
	while(1){}
	test sam;
	sam.f = 13.5;
	cout << bitset<64>(sam.i) << endl;
	test sam2;
	sam2.f = -13.5;
	cout << bitset<64>(sam2.i) << endl;
	while(1){}
	cout << bitset<32>(132323) << endl;
	cout << findMSB(132323) << endl;
	while(1){}
	bitset<32> tmp((-1) >> 12);
	cout << tmp << endl;
	while(1){}
	return 0;
}

// know all you can

class myheap {
private:

public:

};

int m333ain() {
	int sam = 3232;
	int tmp = ~sam + 1;
	cout << tmp << endl;
	return 0;
}

int findreps(string A, string B) {
	// base case
	if (A.size() >= B.size()) {
		if (A.find(B) != -1) return 1;
		else return -1;
	}
	else {
		int firstoccr = B.find(A);
		// check front
		if (string(B.begin(), B.begin() + firstoccr) != string(A.begin() + A.size() - firstoccr, A.end())) {
			return -1;
		}
		// count
		int count = 0;
		for (int i = firstoccr, j = 0; i < B.size(); i++, j++) {
			if (B[i] == A[j]) {
				if (j == A.size() - 1) {
					j = -1;
					count++;
				}
			}
			else {
				return -1;
			}
		}
		return count + 2;
	}
	// not expected to reach here
	return -9999;
}

int ma3322in(){
	cout << findreps("abcd", "bcdabcdab");
	while(1){}
	return 0;
}

// --- be the best

string printbinary(int n) {
	stack<char> tmp;
	while (n != 0) {
		tmp.push(n %2+ '0');
		n /=2;
	}
	string ret="";
	//ret.reserve((int)log(n));
	while (tmp.size() != 0) {
		ret.push_back(tmp.top());
		tmp.pop();
	}
	return ret;
}

int m22ain() {
	cout << printbinary(13) << endl;
	cout << (13 ^ 8) << endl;
	while(1){}
	return 0;
}

// decided by what you do NOW

int mai12n() {
	multiset<int> test;
	test.begin();
	vector<int> t;
	//t.front();
	test.insert(3);
	test.insert(4);
	test.erase(test.begin());
	for (auto it = test.begin(); it != test.end(); it++) {
		cout << *it << endl;
	}
	while(1){}
	set<int> se;
	se.insert(1);
	se.insert(2);
	se.insert(3);
	se.insert(5);
	auto it = se.find(2);
	se.erase(it);
	set<int>::iterator it3;
	se.erase(it3);
	for (auto i = se.begin(); i != se.end(); i++) {
		cout << *i << endl;
	}
	while(1){}
	return 0;
}

// be professional

int getnum(int target, int at) {
	return (target % (at * 10) - target % at)/at;
}

void radixsort(vector<int> & data) {
	// start from 1 and escalate until all elements have zero at the digit
	vector < vector<int >> buffer(10, vector<int>());
	int curr = 1;
	while (buffer[0].size() != data.size()) {
		// renew buffer
		buffer = vector<vector<int>>(10, vector<int>());
		curr *= 10;
		// count sort all indexes and append them
		for (int i = 0; i < data.size(); i++) {
			int sam = getnum(data[i], curr / 10);
			//cout << sam << endl;
			buffer[sam].push_back(i);
		}

		// sort data by the values
		vector<int> tmp = data;
		int count = 0;
		for (int i = 0; i < buffer.size(); i++) {
			for (int j = 0; j < buffer[i].size(); j++) {
				data[count] = tmp[buffer[i][j]];
				count++;
			}
		}
	}
}

int m44444ain() {
	vector<int> v1 = { 232,1142,4422,5212,112,3,43,65,999,121213 };
	radixsort(v1);
	for (int x : v1) cout << x << " ";
	cout << endl;
	while(1){}
	return 0;
}

int m999ain() {
	//unordered_map<pair<int, int>, int> map;
	//map.insert(pair<pair<int, int>, int>(pair<int, int>(1, 2), 3));
	//auto it = map.find(pair<int, int>(1, 2));
	//scout << it->second << endl;
	while(1){}
	return 0;
}

int main33() {
	vector<int> v1 = { 3,2,3,3,3,3,4,5,6,7,8 };
	priority_queue<int> q(v1.begin(), v1.end());
	cout << q.top() << endl;
	while(1){}
	return 0;
}

string convert(string s, int numRows) {
	vector<string> tmp(numRows, "");
	for (string s : tmp) {
		s.reserve(s.size() / numRows);
	}
	int curr = 0;
	int direction = 1;
	for (int i = 0; i < s.size(); i++) {
		string z = "" + s.at(i);
		tmp.at(curr).append(z);
		curr += direction;
		if (curr == numRows - 1) direction = -1;
		if (curr == 0) direction = 1;
	}
	string ret = "";
	ret.reserve(s.size());
	for (int i = 0; i < tmp.size(); i++) {
		ret.append(tmp.at(i));
	}
	return ret;
}

int main22() {
	cout << convert("PAYPALISHIRING", 3) << endl;
	while(1){}
	return 0;
}
