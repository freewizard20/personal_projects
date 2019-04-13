#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <stack>

using namespace std;

int destination[10000][2];
int n;
int aisle[200];

bool isempty(int from, int to) {
	for (int i = from; i <= to; i++) {
		if (aisle[i] == 1) return false;
	}
	return true;
}

bool isdone() {
	for (int i = 0; i < 10000; i++) {
		if (destination[i][0] != -1) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for (int z = 0; z < t; z++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> destination[i][0] >> destination[i][1];
		}
		int time = 0;

		while (true) {
			for (int i = 0; i < n; i++) {
				if (destination[i][0] == -1) continue;
				if (isempty(destination[i][0], destination[i][1])) {
					for (int j = destination[i][0] / 2; j <= destination[i][1] / 2; j++) {
						aisle[j] = 1;
					}
				}
			}
			time++;
			for (int i = 0; i < 200; i++) aisle[i] = 0;
			if (isdone()) break;
		}
	}
	return 0;
}
