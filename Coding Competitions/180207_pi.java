package my;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class pi {
	
	static int[] piarray;
	static int[] cache;
	
	
	public static void main(String[] main) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int M = Integer.parseInt(br.readLine());
		for(int z = 0 ; z < M ; z++) {
			String tmp = br.readLine();
			char[] tmp2 = tmp.toCharArray();
			piarray = new int[tmp2.length];
			//System.out.println(piarray.length);
			for(int i = 0 ; i < tmp2.length ; i++) {
				piarray[i] = (int) tmp2[i] - 48;
			}
			cache = new int[piarray.length];
			for(int i = 0 ; i < cache.length ; i++) {
				cache[i] = -2;
			}
			System.out.println(solve(0));
		}
	}
	
	static int solve(int n) {
		if(n>=piarray.length-5) {
			return point(n,piarray.length-1);
		}
		int ret = cache[n];
		if(ret!=-2) {
			return ret;
		}
		ret = Math.min(Math.min(point(n,n+2)+solve(n+3), point(n,n+3)+solve(n+4)), point(n,n+4)+solve(n+5));
		cache[n]=ret;
		return ret;
	}
	
	static int point(int a, int b) {
		if(b-a<=1) {
			return 10;
		}
		if(ispointone(a,b)) {
			return 1;
		}else if(ispointtwo(a,b)) {
			return 2;
		}else if(ispointfour(a,b)) {
			return 4;
		}else if(ispointfive(a,b)) {
			return 5;
		}else {
			return 10;
		}
	}
	
	static boolean ispointone(int a, int b) {
		int ref = piarray[a];
		for(int i = a ; i <= b ; i++) {
			if(ref!=piarray[i]) {
				return false;
			}
		}
		return true;
	}
	
	static boolean ispointtwo(int a, int b) {
		boolean ret1 = true;
		for(int i = a ; i < b ; i++ ) {
			if(piarray[i]-piarray[i+1]!=1) {
				ret1 = false;
				break;
			}
		}
		boolean ret2 = true;
		for(int i = a ; i < b ; i++) {
			if(piarray[i]-piarray[i+1]!=-1) {
				ret2 = false;
				break;
			}
		}
		return ret1 || ret2;
	}
	
	static boolean ispointfour(int a , int b) {
		int ref1 = piarray[a];
		int ref2 = piarray[a+1];
		boolean ret = true;
		for(int i = a ; i <= b ; i++) {
			if(a%2==i%2) {
				if(ref1!=piarray[i]) {
					ret = false;
					break;
				}
			}else {
				if(ref2!=piarray[i]) {
					ret = false;
					break;
				}
			}
		}
		return ret;
	}
	
	static boolean ispointfive(int a, int b) {
		int d = piarray[a]-piarray[a+1];
		boolean ret = true;
		for(int i = a ; i < b ; i++) {
			if(piarray[i]-piarray[i+1]!=d) {
				ret = false;
				break;
			}
		}
		return ret;
	}
	
}
