#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int n, m;
char board[20][20];
int curr[2];
int reg;
int dir;
int flag;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void work() {

	//cout << board[curr[0]][curr[1]] << endl;

	switch (board[curr[0]][curr[1]]) {
	case '<':
		dir = 2;
		break;
	case '>':
		dir = 3;
		break;
	case '^':
		dir = 0;
		break;
	case 'v':
		dir = 1;
		break;
	case '_':
		if (reg == 0) {
			dir = 3;
		}
		else {
			dir = 2;
		}
		break;
	case '|':
		if (reg == 0) {
			dir = 1;
		}
		else {
			dir = 0;
		}
		break;
	}

	char x = board[curr[0]][curr[1]];

	if (x == '?') {
		dir = rand() % 4;
	}
	else if (x == '.') {

	}
	else if (x == '@') {
		flag = 1;
		return;
	}
	else if (x >= '0'&&x <= '9') {
		reg = x - '0';
	}
	else if (x == '+') {
		reg++;
		if (reg == 16) {
			reg = 0;
		}
	}
	else if(x=='-') {
		reg--;
		if (reg == -1) {
			reg = 15;
		}
	}

	curr[0] = curr[0] + dx[dir];
	curr[1] = curr[1] + dy[dir];

	if (curr[0] == -1) {
		curr[0] = n - 1;
	}
	if (curr[0] == n) {
		curr[0] = 0;
	}
	if (curr[1] == -1) {
		curr[1] = m - 1;
	}
	if (curr[1] == m) {
		curr[1] = 0;
	}

}

int main() {

	srand(time(NULL));

	int t;
	cin >> t;

	for (int z = 0; z < t; z++) {

		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> board[i][j];
			}
		}

		for (int j = 0; j < 100; j++) {
			curr[0] = 0;
			curr[1] = 0;
			reg = 0;
			dir = 3;
			flag = 0;

			for (int i = 0; i < 5000; i++) {
				work();
				if (flag == 1) {
					break;
				}
			}

			if (flag == 1) {
				break;
			}

		}

		if (board[curr[0]][curr[1]] == '@') {
			cout << "#" << (z + 1) << " " << "YES" << endl;
		}
		else {
			cout << "#" << (z + 1) << " " << "NO" << endl;
		}

	}

	while(1){}
}
