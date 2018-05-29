package my;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class testbench {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int M = Integer.parseInt(br.readLine());
		for(int z = 0 ; z < M ; z++) {
			int N = Integer.parseInt(br.readLine());
			int[][] array = new int[N][N];
			for(int i = 0 ; i < N ; i++) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				for(int j = 0 ; j < N ; j++) {
					array[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			for(int i = 0 ; i < array.length ; i++) {
				for(int j = 0 ; j < array.length ; j++) {
					System.out.print(array[i][j]);
				}
				System.out.println();
			}
		}
	}
}
