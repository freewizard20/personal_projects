package my;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class gangnam {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuffer sb = new StringBuffer();
		for(int z = 0 ; z < 10 ; z++) {
			int N = Integer.parseInt(br.readLine());
			StringTokenizer st = new StringTokenizer(br.readLine());
			int[] buildings = new int[N];
			for(int i = 0 ; i < N ; i++) {
				buildings[i] = Integer.parseInt(st.nextToken());
			}
			int h = solve(buildings);
			sb.append("#"+(z+1)+" "+h+"\n");
		}
		System.out.println(sb.toString());
	}
	
	static int solve(int[] buildings) {
		int total = 0;
		for(int i = 2 ; i < buildings.length-2 ; i++) {
			total += views(buildings,i);
		}
		return total;
	}
	
	static int views(int[] buildings, int i) {
		int leftview = Math.min(buildings[i]-buildings[i-1], buildings[i]-buildings[i-2]);
		int rightview = Math.min(buildings[i]-buildings[i+1], buildings[i]-buildings[i+2]);
		int total = Math.min(leftview, rightview);
		if(total>=0) {
			return total;
		}else {
			return 0;
		}
	}
}
