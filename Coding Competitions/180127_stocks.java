package my;

import java.io.BufferedReader;
import java.io.IOException;
import java.util.StringTokenizer;
import java.io.InputStreamReader;


public class stocks {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int M = Integer.parseInt(br.readLine());
		StringBuffer sb = new StringBuffer();
		for(int z = 0 ; z < M ; z++) {
			int N = Integer.parseInt(br.readLine());
			int[] price = new int[N];
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int i = 0 ; i < N ; i++) {
				price[i] = Integer.parseInt(st.nextToken());
			}
			int total = solve(price, 0 , N-1);
			sb.append("#"+(z+1)+" "+total+"\n");
		}
		System.out.println(sb.toString());
	}
	
	static int solve(int[] price, int start , int end) {
		if(start>=end) {
			return 0;
		}
		int maxindex = start;
		for(int i = start ; i <= end ; i++) {
			if(price[maxindex]<=price[i]) {
				maxindex = i;
			}
		}
		int total = 0;
		for(int i = start; i <= maxindex ; i++) {
			total += price[maxindex]-price[i];
		}
		total = total+solve(price,maxindex+1,end);
		return total;
	}
}
