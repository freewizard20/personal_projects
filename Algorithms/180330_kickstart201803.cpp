#include "stdafx.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <fstream>
#include <iomanip>
#include <string>
#include <unordered_map>
#include <vector>
#include <set>

using namespace std;

int main22222() {
	// 클래스 해시 불가. string만 특별히 가능.
	//unordered_map<vector<int>, int> zest;
	//zest.insert(pair<vector<int>, int>(vector<int>(), 3));
	//while(1){}
	// classes comparable
	vector<int> v1 = { 1,2,3,4,5 };
	vector<int> v2 = { 1,2,3,4,5 };
	if (v1 == v2) cout << "ww" << endl;
	while(1){}
	// hash table은 pair을 key로 사용할 수 없다.
	/*unordered_map<pair<int, int>, string> test;
	test.insert(pair<pair<int, int>, string>(pair<int, int>(1, 1), "hello"));
	test.insert(pair<pair<int, int>, string>(pair<int, int>(1, 1), "bye"));
	test.insert(pair<pair<int, int>, string>(pair<int, int>(1, 1), "kiosk"));
	test.insert(pair<pair<int, int>, string>(pair<int, int>(1, 2), "hello1"));
	test.insert(pair<pair<int, int>, string>(pair<int, int>(1, 3), "hello2"));
	test.insert(pair<pair<int, int>, string>(pair<int, int>(1, 4), "hello3"));
	auto pp = test.equal_range(pair<int, int>(1, 1));
	for (auto it = pp.first; it != pp.second; it++) {
		cout << it->second << endl;
	}
	while(1){}*/
	vector<vector<int>> sam(1000, vector<int>(100, 23));
	cout << sam[33][44] << endl;
	while(1){}
	return 0;
}

int main7() {
	unordered_multimap<int, int> sam;
	sam.insert(pair<int, int>(1, 2));
	auto pp = sam.equal_range(13);
	if (pp.first == sam.end() && pp.second == sam.end()) cout << "hh" << endl;
	// 없으면 이거 맞음
	while (1) {}
	return 0;
}

int main333() {
	string s = "hello";
	const char * arr = "hello";
	// 이거는 된다.
	string k(arr, arr+3);
	//string k(&s, &s + 3); //이거는 안됨!! s 자체가 string "값" 이어서 그런듯? &s s 둘다 안됨.
	cout << k << endl;
	while (1) {

	} return 0;
}

int main() {
	vector<unordered_multimap <string, string>> database(20000, unordered_multimap<string, string>());
	set<int> tocheck;
	ifstream in("tt.txt");
	ofstream out("clargeout.out");
	int T;
	in >> T;
	out << T << endl;
	for (int z = 0; z < T; z++) {
		int count = 0;
		int L;
		in >> L;
		for (int j = 0; j < L; j++) {
			string s;
			in >> s;
			string targetmid;
			char start;
			char end;
			// parse and preprocess to hash table
			if (s.size() == 1) {
				start = s[0];
				end = s[0];
				s = "";
			}
			else if (s.size() == 2) {
				start = s[0];
				end = s[1];
				s = "";
			}
			else {
				start = s[0];
				end = s[s.size() - 1];
				s = string(s.begin() + 1, s.end() - 1);
				sort(s.begin(), s.end());
			}
			tocheck.insert(s.size());
			string tp = "" + start + end;
			database[s.size()].insert(pair<string, string>(tp, s));
		}
		char s1, s2;
		int N, a, b, c, d;
		in >> s1 >> s2 >> N >> a >> b >> c >> d;

		// process book string
		string book = "" + s1 + s2;
		for (int i = 0; i < N - 2; i++) {
			book += (a*book[i] + b * book[i + 1] + c) % d;
		}

		// iterate through whole book and look for possible lengths of tocheck

		for (int i = 0; i < book.size(); i++) {
			for (auto it = tocheck.begin(); it != tocheck.end(); it++) {
				// check if the prospective size is possible
				if (i + *it - 1 < book.size()) {
					// check if substring matches
					string cc = "" + book[i] + book[i + *it - 1];
					auto possibles = database[*it].equal_range(cc);
					string middle(book.begin() + i + 1, book.begin() + i + *it);
					sort(middle.begin(), middle.end());
					for (auto it2 = possibles.first; it2 != possibles.second; it2++) {
						if (it2->second == middle) count++;
					}
				}
			}
		}

		// print return value
		out << "Case #" << z + 1 << ": " << count << endl;
	}
	in.close();
	out.close();
	return 0;
}

// -----
/*
double calculate(int N, int K, int * v) {
	int sum = 0;
	// calculate average ( expected value )
	for (int i = 0; i < N; i++) {
		sum += v[i];
	}
	double avg = (double)sum / (double)N;
	// calculate piece values
	int smallercount = 0;
	int smallersum = 0;
	int biggersum = 0;
	int biggercount = 0;
	for (int i = 0; i < N; i++) {
		if (avg >= v[i]) {
			smallersum += v[i];
			smallercount++;
		}
		else {
			biggersum += v[i];
			biggercount++;
		}
	}
	double p = (double)smallercount / (double)N;
	double res = 0;
	res = (1 - pow(p, K+1))*(double)biggersum / (double)biggercount + pow(p, K+1)*(double)smallersum / (double)smallercount;
	return res;
}

int main777() {
	int v[] = { 16,11,7,4,1 };
	cout << fixed << setprecision(6) << calculate(5,3, v);
	while(1){}
	ifstream in("B-small-practice.in");
	ofstream out("Bsout.out");
	int T;
	in >> T;
	for (int i = 0; i < T; i++) {
		int N, K;
		in >> N >> K;
		int * v = new int[N];
		for (int j = 0; j < N; j++) {
			in >> v[j];
		}
		out << fixed << setprecision(6) << calculate(N, K, v) << endl;
	}
	in.close();
	out.close();
	return 0;
}

// ---

int main888() {
	double s = 0.123456789;
	cout << s << endl;
	cout << fixed << setprecision(10);
	cout << s << endl;
	while(1){}
	return 0;
}


//------ love what you do

long long minclicks(long long data) {
	long long sam = data;
	int tmp[32];
	int i = 0;
	// parse and put number in int array
	while (i<32) {
		tmp[31 - i] = data % 10;
		data = data / 10;
		i++;
	}
	// start from first digit to find first occurence of odd digit
	int first = 32;
	for (int j = 0; j < 32; j++) {
		if (tmp[j] % 2 != 0) {
			first = j;
			break;
		}
	}
	// end if first = 15 ( all digits even )
	if (first == 32) {
		return 0;
	}
	// build comparitor integers based on first
	long long tens = 1;
	for (int i = 0; i < 31 - first; i++) {
		tens *= 10;
	}
	long long top;
	top = (long long)(tmp[first] + 1) * tens;
	long long low = 0;
	for (int j = 0; j < 31 - first; j++) {
		low += 8 * pow(10, j);
	}
	low += (tmp[first] - 1) * tens;
	tens *= 10;
	long long target = sam % tens;
	// return smaller range
	//cout << target << endl << top << endl << low << endl << sam << endl;
	if ((tmp[first] == 9&&tmp[first-1]%2==0)) {
		return target - low;
	}
	return top - target > target - low ? target - low : top - target;
}

bool isalleven(long long t) {
	while (t != 0) {
		if (t % 2 != 0) return false;
		t /= 10;
	}
	return true;
}

long long countall(long long data) {
	long long count = 0;
	long long low = data;
	long long high = data;
	while (true) {
		if (isalleven(low) || isalleven(high)) {
			return count;
		}
		low--;
		high++;
		count++;
	}
	return count;
}

int main9999() {
	ifstream sam("A-small-practice.in");
	ofstream out("out.out");
	int T;
	sam >> T;
	long long buffer;
	for (int i = 0; i < T; i++) {
		sam >> buffer;
		cout << "Case " << "#" << (i + 1) << ": " << buffer << endl;
		cout << "Case " << "#" << (i + 1) << ": " << minclicks(buffer) << endl;
		//cout << "Case " << "#" << (i + 1) << ": " << countall(buffer) << endl;
		//out << "Case " << "#" << (i + 1) << ": " << buffer << endl;
		out << "Case " << "#" << (i+1) << ": " << minclicks(buffer) << endl;
		//out << "Case " << "#" << (i + 1) << ": " << countall(buffer) << endl;
	}
	sam.close();
	out.close();
	while(1){}
	return 0;
}*/
