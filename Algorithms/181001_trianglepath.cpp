#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int board[100][100];
int cache[100][100];

int trianglepath(int x, int y, int n) {
	if (cache[x][y] != -1) return cache[x][y];
	if (x >= n || y >= n) {
		return 0;
	}

	int ret = board[x][y]+ trianglepath(x + 1, y, n);
	ret = max(ret, board[x][y] + trianglepath(x+1, y + 1, n));
	cache[x][y] = ret;
	return ret;
}

int main() {
	
	//init
	int n, m;

	cin >> n;
	for (int z = 0; z < n; z++) {
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				board[i][j] = -1;
				cache[i][j] = -1;
			}
		}
		
		cin >> m;
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < j+1; k++) {
				cin >> board[j][k];
			}
		}

		cout << trianglepath(0, 0, m) << endl;

	}
	
	while(1){}
}
