#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

using namespace std;

void sortstrings(vector<string> & data) {
	unordered_multimap<string, string> tmp;
	for (int i = 0; i < data.size(); i++) {
		string s = data.at(i);
		sort(begin(s), end(s));
		tmp.insert(pair<string, string>(s, data.at(i)));
	}
	int i = 0;
	for (unordered_multimap<string, string>::iterator it = tmp.begin(); it != tmp.end(); it++, i++) {
		data[i] = (*it).second;
	}
}

// time complexity : 

int main() {
	/*int ar[] = { 1,2,3,4,5,6 };
	vector<int> vt(ar, ar + 4);
	list<int> lt(ar, ar + 4);
	set<int> s1(vt.begin(), vt.end());
	cout << s1.size() << endl;
	while (1) {}
	multiset<int> s;
	//auto zi = s.begin();
	//advance(s, 13);
	s.insert(5);
	s.insert(5);
	s.insert(5);
	s.insert(1);
	s.insert(1);
	s.insert(1);
	s.insert(4);
	s.insert(4);
	s.insert(13);
	s.insert(13);
	s.insert(1919);
	s.insert(1919);
	s.insert(1);
	auto p = s.equal_range(1);
	for (auto it = p.first; it != p.second; it++) {
		cout << *it << endl;
	}
	while (1) {}*/
	/*unordered_multimap<int, int> t;
	t.insert(pair<int, int>(2323, 1));
	t.insert(pair<int, int>(1, 3));
	t.insert(pair<int, int>(1, 1));
	t.insert(pair<int, int>(2, 2));
	t.insert(pair<int, int>(3, 3));
	t.insert(pair<int, int>(1, 3));
	t.insert(pair<int, int>(2, 4));
	t.insert(pair<int, int>(1, 5));
	t.insert(pair<int, int>(2, 6));
	t.insert(pair<int, int>(1, 7));
	t.insert(pair<int, int>(2, 8));
	//auto same = t.equal_range(2);
	//for (auto it = same.first; it != same.second; it++) {
	//	cout << "matching 2 : " << (*it).first << " " << (*it).second << endl;
	//}
	for (auto it = t.begin(); it != t.end(); it++) {
		cout << (*it).first << " " << (*it).second << endl;
	}
	while (1) {}
	*/
	vector<string> v1 = { "asdasd","ddwdwd","gwegweg","aabbc","cbbaa","gwerewgew","bbcaa","ewqeqweqwe" };
	sortstrings(v1);
	for (string s : v1) {
		cout << s << endl;
	}
	while (1) {};
	return 0;
}

/*
int main1() {
	cout << " hello world";
	vector<int> t = { 5,4,3,2,8,7,6,5,4 };
	cout << t.size();
	sort(t.begin(), t.end());
	cout << t.size();
	vector<int> sam(29);
	cout << endl;
	cout << sam.size() << endl;
	sam.push_back(23);
	cout << sam.size() << endl;
	while (1) {}
	return 0;
}

void sortstrings3(vector<string> & data) {
	multimap<string, string> tmp;
	for (int i = 0; i < data.size(); i++) {
		string s = data.at(i);
		sort(begin(s), end(s));
		tmp.insert(pair<string, string>(s, data.at(i)));
	}
	int i=0;
	for (multimap<string, string>::iterator it = tmp.begin(); it != tmp.end(); i++, it++) {
		data[i] = (*it).second;
	}
}


bool comparitor(string s1, string s2) {
	sort(begin(s1), end(s1));
	sort(begin(s2), end(s2));
	return s1 > s2;
}

void sortstrings(vector<string> & data) {
	sort(data.begin(),data.end(), comparitor);
}



void sortstrings2(vector<string> &data) {
	vector<pair<string,string>> *tmp = new vector<pair<string,string>>();
	for (int i = 0; i < data.size(); i++) {
		string s = data.at(i);
		sort(begin(s), end(s));
		tmp->push_back(pair<string, string>(s, data.at(i)));
	}
	sort(tmp->begin(), tmp->end());
	for (int i = 0; i < tmp->size(); i++) {
		data[i] = tmp->at(i).second;
	}
}


int main9() {
	vector<string> v1 = { "asdasd","ddwdwd","gwegweg","aabbc","cbbaa","gwerewgew","bbcaa","ewqeqweqwe" };
	sortstrings3(v1);
	for (string s : v1) {
		cout << s << endl;
	}
	while (1) {};
	return 0;
}

int main22() {
	int ch = 0;
	int z = 1;
	char c = 'a';
	for (int i = 0; c < 'z'; c++, i++, z--, ch = ch + 5) {
		cout << c << endl;
	}
}

int main0() {
	vector<pair<int, int>> v;
	vector<int> v2(13);
	v2[1] = 3;
	cout << v2[12] << endl;
	while (1) {}
	return 0;
}

/*bool comparitor(int a, int b) {
	return (a > b) ;
}

int main() {
	int arr[] = { 4,3,5,2,10,8,4,9 };
	// 마지막 포인터를 포함하지 않는 바로 앞까지라서 아래처럼 해야됨.
	//sort(arr,arr+(sizeof(arr)/sizeof(int)));
	sort(begin(arr), end(arr),comparitor);
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	while (1) {}
	return 0;
}

/*
struct node {
	int data;
	node *next;
};

class list {
private:
	node * head, *tail;
	int * a;
public:
	list() {
		head = NULL;
		tail = NULL;
		int b = 23;
		a = &b;
	}
	void createnode(int value);
	void print();
};

void list::createnode(int value) {
	node *temp = new node;
	temp->data = value;
	temp->next = NULL;
	if (head == NULL) {
		head = temp;
		tail = temp;
		temp = NULL;
	}
	else {
		tail->next = temp;
		tail = temp;
	}
}

void list::print() {
	cout << a << " " << *a << endl;
	node *temp = new node;
	temp = head;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
}

int main() {
	list test;
	test.createnode(1);
	test.createnode(2);
	test.createnode(3);
	test.print();
	while (1) {}
	return 0;
}
/*struct node {
	int data;
	node * prev;
	node * next;
};

class list {
public:
	node * head;
	node * tail;
	list();
	void insert(int data);
	void remove();
	void print();
	void fuck();
};

list::list(){
	head = NULL;
	tail = NULL;
}

void list::insert(int data) {
	if (head == NULL) {
		node y = { data,NULL,NULL };
		head = &y;
		tail = &y;
		cout << "after insert1 " << head->data << " " << tail->data << endl;
		return;
	}
	cout << "after insert2 " << head->data << " " << tail->data << endl;
	node x = { data,tail, NULL };
	tail->next = &x;
	tail = tail->next;
	cout << "after insert2 " << head->data << " " << tail->data << endl;
	return;
}

void list::remove() {
	if (head == NULL) {
		return;
	}
	else if (head == tail) {
		head = NULL;
		tail = NULL;
		return;
	}
	tail = tail->prev;
	tail->next = NULL;
}

void list::print() {
	cout << "data f p" << head->data << endl;
	node * tmp = this->head;
	cout << "data from print " << tmp->data << endl;
	//while (tmp != NULL) {
	//	cout << tmp->data << endl;
	//	tmp = tmp->next;
	//}
}

void list::fuck() {
	cout << "fuck " << head->data << endl;
}

class whathappened {
public:
	int * a;
	whathappened();
	void print();
};

whathappened::whathappened() {
	int b = 23;
	a = &b;
}

void whathappened::print() {
	cout << a << " " << *a << endl;
}

int main1() {
	whathappened sam;
	cout << sam.a << " " << *sam.a <<  endl;
	sam.print();
	cout << sam.a << " " << *sam.a << endl;
	while (1) {}
	list test;
	test.insert(1);
	//test.fuck();
	cout << test.head->data << " what " << test.tail->data << endl;
	test.fuck();
	test.print();
	test.insert(2);
	cout << test.head->data << " what " << test.tail->data << endl;
	test.insert(3);
	cout << test.head->data << " what " << test.tail->data << endl;
	//test.remove();
	//test.print();
	while (1) {}
	return 0;
}
*/
