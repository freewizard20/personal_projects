package my;

import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.util.StringTokenizer;

public class tripathcnt {
	
	static int[][] totalcache = new int[100][100];
	static int[][] pathcache = new int[100][100];
	static int[][] board;
	static int N;
	
	static public void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int M = Integer.parseInt(br.readLine());
		for(int z = 0 ; z < M ; z++) {
			N = Integer.parseInt(br.readLine());
			board = new int[N][N];
			for(int i = 0 ; i < N ; i++) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				for(int j = 0 ; j < i+1 ; j++) {
					board[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			for(int i = 0 ; i < 100 ; i++) {
				for(int j = 0 ; j < 100 ; j++) {
					totalcache[i][j]=-1;
					pathcache[i][j]=-1;
				}
			}
			totalsolve(0,0);
			System.out.println(pathsolve(0,0));
		}
	}
	
	static int totalsolve(int x, int y) {
		if(x==N-1) {
			totalcache[x][y] = board[x][y];
			return totalcache[x][y];
		}
		int ret = totalcache[x][y];
		if(ret != -1) {
			return ret;
		}
		ret = Math.max(board[x][y]+totalsolve(x+1,y), board[x][y]+totalsolve(x+1,y+1));
		totalcache[x][y]=ret;
		return ret;
	}
	
	static int pathsolve(int x, int y) {
		if(x==N-1) {
			pathcache[x][y] = 1;
			return 1;
		}
		int ret = pathcache[x][y];
		if(ret!=-1) {
			return ret;
		}
		if(totalcache[x+1][y]<totalcache[x+1][y+1]) {
			ret = pathsolve(x+1,y+1);
		}else if(totalcache[x+1][y]>totalcache[x+1][y+1]) {
			ret = pathsolve(x+1,y);
		}else {
			ret = pathsolve(x+1,y+1)+pathsolve(x+1,y);
		}
		pathcache[x][y] = ret;
		return ret;
	}
}
