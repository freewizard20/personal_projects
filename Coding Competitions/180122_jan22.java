package my;
import java.util.Arrays;
import java.util.Scanner;

public class jan22 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int M = sc.nextInt();
		for(int z = 0 ; z < M ; z++) {
			int num = sc.nextInt();
			int testcase = sc.nextInt();
			boolean [][] areFriends = new boolean [num][num];
			for(int i = 0 ; i < num ; i++) {
				for(int j = 0 ; j < num ; j++) {
					areFriends[i][j]=false;
				}
			}
			
			for(int i = 0 ; i < testcase; i++) {
				int a = sc.nextInt();
				int b = sc.nextInt();
				areFriends[a][b]=true;
				areFriends[b][a]=true;
			}
			boolean[] taken = new boolean[num];
			Arrays.fill(taken, false);
			System.out.println(countParings(num,taken,areFriends));
		}
	}
	
	static int countParings(int n, boolean[] taken, boolean[][] areFriends) {
		boolean finished = true;
		for(int i = 0 ; i < n; i++) {
			if(!taken[i]) {
				finished = false;
			}
		}
		if(finished) {
			return 1;
		}
		int smallest = 0;
		for(int i = 0 ; i <n ; i++) {
			if(!taken[i]) {
				smallest = i;
				break;
			}
		}
		
		int ret = 0;
		
		for(int i = smallest ; i < n ; ++i) {
			for(int j = i+1 ; j < n ; ++j) {
				if(!taken[i]&&!taken[j]&&areFriends[i][j]) {
					taken[i]=true;
					taken[j]=true;
					ret += countParings(n,taken,areFriends);
					taken[i]=false;
					taken[j]=false;
				}
			}
		}
		return ret;
	}
	
	static int factorial(int n) {
		if(n<=1) {
			return 1;
		}else {
			return n*factorial(n-1);
		}
	}
	
	static int countParings2(int n, boolean[] taken, boolean[][] areFriends ) {
		boolean finished = true;
		int smallest = 0;
		for(int i = 0 ; i < n ; i++) {
			if(!taken[i]) {
				finished = false;
				smallest = i;
				break;
			}
		}
		if(finished) {
			return 1;
		}
		int ret = 0;
		for(int i = smallest+1 ; i < n ; ++i) {
			if(!taken[i]&&areFriends[smallest][i]) {
				taken[smallest] = taken[i] = true;
				ret += countParings2(n,taken,areFriends);
				taken[smallest] = taken[i] = false;
			}
		}
		return ret;
	}
}
