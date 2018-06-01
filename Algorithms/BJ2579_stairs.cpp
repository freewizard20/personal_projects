// solved it in one try!


#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int cache[400][2];

int getmax(vector<int> & stairs, int curr, int next) {
	if (cache[curr][next] != -1) return cache[curr][next];
	if (curr == stairs.size() - 1) return stairs[stairs.size() - 1];
	if (curr == stairs.size() - 2) return stairs[stairs.size() - 1] + stairs[stairs.size() - 2];
	if (curr == stairs.size() - 3) return stairs[stairs.size() - 1] + stairs[stairs.size() - 3];

	int ret = 0;

	if (curr == 0) {
		ret = max(getmax(stairs, 1, 0), getmax(stairs, 2, 0));
	}
	else {
		if (next == 1) {
			ret = stairs[curr] + getmax(stairs, curr + 2, 0);
		}
		else {
			ret = stairs[curr] + max(getmax(stairs, curr + 1, 1), getmax(stairs, curr+2, 0));
		}
	}
	
	cache[curr][next] = ret;
	return ret;
}

int main()
{
	int n;
	for (int i = 0; i < 400; i++) {
		for (int j = 0; j < 2; j++) {
			cache[i][j] = -1;
		}
	}
	cin >> n;
	vector<int> stairs = { 0 };
	for (int i = 0; i < n ; i++) {
		int x;
		cin >> x;
		stairs.push_back(x);
	}
	cout << getmax(stairs, 0, 0) << endl;

}

