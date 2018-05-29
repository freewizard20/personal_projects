#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_set>
#include <bitset>

using namespace std;

int isdoctor(int level, int key) {
	if (level == 1) return 0;
	// general case
	int myparent = isdoctor(level - 1, key / 2);
	if (myparent == 1) {
		if (key % 2 == 0) return 1;
		else return 0;
	}
	else {
		if (key % 2 == 0) return 0;
		else return 0;
	}
}

int mai888n() {
	cout << isdoctor(4, 3) << endl;
	while(1){}
	return 0;
}

// be passionate.

// Generate a lookup table for 32bit operating system 
// using macro 
#define R2(n)     n,     n + 2*64,     n + 1*64,     n + 3*64
#define R4(n) R2(n), R2(n + 2*16), R2(n + 1*16), R2(n + 3*16)
#define R6(n) R4(n), R4(n + 2*4 ), R4(n + 1*4 ), R4(n + 3*4 )

// Lookup table that store the reverse of each table
unsigned int lookuptable[256] = { R6(0), R6(2), R6(1), R6(3) };

/* Function to reverse bits of num */
int reverseBits(unsigned int num)
{
	int reverse_num = 0;

	// Reverse and then rearrange 

	// first chunk of 8 bits from right
	reverse_num = lookuptable[num & 0xff] << 24 |

		// second chunk of 8 bits from  right 
		lookuptable[(num >> 8) & 0xff] << 16 |

		lookuptable[(num >> 16) & 0xff] << 8 |
		lookuptable[(num >> 24) & 0xff];

	return reverse_num;
}

//driver program to test above function 
int ma123in()
{
	int x = 12456;
	printf("%u", reverseBits(x));
	while(1){}
	return 0;
}

string print(long long n) {
	stack<int> reverse;
	string ret = "";
	while (n != 0) {
		reverse.push('0' + n % 2);
		n /= 2;
	}
	while (reverse.size() != 0) {
		ret.push_back(reverse.top());
		reverse.pop();
	}
	return ret;
}

int toint(string s) {
	int ret = 0;
	int it = 1;
	for (int i = s.size() - 1; i >= 0; i--) {
		ret += (s[i] - '0')*it;
		it *= 2;
	}
	return ret;
}

string printfloat(float sam) {
	
	// check float int range
	int tmp = (int)sam;
	int count = 0;
	while (tmp != 0) {
		count++;
		tmp /= 10;
	}

	// extract all numbers of float
	while (((int)sam) != sam) {
		sam *= 10;
	}
	tmp = (int)sam;
	stack<int> numbers;
	while (tmp != 0) {
		numbers.push(tmp % 10);
		tmp /= 10;
	}
	string ret = "";
	int cnt = 0;
	while (numbers.size() != 0) {
		ret.push_back(numbers.top() + '0');
		if (cnt == count-1) ret.push_back('.');
		cnt++;
		numbers.pop();
	}
	return ret;
}

string printb(int n) {
	// bit searcher
	int m = INT_MIN;
	// move m to top
	while ((n&m) == 0) {
		cout << m << endl;
		m=m >> 1;
	}
	// check bit status
	string s = "";
	while (m != 0) {
		cout << m << endl;
		s.push_back((m&n != 0) + '0');
		m=m >> 1;
	}
	return s;
}

string newtry(int n) {
	return "";
}

union tester {
	double f;
	long long i;
};

string printz(int sam) {
	int m=1;
	stack<char> tmp;
	for (int i = 0; i < 63; i++) {
		tmp.push('0' + ((sam&m) != 0));
		m=m << 1;
	}
	string ret;
	while (tmp.size() != 0) {
		ret.push_back(tmp.top());
		tmp.pop();
	}
	return ret;
}

// clear all bits from msb to i
int clearMSB(int n, int i) {
	int m = (1 << i)-1;
	return n&m;
}

// clear all bits from i to LSB
int clearLSB(int n, int i) {
	int m = (1 << (i+1)) - 1;
	m = ~m;
	return n&m;
}

int ma121212in() {
	bitset<32> tmp1(331);
	bitset<32> tmp2(331 & 330);
	cout << tmp1 << endl;
	cout << tmp2 << endl;
	while(1){}
	return 0;
}

// 그 한 문제가 빈틈이면 너는 죽는다. 정말 모든 것을 알아야 한다는 심정으로 임해라

vector<int> findprimes(int n) {
	vector<int> res;
	vector<bool> deleted(n+1, false);
	for (int i = 2; i <= n; i++) {
		if (deleted[i] == false) {

			//insert myself
			res.push_back(i);

			// delete all
			for (int j = i*2; j <= n; j = j + i) {
				deleted[j] = true;
			}
		}
	}
	return res;
}

int mai333n(){
	vector<int> res = findprimes(1000);
	for (int x : res) cout << x << " ";
	while(1){}
	return 0;
}

// 왜 이렇게 한가하니?

int addone(int n) {
	// remove all 1s until 0 met
	int m = 1;
	while (m&n) {
		n = m^n;
		m = m << 1;
	}
	// make the first 0, 1
	n = m | n;
	return n;
}

int turnoff(int n) {
	int m = 1;
	while ((m&n)!=m) {
		m = m << 1;
	}
	n = n^m;
	return n;
}

bool ispowerof4(int n) {
	// count number of zeroes before first zero.
	int m = 1;
	int count = 0;
	while ((n&m) != m) {
		count++;
		m = m << 1;
	}
	// check if n is even
	if (m % 2 == 0 && m == n) return true;
	return false;
}

int findcases(int n) {
	unordered_set<int> pool;
	pool.insert(0);
	int generator = 1;
	int count = 0;
	for (int i = 2; i <= n+1; i++) {
		auto it = pool.find(generator-n);
		if (it != pool.end()) count++;
		pool.insert(generator);
		generator += i;
	}
	return count;
}

int gcd(int n, int m) {
	if (n == m) return n;
	if (n > m) return gcd(n - m, m);
	else return gcd(n, m - n);
}

int findlcm(int n, int m) {
	return m*n / gcd(n, m);
}

int findlcmarr(vector<int> & data) {
	int lcm = data[0];
	for (int i = 1; i < data.size(); i++) {
		lcm = findlcm(lcm, data[i]);
	}
	return lcm;
}

int findgcdarr(vector<int> & data) {
	int gcd = data[0];
	for (int i = 1; i < data.size(); i++) {
		//gcd = gcd(gcd, data[i]);
	}
	return gcd;
}



int mai666n() {
	cout << findlcm(72, 32) << endl;
	int m = 1;
	m=m << 3;
	cout << print(27 ^ m)<<endl;
	while(1){}
	return 0;
}
