#include <iostream>
#include <vector>

using namespace std;

const int covertype[4][3][2] = {
	{{0,0},{1,0},{0,1}},
	{{0,0},{0,1},{1,1}},
	{{0,0},{1,0},{1,1}},
	{{0,0},{1,0},{1,-1}}
};

pair<int,int> iscovered(vector<vector<int>> board) {
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			if (board[i][j] == 0) return pair<int, int>(i, j);
		}
	}
	return pair<int,int>(-9999,-9999);
}

int cover(vector<vector<int>> board) {
	auto it = iscovered(board);
	if (it.first==-9999) return 1;
	int ret = 0;
	for (int i = 0; i < 4; i++) {
		// fill the positions
		int tmpx[3];
		int tmpy[3];
		int ok = 0;
		for (int j = 0; j < 3; j++) {
			tmpx[j] = it.first + covertype[i][j][0];
			tmpy[j] = it.second + covertype[i][j][1];
			if (tmpx[j] >= 0 && tmpy[j] >= 0 && tmpx[j] < board.size() && tmpy[j] < board[0].size() && board[tmpx[j]][tmpy[j]] == 0) {
				ok++;
			}
		}
		if (ok == 3) {
			for (int j = 0; j < 3; j++) {
				board[tmpx[j]][tmpy[j]] = 1;
			}
			/*for (int a = 0; a < board.size(); a++) {
				for (int b = 0; b < board[0].size(); b++) {
					cout << board[a][b] << " ";
				}
				cout << endl;
			}
			cout << "-----------" << endl;*/
			ret += cover(board);
			for (int j = 0; j < 3; j++) {
				board[tmpx[j]][tmpy[j]] = 0;
			}
		}
	}

	return ret;

}

int main() {

	int T;
	cin >> T;
	for (int z = 0; z < T; z++) {

		int x, y;
		cin >> x >> y;
		vector<vector<int> > board(x, vector<int>(y, 0));
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				char tmp;
				cin >> tmp;
				if (tmp == '#') {
					board[i][j] = 1;
				}
				else {
					board[i][j] = 0;
				}
			}
		}

		cout << cover(board) << endl;
	}

}
