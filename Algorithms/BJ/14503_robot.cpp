#include <iostream>
#include <vector>

using namespace std;

int n, m;
int board[50][50];
int robot[2];
int dir;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int cnt;

bool inbound(int x, int y) {
	return x >= 0 && y >= 0 && x < n&&y < m;
}

int main() {

	cin >> n >> m;
	cin >> robot[0] >> robot[1] >> dir;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	cnt = 0;

	while (1) {

		if (board[robot[0]][robot[1]] == 0) {
			board[robot[0]][robot[1]] = 2;
			cnt++;
		}

		int flag = 0;
		// scan boundary
		for (int i = 0; i < 4; i++) {
			int tmpx = robot[0] + dx[i];
			int tmpy = robot[1] + dy[i];
			if (tmpx >= 0 && tmpx < n && tmpy >= 0 && tmpy < m) {
				if (board[tmpx][tmpy] == 1 || board[tmpx][tmpy] == 2) {
					flag++;
				}
			}
		}

		int back = (dir + 2) % 4;
		int backx = robot[0] + dx[back];
		int backy = robot[1] + dy[back];
		if (flag==4 && (!(backx >= 0 && backy >= 0 && backx < n&&backy < m) || board[backx][backy] == 1)) {
			break;
		}
		else if(flag==4){
			robot[0] = backx;
			robot[1] = backy;
			continue;
		}
		
		int left = dir <= 0 ? 3 : dir - 1;
		
		int tmpx = robot[0] + dx[left];
		int tmpy = robot[1] + dy[left];
		if (inbound(tmpx, tmpy) && board[tmpx][tmpy] == 0) {
			dir = left;
			robot[0] = tmpx;
			robot[1] = tmpy;
		}
		else {
			dir = left;
		}



	}

	cout << cnt << endl;
		
}
