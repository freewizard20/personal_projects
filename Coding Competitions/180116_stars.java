package my;

import java.util.Scanner;

public class friends {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int s1 = sc.nextInt();
		int s2 = sc.nextInt();
		for(int i = 0 ; i < s1 ; i++) {
			for(int j = 0 ; j < s2 ; j++) {
				System.out.print("*");
			}
			System.out.println("");
		}
	}
}
