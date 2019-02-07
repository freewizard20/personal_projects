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
			Vector vboard = new Vector();
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int i = 0 ; i < N ; i++) {
				board[i] = Integer.parseInt(st.nextToken());
				vboard.add(board[i]);
			}
			cache = new int[N];
			for(int i = 0 ; i < N ; i++) {
				cache[i] = -1;
			}
			//System.out.println(solve2(0,new Vector()));
			//System.out.println(solve3(vboard));
			for(int i = 0 ; i < N ; i++) {
				solve4(N-i-1);
			}
			int ret = 0;
			for(int i = 0 ; i < N ; i++) {
				if(cache[i]>ret) {
					ret = cache[i];
				}
			}
			System.out.println(ret);
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
	
	static int solve3(Vector vboard) {
		if(vboard.size()==0) {
			return 0;
		}
		int ret = 0;
		for(int i = 0 ; i < vboard.size(); i++) {
			Vector b = new Vector();
			for(int j = i+1; j<vboard.size(); j++) {
				if((int)vboard.get(i)<(int)vboard.get(j)) {
					b.add(vboard.get(j));
				}
			}
			ret = Math.max(ret,  1+solve3(b));
		}
		return ret;
	}
	
	static int [] cache;
	
	static int solve4(int start) {
		int ret = cache[start];
		if(ret!=-1) {
			return ret;
		}
		ret = 1;
		for(int next = start+1; next<board.length;next++) {
			if(board[start]<board[next]) {
				ret = Math.max(ret,  solve4(next)+1);
			}
		}
		cache[start]=ret;
		return ret;
	}
}
