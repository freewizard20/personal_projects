#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;

int n;
unordered_set<int> primes;

bool isprime(int a) {
	if (a == 1) return false;
	for (int i = 2; i <= sqrt(a); i++) {
		if (a%i == 0) return false;
	}
	return true;
}

int solve(int left, int topick, vector<int> buffer) {
	if (left < 0) return 0;
	if (topick == 0 && left==0) {
		
		for (int i = 0; i < buffer.size(); i++) {
			if (primes.find(buffer[i])==primes.end()) {
				return 0;
			}
		}
		return 1;
		
	}
	if (topick == 0 && left > 0) return 0;

	int small = buffer.size()==0?1:buffer.back();
	int ret = 0;

	for (int i = small; i <= left; i++) {
		buffer.push_back(i);
		ret += solve(left - i, topick - 1, buffer);
		buffer.pop_back();
	}
	return ret;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (int i = 0; i < 1000; i++) {
		if (isprime(i)) {
			primes.insert(i);
		}
	}

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> n;
		vector<int> tmp;
		cout << "#" << test_case << " " << solve(n, 3, tmp) << '\n';
	}
	while(1){}
	return 0;
}
