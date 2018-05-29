package my;
import java.util.Arrays;
import java.util.Vector;

public class recursivapractice {
	public static void main(String[] args) {
		System.out.println(permutation(5,5, new Vector<Integer>()));
		System.out.println(combination(5,4,new Vector<Integer>()));
		int[] sam = new int[4];
		Arrays.fill(sam,0);
		System.out.println(rotation(4,3,sam));
	}
	
	static public int permutation(int n, int r,Vector<Integer> sam) {
	if(r==0) {
		for(int i : sam) {
			System.out.print(i + " ");
		}
		System.out.println();
		return 1;
	}
	int ret = 0;
	for(int i = 0 ; i < n ; i++) {
		if(!sam.contains(i)) {
			sam.add(i);
			ret += permutation(n,r-1,sam);
			sam.remove(sam.size()-1);
		}
	}
	return ret;
		
	}
	
	static public int combination(int n, int r, Vector<Integer>sam) {
		if(r==0) {
			for(int i : sam) {
				System.out.print(i+ " ");
			}
			System.out.println();
			return 1;
		}
		int smallest;
		if(sam.size()==0) {
			smallest = 0;
		}else{
			smallest = sam.lastElement()+1;
		}
		int ret = 0;
		for(int i = smallest ; i < n ; i++) {
			sam.add(i);
			ret += combination(n,r-1,sam);
			sam.remove(sam.size()-1);
		}
		return ret;
	}
	
	static public int rotation(int n, int r, int[] sam) {
		if(n==0) {
			for(int i : sam) {
				System.out.print(i+ " ");
			}
			System.out.println();
			return 1;
		}
		int ret = 0;
		int tmp;
		for(int i = 0 ; i < r ; i++) {
			tmp = sam[n-1];
			sam[n-1]=i;
			ret += rotation(n-1,r,sam);
			sam[n-1]=tmp;
		}
		return ret;
	}
}

