package nolza;

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Vector;

public class packing {
	
	static int [][] cache;
	static String[] names;
	static int[] weights;
	static int[] points;
	static Vector<String> totake;
	static int W;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int M = Integer.parseInt(br.readLine());
		for(int z = 0 ; z < M ; z++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int N = Integer.parseInt(st.nextToken());
			W = Integer.parseInt(st.nextToken());
			names = new String[N];
			weights = new int[N];
			points = new int[N];
			for(int i = 0 ; i < N ; i++) {
				StringTokenizer st2 = new StringTokenizer(br.readLine());
				names[i] = st2.nextToken();
				weights[i] = Integer.parseInt(st2.nextToken());
				points[i] = Integer.parseInt(st2.nextToken());
			}
			cache = new int[1001][100];
			for(int i = 0 ; i < 1001 ; i++) {
				for(int j = 0 ; j < 100 ; j++) {
					cache[i][j] = -1;
				}
			}
			totake = new Vector<String>();
			int max = solve(W,0);
			remake(W,0);
			System.out.println(max+" "+totake.size());
			for(int i = 0 ; i < totake.size();i++) {
				System.out.println(totake.get(i));
			}
		}
	}
		
	static int solve(int Weight, int n) {
		if(n==names.length) {
			return 0;
		}
		int ret = cache[Weight][n];
		if(ret!=-1) {
			return ret;
		}
		ret = solve(Weight,n+1);
		if(Weight>=weights[n]) {
			ret = Math.max(ret, solve(Weight-weights[n],n+1)+points[n]);
		}
		return ret;
	}
	
	static void remake(int cap, int n) {
		if(n==names.length) {
			return;
		}
		
		if(solve(cap,n)==solve(cap,n+1)) {
			remake(cap,n+1);
		}else {
			totake.add(names[n]);
			remake(cap-weights[n],n+1);
		}
	}
}
