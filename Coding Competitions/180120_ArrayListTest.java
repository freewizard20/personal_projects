package my;

import java.util.ArrayList;
import java.util.Collections;

public class classtest{
	
	public static void main(String[] args) {
		ArrayList<Integer> sam = new ArrayList<Integer>();
		sam.add(30);
		for (int s : sam) {
			System.out.println(s);
		}
		System.out.println(sam.size());
		sam.add(14);
		sam.add(15);
		System.out.println(sam.get(sam.size()-1));
		Collections.sort(sam);
		for ( int s : sam) {
			System.out.print(" " + s);
		}
		System.out.println();
		sam.add(1, 11);
		for ( int s : sam) {
			System.out.print(" " + s);
		}
	}
	
}
