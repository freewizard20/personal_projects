package my;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class circuit {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int M = Integer.parseInt(br.readLine());
		for(int z = 0 ; z < M ; z++) {
			int N = Integer.parseInt(br.readLine());
			int[][] board = new int[N][N];
			int one = 0;
			for(int i = 0 ; i < N ; i++) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				for(int j = 0 ; j < N ; j++) {
					board[i][j]= Integer.parseInt(st.nextToken());;
					if(board[i][j]==1) {
						one++;
					}
					}
			}
			int [][] chips = new int[one][3];
			int cc = 0;
			for(int i = 0 ; i < N ; i++) {
				for(int j = 0 ; j < N ; j++) {
					if(board[i][j]==1) {
						int[] tmp = new int[3];
						if(i==0||j==0||i==N-1||j==N-1) {
							tmp[2]=1;
						}else {
							tmp[2]=0;
						}
						tmp[0]=i;
						tmp[1]=j;
						chips[cc] = tmp.clone();
						cc++;
					}
				}
			}
			int ret = 0;
			ret = solve(board,chips,one,0);
			if(ret==9999) {
				System.out.println("#"+M+ " " + -1);
			}else {
				System.out.println("#"+M+" " + ret);
			}
			
		}
		}
	
	static int solve(int[][] board, int[][] chips, int count, int status) {
		if(status==-1) {
			return 9999;
		}
		if(status==1) {
			int count2 = 0;
			for(int i = 0 ; i < board.length ; i++) {
				for(int j = 0 ; j < board.length; j++) {
					if(board[i][j]==2) {
						count2++;
					}
				}
			}
			return count2;
		}
		if(count==0) {
			return 9999;
		}
		int ret = 9999;
		for(int i = 0 ; i < 4 ; i++) {
			int[][] boardtmp = new int[board.length][board.length];
			int[][] chipstmp = new int[chips.length][3];
			for(int j = 0 ; j < board.length ; j++) {
				boardtmp[j]=board[j].clone();
			}
			for(int j = 0 ; j < chips.length ; j++) {
				chipstmp[j]=chips[j].clone();
			}
			int status2 = plant(board,chips,count,i);
			ret = Math.min(ret, solve(board,chips,count-1,status2));
			for(int j = 0 ; j < board.length ; j++) {
				board[j]=boardtmp[j].clone();
			}
			for(int j = 0 ; j < chips.length ; j++) {
				chips[j]=chipstmp[j].clone();
			}
		}
		return ret;
	}
	
	static int [][] direction = {
			{-1,0},{0,1},{1,0},{0,-1}		
	};
	
	static int plant(int[][] board,int[][] chips,int count,int i) {
		if(chips[count-1][2]==1) {
			if(allgreen(chips)) {
				return 1;
			}else {
				return 0;
			}
		}
		// count-1 chip을 i 방향으로 선 이어본다. 그 후에 전체 체크를 해서 1 아님 0 아님 -1을 반환한다.
		int ret = 0;
		int[] currentxy = new int[2];
		currentxy[0] = chips[count-1][0];
		currentxy[1] = chips[count-1][1];
		int[] nextxy = new int[2];
		nextxy[0] = currentxy[0] + direction[i][0];
		nextxy[1] = currentxy[1] + direction[i][1];
		int [][] colorxy = new int[20][2];
		for(int k = 0; k < 20 ;k++) {
			for(int j = 0 ; j < 2 ; j++) {
				colorxy[k][j]=2323;
			}
		}
		int cc = 0;
		while(true) {
			if(nextxy[0]<0||nextxy[0]==board.length||nextxy[1]<0||nextxy[1]==board.length) {
				chips[count-1][2]=1;
				break;
			}
			if(board[nextxy[0]][nextxy[1]]==1||board[nextxy[0]][nextxy[1]]==2) {
				ret = -1;
				break;
			}
			colorxy[cc][0] = nextxy[0];
			colorxy[cc][1] = nextxy[1];
			nextxy[0] = nextxy[0] + direction[i][0];
			nextxy[1] = nextxy[1] + direction[i][1];
			cc++;
		}
		
		if(ret==0) {
			int bb = 0;
			while(colorxy[bb][0]!=2323) {
				board[colorxy[bb][0]][colorxy[bb][1]] = 2;
				bb++;
			}
		}
		
		if(allgreen(chips)) {
			ret = 1;
		}
		return ret;		
}
	
	static boolean allgreen(int[][] chips) {
		boolean ok = true;
		for(int i = 0 ; i < chips.length ; i++) {
			if(chips[i][2]==0) {
				ok = false;
				break;
			}
		}
		return ok;
	}
	
}

