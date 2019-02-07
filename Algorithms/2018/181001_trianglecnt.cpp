#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int board[100][100];
int cache[100][100][2];

pair<int,int> maxtriangle(int x, int y, int n) {
	if (cache[x][y][0] != -1) return pair<int, int>(cache[x][y][0], cache[x][y][1]);
	if (x >= n-1 || y >= n) return pair<int, int>(board[x][y], 1);

	int down = board[x][y] + maxtriangle(x + 1, y, n).first;
	int side = board[x][y] + maxtriangle(x + 1, y + 1, n).first;
	pair<int, int> ret;
	if (down < side) {
		ret.first = side;
		ret.second = maxtriangle(x + 1, y+1, n).second;
	}
	else if (down > side) {
		ret.first = down;
		ret.second = maxtriangle(x + 1, y, n).second;
	}
	else {
		ret.first = down;
		ret.second = maxtriangle(x + 1, y + 1, n).second + maxtriangle(x + 1, y, n).second;
		//cout << x << " " << y << " " << endl;
	}
	cache[x][y][0] = ret.first;
	cache[x][y][1] = ret.second;
	//cout << ret.first << " " << ret.second << endl;
	return ret;
}

int main() {
	int n;
	cin >> n;
	for (int z = 0; z < n; z++) {
		int m;
		cin >> m;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j <= i; j++) {
				cache[i][j][0] = -1;
				cache[i][j][1] = -1;
				cin >> board[i][j];
			}
		}

		cout << maxtriangle(0, 0, m).second << endl;

	}
	//while(1){}
}
