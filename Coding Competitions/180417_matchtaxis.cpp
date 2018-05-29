vector<vector<int>> matchtaxi(vector<vector<int>> board) {
	// find cars and number them
	// -1 for people, 1 for cars
	int count = 0;
	queue<vector<int>> buffer;
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[0].size(); j++) {
			if (board[i][j] == 1) {
				board[i][j] = 1 + count;
				count++;
				buffer.push(vector<int>(i, j));
			}
		}
	}
	// do BFS on the board	
	vector<vector<int>> dir = { {1,0},{-1,0},{0,1},{0,-1} };
	while (buffer.size() != 0) {
		vector<int> curr = buffer.front();
		// do iteration and coloring
		for (int i = 0; i < 4; i++) {
			int x = curr[0] + dir[i][0];
			int y = curr[0] + dir[i][1];
			if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size()) {
				vector<int> tmp;
				int area = 0;
				if (board[curr[0]][curr[1]] < -1000) {
					area = board[curr[0]][curr[1]] + 10000;
				}
				else {
					area = board[curr[0]][curr[1]];
				}
				if (board[x][y] == 0) {
					board[x][y] = area;
					tmp.push_back(x); tmp.push_back(y);
					buffer.push(tmp);
				}
				else if (board[x][y] == -1) {
					board[x][y] = -10000 + area;
					tmp.push_back(x); tmp.push_back(y);
					buffer.push(tmp);
				}
			}
		}
	}
	// print out the cars for the people
	vector<vector<int>> ret;
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board.size(); j++) {
			if (board[i][j] < -1000) {
				vector<int>tmp = { i,j,board[i][j] + 10000 };
			}
		}
	}
	return ret;
}
