package my;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOMB {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int M = Integer.parseInt(br.readLine());
		for(int z = 0 ; z < M ; z++) {
			int N = Integer.parseInt(br.readLine());
			int[][] board = new int[N][N];
			for(int i = 0 ; i < N ; i++) {
				char[] tmp = br.readLine().toCharArray();
				for(int j = 0 ; j < N ; j++) {
					if(tmp[j]=='.') {
						board[i][j] = -1;
					}else {
						board[i][j] = -2;
					}
				}
			}
			System.out.println("#"+(z+1)+" "+solve(board,0));
		}
	}
	
	static int solve(int[][] board,int count) {
		int[][] tmp2 = new int[board.length][board.length];
		int flag = 0;
		for(int i = 0 ; i < board.length ; i++) {
			for(int j = 0 ; j < board.length ; j++ ) {
				if(board[i][j]==-1) {
					flag=1;
				}
				tmp2[i][j] = board[i][j];
			}
		}
		if(flag==0) {
			return count;
		}
		int ret = 9999;
		for(int i = 0 ; i < board.length ; i++) {
			for(int j = 0 ; j < board.length ; j++) {
				if(board[i][j]==-1) {
					int[] tmp = {i,j};
					fill(board,tmp);
					ret = Math.min(ret, solve(board,count+1));
					for(int k = 0 ; k < board.length ; k++) {
						for(int l = 0 ; l < board.length ; l++) {
							board[i][j] = tmp2[i][j];
						}
					}
					
				}
			}
		}
		
		return ret;
		
	}
	
	
	static void fill(int[][] board, int[] tmp) {
		int shit = count(board,tmp[0],tmp[1]);
		if(shit!=0) {
			board[tmp[0]][tmp[1]]=shit;
			return;
		}else {
			board[tmp[0]][tmp[1]]=0;
			for(int i = -1; i <=1; i++) {
				for(int j = -1; j<=1;j++) {
					if(tmp[0]+i<0||tmp[1]+j<0||tmp[0]+i>board.length-1||tmp[1]+j>board.length-1) {
						continue;
					}
					if(!((i==0)&&(j==0))&&board[tmp[0]+i][tmp[1]+j]==-1) {
					shit = count(board,tmp[0]+i,tmp[1]+j);
					if(shit==0) {
						int[] tmp2 = {tmp[0]+i,tmp[1]+j};
						fill(board,tmp2);
					}else {
						try {
						board[tmp[0]+i][tmp[1]+j] = shit;
						}catch(Exception e) {
							
						}
					}
					}
				}
			}
		}
	}
	
	static int count(int[][] board, int x, int y) {
		int ret = 0;
		for(int i = -1 ; i <= 1 ; i++) {
			for(int j = -1; j <= 1 ; j++) {
				try {
				if(board[x+i][y+j]==-2) {
					ret++;
				}
				}catch(Exception e) {
					
				}
			}
		}
		return ret;
	}
}
