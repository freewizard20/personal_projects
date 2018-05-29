package nolza;

import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.Vector;

public class snake {
	
	static int[][] board;
	static int time;
	static int[] change;
	static int dir;
	static int[][] go = {{-1,0},{0,1},{1,0},{0,-1}};
	static int end = 0;
	static int[] head = {0,0};
	static int[] tail = {0,0};
	static Vector<int[]> trace;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		change = new int[10001];
		for(int i = 0 ; i < 10001 ; i++) {
			change[i]=0;
		}
		board = new int[N][N];
		for(int i = 0 ; i < N ; i++) {
			for(int j = 0 ; j < N ; j++){
				board[i][j] = 0;
			}
		}
		time = 0;
		dir = 1;
		trace = new Vector<int[]>();
		int[] s = {0,0};
		trace.add(s);
		int K = Integer.parseInt(br.readLine());
		for(int i = 0 ; i < K ; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int M1 = Integer.parseInt(st.nextToken());
			int M2 = Integer.parseInt(st.nextToken());
			board[M1-1][M2-1] = 1;
		}
		board[0][0] = 2;
		int L = Integer.parseInt(br.readLine());
		for(int i = 0 ; i < L ;i++) {
			StringTokenizer st2 = new StringTokenizer(br.readLine());
			int M3 = Integer.parseInt(st2.nextToken());
			String M4 = st2.nextToken();
			if(M4.equals("D")) {
				change[M3]=1;
			}else {
				change[M3]=-1;
			}
		}
		gogo();
		System.out.println(time);
	}
	
	static void gogo() {
		while(true) {
		nextboard();
		time++;
		if(end==1) {
			return;
		}
		}
	}
	
	static void nextboard() {
		int[] nextpos = new int[2];
		if(change[time]==1) {
			dir = (dir+1)%4;
		}
		if(change[time]==-1) {
			dir = dir-1;
			if(dir==-1) {
				dir = 3;
			}
		}
		nextpos[0]=head[0]+go[dir][0];
		nextpos[1]=head[1]+go[dir][1];
		head[0] = nextpos[0];
		head[1] = nextpos[1];
		trace.add(head.clone());
		try {
			if(board[nextpos[0]][nextpos[1]]==1) {
				
			}
		}catch(Exception e) {
			end = 1;
			return;
		}
		if(board[nextpos[0]][nextpos[1]]==2) {
			end = 1;
			return;
		}else if(board[nextpos[0]][nextpos[1]]==1) {
			board[nextpos[0]][nextpos[1]]=2;
			return;
		}else {
			board[nextpos[0]][nextpos[1]]=2;
			board[trace.get(0)[0]][trace.get(0)[1]]=0;
			tail[0]=trace.get(1)[0];
			tail[1]=trace.get(1)[1];
			trace.remove(0);
			return;
		}
	}
}
