// BJ 1039

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

int number;
int k;
int resultMax;
int digits;

void swap(int x, int y) {
	vector<int> tmp;
	int num = number;
	while (num != 0) {		
		tmp.push_back(num%10);
		num /= 10;
	}
	reverse(tmp.begin(), tmp.end());
	
	if (x == 1 && tmp[y - 1] == 0) return;

	num = tmp[x-1];
	tmp[x-1] = tmp[y-1];
	tmp[y - 1] = num;

	number = 0;
	for (int i = 0; i < tmp.size(); i++) {
		number += pow(10, tmp.size() - i - 1) * tmp[i];
	}
	return;
}

void solve(int curr) {
	if (curr == 0) {
		if (number > resultMax) resultMax = number;
		return;
	}
	for (int j = 2; j <= digits; j++) {
		for (int i = 1; i < j; i++) {
			int tmp = number;
			swap(i, j);			
			solve(curr - 1);
			number = tmp;
		}
	}
}

int swap2(int x, int y, int number) {
	if (x > digits || y > digits) return -1;
	if (digits == 1) return number;

	vector<int> tmp;
	int num = number;
	while (num != 0) {
		tmp.push_back(num % 10);
		num /= 10;
	}
	reverse(tmp.begin(), tmp.end());

	if (x == 1 && tmp[y - 1] == 0) return -1;

	num = tmp[x - 1];
	tmp[x - 1] = tmp[y - 1];
	tmp[y - 1] = num;

	number = 0;
	for (int i = 0; i < tmp.size(); i++) {
		number += pow(10, tmp.size() - i - 1) * tmp[i];
	}
	return number;
}

void solve2() {
	queue<pair<int, int>> q;
	q.push(pair<int, int>(number, k));
	while (q.size() != 0) {
		int curr = q.front().second;
		int currn = q.front().first;
		if (curr==0 && currn > resultMax) resultMax = currn;
		q.pop();
		if (curr == 0) continue;
		for (int j = 2; j < digits; j++) {
			for (int i = 1; i < j; i++) {
				q.push(pair<int, int>(swap2(i, j, currn),curr-1));
			}
		}
	}
}

int change(int from, int to, int num) {
	int from_num = num / (int)pow(10, digits - from) % 10;
	int to_num = num / (int)pow(10, digits - to) % 10;
	int result = num;
	result = result - from_num * (int)pow(10, digits - from);
	result = result - to_num * (int)pow(10, digits - to);
	result = result + to_num * (int)pow(10, digits - from);
	result = result + from_num * (int)pow(10, digits - to);

	return result;
}

void solve3() {
	int state = 0;
	queue<int> q;
	q.push(number);
	while (q.size() != 0 && state < k) {
		state++;
		vector<bool> visited(pow(10, digits+1)+1, false);

		int size = q.size();
		while (size > 0) {
			size--;	

			if (q.size() == 0) continue;
			int currn = q.front();
			q.pop();
			
			for (int j = 2; j <= digits; j++) {
				for (int i = 1; i < j; i++) {
					int next = change(i, j, currn);
					if (next == -1) continue;
					if (next < (int)pow(10, digits - 1)) continue;
					if (!visited[next]) {
						if (state == k && resultMax < next) resultMax = next;
						visited[next] = true;
						if (i <= digits && j <= digits) q.push(next);
					}
				}				
			}
		}
	}
}

int main() {
	cin >> number >> k;
	digits = 0;
	int tmp = number;
	while (tmp != 0) {
		digits++;
		tmp /= 10;
	}
	if (number < 10) return number;

	resultMax = 0;
	solve3();
	if (resultMax == 0) cout << "-1" << endl;
	else cout << resultMax << endl;
}
