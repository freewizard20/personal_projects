// do BFS from nearby nodes

void painter(vector<vector<int>> & board){
	// enqueue all guards and start bfs there
	queue <pair<int,int>> buffer;
	for(int i = 0 ; i < board.size() ; i++){
		for(int j = 0 ; j < board[0].size() ; j++){
			if(board[i][j]==-1)
				buffer.push(pair<int,int>(i,j));
		}
	}
	// do bfs around the guards
	while(buffer.size()!=0){
		auto curr = buffer.top();
		vector<vector<int>> dir = {{-1,0},{1,0},{0,1},{0,-1}};
		for(auto it : dir){
			if(curr.first+it[0]>=0&&curr.first+it[0]<board.size()&&curr.second+it[1]>=0&&curr.second+it[1]<board[0].size()&&board[curr.first+it[0]][curr.second+it[1]]>=0){
			if(board[curr.first][curr.second]==-1){
				board[curr.first+it[0]][curr.second+it[1]] = 1;
				buffer.push(board[curr.first+it[0]][curr.second+it[1]];
			}else if(board[curr.first+it[0]][curr.second+it[1]]>board[curr.first][curr.second]+1){
board[curr.first+it[0]][curr.second+it[1]] = board[curr.first][curr.second]+1;
buffer.push(board[curr.first+it[0]][curr.second+it[1]];	
	}


// do DFS from nearby nodes

void painter(vector<vector<int>> & board){
	// do DFS from all guards
	for(int i = 0 ; i < board.size() ; i++){
		for(int j = 0 ; j < board[0].size() ; j++){
			if(board[i][j]==-1){
				dfspaint(board, i,j,0);
			}
		}
	}
}
void dfspaint(vector<vector<int>> & board, int x , int y , int dist){
	if(!(x>=0&&x<board.size()&&y>=0&&y<board[0].size())) return;
	if(board[x][y]<0) return;
	if(board[x][y]>dist+1) return;
	// fill this point
	board[x][y] = dist+1;
// do DFS to nearby points
dfspaint(board,x+1,y,dist+1);
dfspaint(board,x,y+1,dist+1);
dfspaint(board,x-1,y,dist+1);
dfspaint(board,x,y-1,dist+1);
}

