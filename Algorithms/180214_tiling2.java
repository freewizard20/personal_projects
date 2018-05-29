package my;

import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.util.Arrays;

public class tiling2 {
	static int mod = 1000000007;
	static int[] cache;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int M = Integer.parseInt(br.readLine());
		for(int z = 0 ; z < M ; z++) {
			int N = Integer.parseInt(br.readLine());
			cache = new int[100];
			Arrays.fill(cache, -1);
			cache[0]=1;
			cache[1]=2;
			fillcache();
			System.out.println(solve(N));
		}
	}
	
	static void fillcache() {
		for(int i = 2 ; i < 100 ; i++) {
			cache[i] = (cache[i-1]+cache[i-2])%mod;
		}
	}
	
	static int solve(int n) {
		int ret = cache[n-1];
		if(ret!=-1) {
			return ret;
		}
		ret = (solve(n-1)+solve(n-2))%mod;
		return ret;
	}
}
