package my;
import java.util.Scanner;

public class zeroout {
	
	static int[][] adddirection = {{-1,0},{0,1},{1,0},{0,-1}};
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int M = sc.nextInt();
		int N = sc.nextInt();
		char [][] board = new char[M][N];
		int[] red = new int[2];
		int[] blue = new int[2];
		for(int i = 0 ; i < M ; i++) {
			char [] tmp = sc.next().toCharArray();
			for(int j = 0 ; j < N ; j++) {
				board[i][j]=tmp[j];
				if(tmp[j]=='R') {
					red[0]=i;
					red[1]=j;
				}
				if(tmp[j]=='B') {
					blue[0]=i;
					blue[1]=j;
				}
			}
		}
			
		int ret = solve(board,red,blue,0,0);
		
		if(ret == 9999) {
			System.out.println(-1);
		}else {
			System.out.println(ret);
		}
	}
	
	static int solve(char[][] board, int[] red, int[] blue, int times, int doneflag) {
		if(times>10) {
			return 9999;
		}
		if(doneflag==1) {
			return times;
		}else if(doneflag==-1) {
			return 9999;
		}
		int ret = 9999;
		int[] rtmp;
		int[] btmp;
		char[][] boardtmp = new char[board.length][board[0].length];
		for(int i = 0; i < 4; i++) {
			rtmp = red.clone();
			btmp = blue.clone();
			for(int j = 0 ; j < board.length ; j++) {
				boardtmp[j] = board[j].clone();
			}
			doneflag = moving(board,red,blue,i);
			ret = Math.min(ret, solve(board,red,blue,times+1,doneflag));
			for(int j = 0 ; j < board.length;j++) {
				board[j]=boardtmp[j].clone();
			}
			red = rtmp;
			blue = btmp;
			
		}
		return ret;
	}
	
	static int moving(char[][] board, int[] red, int[] blue, int direction) {
		
		boolean binf = BinfrontR(board,red,blue,direction);
		int mvR = move(board,red,blue,0,direction);
		int mvB = move(board,red,blue,1,direction);
		if(mvB!=1 && binf) {
			mvR = move(board,red,blue,0,direction);
		}
		if(mvB==1) {
			return -1;
		}else if(mvR==1) {
			return 1;
		}else {
			return 0;
		}
	}
	
	static boolean BinfrontR(char[][] board, int[] red, int[] blue, int direction) {
		boolean ret = false;
		int [] currentxy = red.clone();
		while(true) {
			currentxy[0]+=adddirection[direction][0];
			currentxy[1]+=adddirection[direction][1];
			if(board[currentxy[0]][currentxy[1]]=='#') {
				break;
			}else if(board[currentxy[0]][currentxy[1]]=='B') {
				ret = true;
				break;
			}else if(board[currentxy[0]][currentxy[1]]=='O') {
				break;
			}
		}
		return ret;
	}
	
	static int move(char[][] board, int[] red, int[] blue, int movcolor, int direction) {
		int ret = 0;
		int[] currentxy;
		if(movcolor ==0) {
			currentxy = red.clone();
		}else {
			currentxy = blue.clone();
		}
		int[] nextxy = new int[2];
		nextxy[0]=currentxy[0]+adddirection[direction][0];
		nextxy[1]=currentxy[1]+adddirection[direction][1];
		while(true) {
			
			if(board[nextxy[0]][nextxy[1]]=='#'||board[nextxy[0]][nextxy[1]]=='R'||board[nextxy[0]][nextxy[1]]=='B') {
				if(movcolor==0) {
					board[red[0]][red[1]] = '.';
					board[currentxy[0]][currentxy[1]] = 'R';
					red[0] = currentxy[0];
					red[1] = currentxy[1];
				}else {
					
					board[blue[0]][blue[1]] = '.';
					board[currentxy[0]][currentxy[1]] = 'B';
					blue[0] = currentxy[0];
					blue[1] = currentxy[1];
				}
				break;
			}
			if(board[nextxy[0]][nextxy[1]]=='O') {
				ret = 1;
				if(movcolor==0) {
					board[red[0]][red[1]] = '.';
					red[0]=-9999;
					red[1]=-9999;
				}else {
					board[blue[0]][blue[1]] = '.';
					blue[0]=-9999;
					blue[1]=-9999;
				}
				break;
			}
			currentxy[0]=nextxy[0];
			currentxy[1]=nextxy[1];
			
			nextxy[0]=nextxy[0]+adddirection[direction][0];
			nextxy[1]=nextxy[1]+adddirection[direction][1];
		}
		return ret;
	}
}
