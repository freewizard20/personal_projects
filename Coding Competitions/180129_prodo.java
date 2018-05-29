package my;
import java.util.Scanner;

public class prodo {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] map = new int[N];
		for(int i = 0 ; i < N ; i++) {
			map[i] = sc.nextInt();
		}
		int[] map2 = new int[N];
		for(int i = 0 ; i < N ; i++) {
			map2[i]=sc.nextInt();
		}
		int[] map3 = new int[N];
		for(int i = 0 ; i < N ; i++) {
			map3[i] = map[i]|map2[i];
		}
		String[] map4 = new String[N];
		for(int i = 0 ; i < N ; i++) {
			StringBuffer sb = new StringBuffer();
			String tmp = Integer.toBinaryString(map3[i]);
			System.out.println(tmp);
			int T = tmp.length();
			for(int j = 0 ; j < N-T ; j++) {
				sb.append("0");
			}
			sb.append(tmp);
			char[] ss = sb.toString().toCharArray();
			StringBuffer sb2 = new StringBuffer();
			for(int j = 0 ; j < N ; j++) {
				if(ss[j]=='0') {
					sb2.append(" ");
				}else {
					sb2.append("#");
				}
			}
			map4[i] = sb2.toString();
		}
		for(int i = 0 ; i < N ; i++) {
			System.out.print(map4[i]+"/");
		}
	}
}
