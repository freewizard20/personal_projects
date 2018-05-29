package my;

import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class trianglepath {
	
	static int[][] board;
	static int[][] cache;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int M = Integer.parseInt(br.readLine());
		for(int z = 0 ; z < M ; z++) {
			int N = Integer.parseInt(br.readLine());
			board = new int[N][N];
			for(int i = 0 ; i < N ; i++) {
				for(int j = 0 ; j < N ; j++) {
					board[i][j] = -1;
				}
			}
			cache = new int[N][N];
			for(int i = 0 ; i < N ; i++) {
				for(int j = 0 ; j < N ; j++) {
					cache[i][j] = -1;
				}
			}
			for(int i = 0 ; i < N ; i++) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				int j = 0;
				while(st.hasMoreTokens()) {
					board[i][j] = Integer.parseInt(st.nextToken());
					j++;
				}
			}
			System.out.println(solve2(0,0));
		}
	}
	
	static int solve(int x, int y, int sum) {
		if(x==board.length-1) {
			return sum + board[x][y];
		}
		sum += board[x][y];
		return Math.max(solve(x+1,y+1,sum), solve(x+1,y,sum));
		
	}
	
	static int solve2(int x, int y) {
		if(x==board.length-1) {
			return board[x][y];
		}
		int ret = cache[x][y];
		if(ret!=-1) {
			return ret;
		}
		ret = 0;
		ret = Math.max(solve2(x+1,y)+board[x][y], solve2(x+1,y+1)+board[x][y]);
		cache[x][y] = ret;
		return ret;
	}
}
