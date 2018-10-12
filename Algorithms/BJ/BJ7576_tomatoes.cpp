// ConsoleApplication1.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
// done in one try!!

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int main() {
	int m, n;
	cin >> m >> n;
	vector<vector<int>> tomatoes(n, vector<int>(m, 0));
	queue<vector<int>> color;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x;
			cin >> x;
			tomatoes[i][j] = x;
			if(x==1) color.push({ i,j,0 });
		}
	}

	// if queue is empty, there is no more to color
	int days = 0;
	while (color.size() != 0) {
		vector<int> curr = color.front();
		days = curr[2];
		color.pop();
		// color nearby elements and push to queue
		if (curr[0] + 1 < tomatoes.size() && tomatoes[curr[0] + 1][curr[1]] == 0) {
			tomatoes[curr[0] + 1][curr[1]] = 1;
			color.push({ curr[0] + 1, curr[1],curr[2] + 1 });
		}
		if (curr[1] + 1 < tomatoes[0].size() && tomatoes[curr[0]][curr[1]+1] == 0) {
			tomatoes[curr[0]][curr[1]+1] = 1;
			color.push({ curr[0], curr[1] + 1,curr[2] + 1 });
		}
		if (curr[0] - 1 >=0 && tomatoes[curr[0] - 1][curr[1]] == 0) {
			tomatoes[curr[0] - 1][curr[1]] = 1;
			color.push({ curr[0] - 1, curr[1],curr[2] + 1 });
		}
		if (curr[1]-1>=0 && tomatoes[curr[0]][curr[1]-1] == 0) {
			tomatoes[curr[0]][curr[1]-1] = 1;
			color.push({ curr[0], curr[1] - 1,curr[2] + 1 });
		}
	}
	
	// check if all tomatoes are done.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tomatoes[i][j] == 0) days = -1;
		}
	}

	cout << days << endl;
}
