package my;

import java.io.BufferedReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.io.InputStreamReader;

public class most {
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int M = Integer.parseInt(br.readLine());
		for(int z = 0 ; z < M ; z++) {
			int L = Integer.parseInt(br.readLine());
			int[] students = new int[1000];
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int i = 0 ; i < 1000 ; i++) {
				students[i] = Integer.parseInt(st.nextToken());
			}
			int[] points = new int[101];
			Arrays.fill(points, 0);
			for(int i = 0 ; i < 1000 ; i++) {
				points[students[i]]++;
			}
			int ret = 0;
			for(int i = 0 ; i < 101 ; i++) {
				if(points[i]>=points[ret]) {
					ret = i;
				}
			}
			sb.append("#"+(z+1)+" "+ret+"\n");
		}
		System.out.println(sb.toString());
	}
}
