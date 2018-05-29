package my;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Vector;

public class lis {
	
	static int[] board;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int M = Integer.parseInt(br.readLine());
		for(int z = 0 ; z < M ; z++) {
			int N = Integer.parseInt(br.readLine());
			board = new int[N];
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int i = 0 ; i < N ; i++) {
				board[i] = Integer.parseInt(st.nextToken());
			}
			System.out.println(solve2(0,new Vector()));
		}
	}
	
	static int solve(int n, Vector maxar) {
		if(n==board.length) {
			return maxar.size();
		}
		int ret = 0;
		if(maxar.size()==0) {
			maxar.add(board[n]);
			ret = Math.max(ret, solve(n+1,maxar));
		}else if(board[n]>(int)maxar.lastElement()) {
			maxar.add(board[n]);
			ret = Math.max(ret, solve(n+1,maxar));
		}else {
			ret = Math.max(ret, solve(n+1,maxar));
		}
		return ret;
	}
	
	static int solve2(int n,Vector maxar) {
		if(n==board.length) {
			if(islis(maxar)) {
				return maxar.size();
			}else {
				return 0;
			}
		}
		int ret = 0;
		for(int i = 0 ; i < 2 ; i++) {
			if(i==0) {
			ret = Math.max(ret, solve2(n+1,maxar));
			}else {
			maxar.add(board[n]);
			ret = Math.max(ret, solve2(n+1,maxar));
			maxar.remove(maxar.size()-1);
			}
		}
		return ret;
	}
	
	static boolean islis(Vector maxar) {
		boolean ret = true;
		for(int i = 0 ; i < maxar.size();i++) {
			if(i!=maxar.size()-1 && (int)maxar.get(i)>=(int)maxar.get(i+1)) {
				ret = false;
				break;
			}
		}
		return ret;
	}
}
