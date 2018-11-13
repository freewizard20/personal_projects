#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int h, w, n;
int board[15][12];
int rep[15][12];
int rep2[15][12];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };

void organize() {

	for (int j = 0; j < w; j++) {
		for (int i = h-1; i >=0 ; i--) {
			if (rep[i][j] == 0) {
				for (int k = i - 1; k >= 0; k--) {
					if (rep[k][j] != 0) {
						rep[i][j] = rep[k][j];
						rep[k][j] = 0;
						break;
					}
				}
			}
		}
	}

}

void kaboom(int a, int b, int strength) {

	//cout << "kaboom " << a << " " << b << " " << strength << endl;

	rep2[a][b] = 1;

	for (int i = 0; i < 4; i++) {
		int tmpx = a;
		int tmpy = b;		
		for (int j = 0; j < strength-1; j++) {
			tmpx += dx[i];
			tmpy += dy[i];
			if (tmpx >= 0 && tmpx < h && tmpy >= 0 && tmpy < w && rep2[tmpx][tmpy]!=1) {
				kaboom(tmpx, tmpy, rep[tmpx][tmpy]);
			}
		}
	}
	
}

void boom(int m) {

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			rep2[i][j] = 0;
		}
	}

	for (int i = 0; i < h; i++) {

		if (rep[i][m] != 0) {
			kaboom(i, m, rep[i][m]);
			break;
		}

	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (rep2[i][j] == 1) {
				rep[i][j] = 0;
			}
		}
	}

	/*for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << rep[i][j] << " ";
		}
		cout << endl;
	}*/

	organize();

}

int solve(int m, vector<int> & buffer) {

	if (m == 0) {
		
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				rep[i][j] = board[i][j];
			}
		}

		for (int i = 0; i < n; i++) {
			boom(buffer[i]);
		}

		int cnt = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (rep[i][j] != 0) cnt++;
			}
		}

		return cnt;

	}

	int ret = 99999999;

	for (int i = 0; i < w; i++) {

		buffer.push_back(i);
		ret = min(ret, solve(m - 1, buffer));
		buffer.pop_back();

	}

	return ret;
}

int main() {

	int t;
	cin >> t;

	for(int z = 0 ; z < t ; z++){
	
		cin >> n >> w >> h;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> board[i][j];
			}
		}
		vector<int> tmp;
		cout << "#" << (z + 1) << " " << solve(n, tmp) << '\n';

	}

}
