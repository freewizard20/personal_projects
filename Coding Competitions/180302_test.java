package nolza;

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class test {
	
	static int[] students;
	
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int M = Integer.parseInt(br.readLine());
		students = new int[M];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i = 0 ; i < M ; i++) {
			students[i] = Integer.parseInt(st.nextToken());
		}
		StringTokenizer st2 = new StringTokenizer(br.readLine());
		int chong = Integer.parseInt(st2.nextToken());
		int bu = Integer.parseInt(st2.nextToken());
		long total = 0;
		for(int i = 0 ; i < M ; i++) {
			int tmp = 1;
			int tmptot = students[i]-chong;
			while(tmptot>0) {
				tmp++;
				tmptot = tmptot - bu;
			}
			total = total + tmp;
		}
		System.out.println(total);
	}
}
