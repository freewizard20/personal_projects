import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int M = Integer.parseInt(br.readLine());
		for(int z = 0 ; z < M ; z++) {
			int N = Integer.parseInt(br.readLine());
			int[][] board = new int[N][N];
			for(int i = 0 ; i < N ; i++) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				for(int j = 0 ; j < N ; j++) {
					board[i][j] = Integer.parseInt(st.nextToken());
				}
			}
		  	cache = new int[N][N];
		  	for(int i = 0 ; i < N ; i++){
			  for(int j = 0 ; j < N ; j++){
				cache[i][j] = -1;
			  }
				  }
			boolean ans = solve(board,0,0);
			if(ans==true) {
				System.out.println("YES");
			}else {
				System.out.println("NO");
			}
		}
	}
	
  	static int [][] cache;
  
	static boolean solve(int[][] board, int x, int y) {
		if(x>=board.length || y>=board.length) {
			return false;
		}
		if(x==(board.length-1)&&y==(board.length-1)) {
			return true;
		}
		if(cache[x][y]==-1){
		  if(solve(board,x+board[x][y],y) || solve(board,x,y+board[x][y])){
			cache[x][y]=1;
			return true;
		  }else{
			cache[x][y]=0;
			return false;
		  }
		}else{
		  if(cache[x][y]==1){
			return true;
		  }else{
			return false;
		  }
		}	
		}
}
