#include "stdafx.h"
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

char namearr[100][30];
int pointarr[100];
int weightarr[100];
int N, W;

int solve(int n, int w);
void match(int n, int w);

int cache[101][1001];
vector<int> retarr;



int main2() {
	char arr[10];
	scanf("%s", arr);
	printf("%s", arr);
	while (1) {}
	return 0;
}

int main() {
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 1000; j++) {
			cache[i][j] = -1;
		}
	}
	int M;
	scanf("%d", &M);
	for (int z = 0; z < M; z++) {
		retarr.erase(retarr.begin(), retarr.end());
		scanf("%d %d", &N, &W);
		for (int i = 0; i < N; i++) {
			scanf("%s %d %d", namearr[i], &weightarr[i], &pointarr[i]);
		}
		int ret = solve(0, W);
		match(0, W);
		//printf("%d %d\n", ret,retarr.size());
		cout << ret << " " << retarr.size() << endl;
		for (int i = 0; i < retarr.size(); i++) {
			//printf("%s\n", namearr[retarr.at(i)]);
			cout << namearr[retarr.at(i)] << endl;
		}
	}
	while (1) {}
	return 0;
}

void match(int n,int w) {
	if (n == N) {
		return;
	}
	if (solve(n, w) == solve(n + 1, w)) {
		match(n + 1, w);
	}
	else {
		retarr.push_back(n);
		match(n + 1, w - weightarr[n]);
	}
}

int solve(int n, int w) {
	if(n == N) {
		return 0;
	}
	if (cache[n][w] != -1) {
		return cache[n][w];
	}
	int ret = solve(n + 1, w);
	if (w - weightarr[n] >= 0) {
		ret = max(ret, solve(n + 1, w - weightarr[n]) + pointarr[n]);
	}
	cache[n][w] = ret;
	return ret;
}
