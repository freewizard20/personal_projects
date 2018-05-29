package my;

import java.util.Scanner;
import java.util.Vector;

public class jinsu {
	
	static int[] calculated;
	static int n;
	static int t;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		t = sc.nextInt();
		int m = sc.nextInt();
		int p = sc.nextInt();
		calculated = new int[m*t];
		fill();
		StringBuffer sb = new StringBuffer();
		int i = 0;
		while(sb.length()!=t) {
			switch(calculated[i*m+p-1]) {
			case 10:
				sb.append('A');
				break;
			case 11:
				sb.append('B');
				break;
			case 12:
				sb.append('C');
				break;
			case 13:
				sb.append('D');
				break;
			case 14:
				sb.append('E');
				break;
			case 15:
				sb.append('F');
				break;
			default:
				sb.append(calculated[i*m+p-1]);
				break;
			}
			i++;
		}
		System.out.println(sb.toString());
	}
	
	static void fill() {
		int curr = 0;
		int nextint = 0;
		Vector buffer = new Vector();
		while(curr < calculated.length) {
			buffer = fillbuffer(nextint);
			int ln = buffer.size();
			for(int i = 0 ; i < ln ; i++) {
				try {
					calculated[curr] = (int) buffer.get(i);
				}catch(Exception e) {
					
				}
				curr++;
			}
			nextint++;
		}
	}
	
	static Vector fillbuffer(int target) {
		Vector tmp = new Vector();
		if(target==0) {
			tmp.add(0);
		}
		while(target != 0) {
			tmp.add(target%n);
			target = target/n;
		}
		Vector tmp2 = new Vector();
		for(int i = tmp.size()-1; i >=0; i--) {
			tmp2.add(tmp.get(i));
		}
		return tmp2;
	}
}
