package my;
import java.util.Scanner;
import java.util.Vector;

public class shortestpath {
		static int[][] dist;
	
	
		public static void main(String[] args) {
			Scanner sc = new Scanner(System.in);
			int N = sc.nextInt();
			dist = new int[N][N];
			for(int i = 0 ; i < N ; i++) {
				for(int j = i ; j < N ; j++) {
					if(j==i) dist[i][i] = 0;
					dist[i][j] = (int) Math.floor(Math.random()*N);
					dist[j][i] = dist[i][j];
				}
			}
			
			
			System.out.println(mindist(new Vector<Integer>(), N));
		}
		
		static int mindist(Vector<Integer> sam, int n) {
			if(n==0) {
				int tmp = 0;
				for(int i = 0 ; i < sam.size()-1; i++) {
					tmp+= dist[i][i+1];
				}
				return tmp;
			}
			int md = 99999999;
			for(int i = 0 ; i < dist.length; i++) {
				if(!sam.contains(i)) {
				sam.add(i);
				md = Math.min(md, mindist(sam,n-1));
				
			}
		}
			return md;
		}
}
