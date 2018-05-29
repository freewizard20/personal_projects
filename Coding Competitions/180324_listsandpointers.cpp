#include "stdafx.h"
#include <iostream>
#include <list>
#include <vector>

using namespace std;

// 값은 뭔가요? >> int
// 중복 가능한가요? >> yes
// 순서를 보존해야 하나요? >> yes
// 값 범위는 상관 없다.
// 버퍼 사용 가능한가요? >> no ok ok no

// 처음으로 나타난 x를 포인터로 가리킨다.
// 다시 처음부터 순회하면서 
// x 왼쪽에서 값이 작으면 그대로 두고, 왼쪽에서 값이 같으면 x 바로 왼쪽에 붙이고 범위 포인터 --, 왼쪽에서 값이 크면 바로 오른쪽에 붙인다
// x 오른쪽에서 값이 작으면 범위 포인터 위 하나에 넣어준다. 값이 같으면 오른쪽에 붙이고 범위 포인터 ++, 값이 크면 그대로 둔다.
// x포인터를 범위 포인터로 두개를 두던가, 아니면 또 방법이 처음에 x를 전부 찾아서 맨 뒤로 보낸다. 결국에는 범위 포인터가 또 필요해지네.
// 그러면 그냥 범위 포인터를 쓰는걸로 하자.

void splitx2(list<int> &data, int x) {
	// empty data to classify and insert
	list<int> tmp[3];
	while (data.size() != 0){
		if (*data.begin() == x) {
			tmp[1].push_back(x);
		}
		else if (*data.begin() > x) {
			tmp[2].push_back(*data.begin());
		}
		else {
			tmp[0].push_back(*data.begin());
		}
		data.erase(data.begin());
	}
	//insert classified data sequentially
	for (int i = 0; i < 3; i++) {
		for (list<int>::iterator it = tmp[i].begin(); it != tmp[i].end();it++) {
			data.push_back(*it);
		}
	}
}

void splitxv(vector<int> & data, int x) {
	vector<int> tmp[3];
	while (data.size() != 0) {
		if (data.at(0) == x) {
			tmp[1].push_back(x);
		}
		else if (data.at(0) > x) {
			tmp[2].push_back(data.at(0));
		}
		else {
			tmp[0].push_back(data.at(0));
		}
		data.erase(data.begin());
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < tmp[i].size(); j++) {
			data.push_back(tmp[i].at(j));
		}
	}
}

void test(vector<int> & data) {
	data.erase(data.begin());
}

void splitx(list<int> &data, int x) {
	list<int>::iterator low, high, it, tmp;	
	for (low = data.begin(); low != data.end(); low++) {
		if (*low == x) {
			high = low;
			break;
		}
	}
	if (low == data.end()) {
		return;
	}
	it = data.begin();
	int count = 0;
	while (it != low) {
		if (*it < x) {
			it++;
		}
		else if (*it == x) {
			data.insert(low--,x);
			data.erase(it--);
			it++;
		}
		else {
			tmp = high;
			advance(tmp, 1 + count);
			data.insert(tmp, *it);
			//tmp = it;
			//tmp++;
			//data.erase(it);
			//it = tmp;
			if (it == data.begin()) {
				data.erase(data.begin()); it = data.begin();
			}
			else { data.erase(it--); }
			it++;
			count++;
		}
	}
	it = high;
	it++;
	while (it != data.end()) {
		if (*it > x) {
			it++;
		}
		else if (*it == x) {
			data.insert(low, x);
			if (low != data.begin()) low--;
			tmp = it;
			tmp++;
			data.erase(it);
			it = tmp;
		}
		else {
			data.insert(low, *it);
			tmp = it;
			tmp++;
			data.erase(it);
			it = tmp;
		}
	}
}

int main() {
	list<int> sam;
	sam.push_back(7);
	sam.push_back(1);
	sam.push_back(8);
	sam.push_back(4);
	sam.push_back(4);
	sam.push_back(4);
	sam.push_back(7);
	sam.push_back(6);
	sam.push_back(2);
	sam.push_back(5);
	sam.push_back(3);
	splitx2(sam, 4);
	//test(sam);
	for (list<int>::iterator i = sam.begin(); i != sam.end(); i++) {
		cout << *i << " ";
	}
	cout << endl;
	while (1) {}
	return 0;
}

int main2() {
	list<int> sam;
	for (int i = 0; i < 10; i++) {
		sam.push_back(i);
	}
	list<int>::iterator it = sam.begin();
	advance(it, 3);
	for (list<int>::iterator s = sam.begin(); s != sam.end(); s++) {
		cout << *s << " ";
	}
	cout << endl;
	sam.insert(it++, 49);
	for (list<int>::iterator s = sam.begin(); s != sam.end(); s++) {
		cout << *s << " ";
	}
	cout << endl;
	cout << *it << endl;
	sam.insert(++it, 50);
	for (list<int>::iterator s = sam.begin(); s != sam.end(); s++) {
		cout << *s << " ";
	}
	cout << endl;
	cout << *it << endl;
	sam.erase(it--);
	for (list<int>::iterator s = sam.begin(); s != sam.end(); s++) {
		cout << *s << " ";
	}
	cout << endl;
	cout << *it << endl;
	while (1) { }
	return 0;
}

char returnk(list<char> *data, int k) {
	if (k >= (*data).size()){
		return NULL;
	}
	else {
		list<char>::iterator it = data->end();
		advance(it, -k - 1);
		return *it;
	}
}

int main1() {
	list<char> data;
	for (int i = 0; i < 10; i++) {
		data.push_back(i * 2 + 'a');
		cout << (char)(i * 2 + 'a') << " ";
	}
	cout << endl;
	cout << returnk(&data, 3) << endl;
	while (1) {}
	return 0;
}
