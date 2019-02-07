int arr[10][10];
int c = 0;



int countcombinations(int maxselect, int max, int toget) {
	if (toget == 0) {
		return 1;
	}
	if (maxselect > max) {
		return 0;
	}
	int suhap = 0;
	for (int i = maxselect; i <= max; i++) {
		suhap += countcombinations(i + 1, max, toget-1);
	}
	return suhap;
}

int backtrackprint(int x, int y,vector<pair<int,int>> v) {
	if (x >= 10 || y >= 10) {
		return 0;
	}
	if (arr[x][y] == 1) {
		return 0;
	}
	if (x == 9 && y == 9) {
		cout << c << "st ";
		c++;
		for (auto i : v) {
			cout << "(" << i.first << "," << i.second << ")" << " ";
		}
		cout << endl;
		return 1;
	}
	v.push_back(pair<int, int>(x, y));
	int sum = 0;
	sum += backtrackprint(x + 1, y, v);
	sum += backtrackprint(x, y + 1, v);
	return sum;
}

int backtrack(int x, int y) {
	if (x >= 10 || y >= 10) {
		return 0;
	}
	if (arr[x][y] == 1) {
		return 0;
	}
	if (x == 9 && y == 9) {
		return 1;
	}

	int sendup = 0;
	sendup += backtrack(x + 1, y);
	sendup += backtrack(x, y + 1);
	return sendup;
}

int dp(int x, int y) {
	if (x >= 10 || y >= 10) {
		return 0;
	}
	if (arr[x][y] == 1) {
		return 0;
	}
	if (x == 9 && y == 9) {
		return 1;
	}
	return dp(x + 1, y) + dp(x, y + 1);
}

int main666() {
	// create board
	memset(arr, 0, sizeof(int) * 100);
	arr[1][0] = 1;
	arr[3][3] = 1;
	arr[2][5] = 1;
	arr[2][9] = 1;
	arr[3][8] = 1;
	arr[6][7] = 1;
	arr[8][9] = 1;
	cout << countcombinations(0, 10, 4) << endl;
	//cout << backtrackprint(0, 0,vector<pair<int,int>>()) << endl;
	//cout << backtrack(0, 0) << endl;
	//cout << dp(0, 0) << endl;
	while(1){}
	return 0;
}
