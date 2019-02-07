#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, x, y, k;
int board[20][20];
int inst[1000];

// bottom, top, N E S W
int dice[6];
int dx[4] = {0,0,-1,1};
int dy[4] = { 1,-1,0,0 };

void back() {
	int tmp[6];
	for (int i = 0; i < 6; i++) {
		tmp[i] = dice[i];
	}
	dice[0] = tmp[4];
	dice[1] = tmp[2];
	dice[2] = tmp[0];
	dice[4] = tmp[1];
}

void left() {
	int tmp[6];
	for (int i = 0; i < 6; i++) {
		tmp[i] = dice[i];
	}
	dice[0] = tmp[5];
	dice[1] = tmp[3];
	dice[3] = tmp[0];
	dice[5] = tmp[1];
}

void right() {
	int tmp[6];
	for (int i = 0; i < 6; i++) {
		tmp[i] = dice[i];
	}
	dice[0] = tmp[3];
	dice[1] = tmp[5];
	dice[3] = tmp[1];
	dice[5] = tmp[0];
}

void front() {
	int tmp[6];
	for (int i = 0; i < 6; i++) {
		tmp[i] = dice[i];
	}
	dice[0] = tmp[2];
	dice[1] = tmp[4];
	dice[2] = tmp[1];
	dice[4] = tmp[0];
}

int main() {

	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	int curr;
	for (int i = 0; i < k; i++) {
		cin >> curr;
		curr--;
		int tmpx = x + dx[curr];
		int tmpy = y + dy[curr];
		if (!(tmpx >= 0 && tmpx < n&&tmpy >= 0 && tmpy < m)) {
			continue;
		}
		switch (curr) {
		case 0:
			right();
			break;
		case 1:
			left();
			break;
		case 2:
			front();
			break;
		case 3:
			back();
			break;
		}
		if (board[tmpx][tmpy] == 0) {
			board[tmpx][tmpy] = dice[0];
		}
		else {
			dice[0] = board[tmpx][tmpy];
			board[tmpx][tmpy] = 0;
		}
		cout << dice[1] << endl;
		x = tmpx;
		y = tmpy;
	}
}
