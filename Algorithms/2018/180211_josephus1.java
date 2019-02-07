package my;

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Queue;
import java.util.LinkedList;

public class josephus {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int M = Integer.parseInt(br.readLine());
		for(int z = 0 ; z < M ; z++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int N = Integer.parseInt(st.nextToken());
			int K = Integer.parseInt(st.nextToken());
			Queue<Integer> cu = new LinkedList<Integer>();
			for(int i = 1 ; i <= N ; i++) {
				cu.add(i);
			}
			int count = K-1;
			while(cu.size()>2) {
				if(count==K-1) {
					count = 0;
					cu.remove();
				}
				count++;
				cu.add(cu.remove());
			}
			int a = cu.remove();
			int b = cu.remove();
			if(a>=b) {
				System.out.println(b+" "+ a);
			}else {
				System.out.println(a + " " + b);
			}
		}
	}
}
