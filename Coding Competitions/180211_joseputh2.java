package my;

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Arrays;

public class josephus {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int M = Integer.parseInt(br.readLine());
		for(int z = 0 ; z < M ; z++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int N = Integer.parseInt(st.nextToken());
			int K = Integer.parseInt(st.nextToken());
			int [] arr = new int[N];
			Arrays.fill(arr, 1);
			int count = N;
			int index = K-1;
			int current = 0;
			while(count!=2) {
				if(index==K-1&&arr[current]==1) {
					arr[current]=0;
					count--;
					index = 0;
				}
				if(arr[current]==1) {
					index++;
				}
				current++;
				current = current%N;
			}
			for(int i = 0 ; i < N ; i++) {
				if(arr[i]==1) {
					System.out.print((i+1)+" ");
				}
			}
			System.out.println();
		}
	}
}
