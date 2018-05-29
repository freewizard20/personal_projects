package nolza;

import java.io.IOException;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class dice {
	static int[] dice = {0,0,0,0,0,0};
	static int[] curr;
	static int[][] board;
	static int[] order;
	static int err;
	static int[][] dir = {{0,1},{0,-1},{-1,0},{1,0}};
	
	static public void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int M = Integer.parseInt(st.nextToken());
		int N = Integer.parseInt(st.nextToken());
		curr = new int[2];
		board = new int[M][N];
		curr[0] = Integer.parseInt(st.nextToken());
		curr[1] = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());
		for(int i = 0 ; i < M ; i++) {
			StringTokenizer st2 = new StringTokenizer(br.readLine());
			for(int j = 0 ; j < N ; j++) {
				board[i][j] = Integer.parseInt(st2.nextToken());
			}
		}
		order = new int[K];
		StringTokenizer st3 = new StringTokenizer(br.readLine());
		for(int i = 0 ; i < K ; i++) {
			order[i] = Integer.parseInt(st3.nextToken())-1;
		}
		for(int i = 0 ; i < K ; i++) {
			if(noterr(order[i])) {
			movedice(order[i]);
			movecurr(order[i]);
			dothing();
			}
		}
	}
	
	static void movedice(int d) {
		int[] tmp = dice.clone();
		if(d==0) {
			dice[0]= tmp[3];
			dice[1]= tmp[2];
			dice[2]= tmp[0];
			dice[3]= tmp[1];
			dice[4]= tmp[4];
			dice[5]= tmp[5];
		}else if(d==1) {
			dice[0]= tmp[2];
			dice[1]= tmp[3];
			dice[2]= tmp[1];
			dice[3]= tmp[0];
			dice[4]= tmp[4];
			dice[5]= tmp[5];
		}else if(d==2) {
			dice[0]= tmp[4];
			dice[1]= tmp[5];
			dice[2]= tmp[2];
			dice[3]= tmp[3];
			dice[4]= tmp[1];
			dice[5]= tmp[0];
		}else {
			dice[0]= tmp[5];
			dice[1]= tmp[4];
			dice[2]= tmp[2];
			dice[3]= tmp[3];
			dice[4]= tmp[0];
			dice[5]= tmp[1];
		}
	}
	
	static boolean noterr(int d) {
		try {
			if(board[curr[0]+dir[d][0]][curr[1]+dir[d][1]]==-1) {
				
			}
			return true;
		}catch(Exception e) {
			return false;
		}
	}
	
	static void movecurr(int d) {
		curr[0] = curr[0]+dir[d][0];
		curr[1] = curr[1]+dir[d][1];
	}
	
	static void dothing() {
		if(board[curr[0]][curr[1]]==0) {
			board[curr[0]][curr[1]]=dice[1];
		}else {
			dice[1] = board[curr[0]][curr[1]];
			board[curr[0]][curr[1]]=0;
		}
		System.out.println(dice[0]);
	}
	
}
