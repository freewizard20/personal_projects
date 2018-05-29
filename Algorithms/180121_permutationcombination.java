package my;
import java.util.Vector;

public class taeWook {
	public static void main(String[] args) {
		//System.out.println(combination(10,6));
		System.out.println(permutation(10,6,new Vector<Integer>()));
		
		System.out.println(permutation(10,6));
		
	}
	
	static void pickfrom(int num, Vector<Integer> sam, int toPick) {
		if(toPick == 0 ) {
			for(int i : sam) {
				System.out.print(i+" ");
			}
			System.out.println();
			return;
		}else {
			int smallest;
			if(sam.isEmpty()) {
				smallest = 0;
			}else {
				smallest = sam.lastElement()+1;
			}
			for(int i = smallest ; i < num; i++) {
				sam.add(i);
				pickfrom(num,sam,toPick-1);
				sam.remove(sam.size()-1);
			}
		}
	}
	
	static // n개(짝수)를 2개씩 짝짓는 경우의 수
	
	int combination(int n, int r) {
		int count = 1;
		for(int i = n,j=1;i>n-r;i--,j++) {
			count = count*i/j;
		}
		return count;
	}
	
	static int permutation(int n, int r) {
		return factorial(n)/factorial(n-r);
	}
	
	static int pick2one(int n) {
		int total=1;
		for(int i = n ; i > 0 ; i = i - 2) {
			total = total*combination(i,2);
		}
		return total;
	}
	
	static int factorial(int n) {
		if(n<=1) {
			return 1;
		}else {
			return factorial(n-1)*n;
		}
	}
	
	static int pick2two(int n) {
		int two = 1;
		for(int i = 0 ; i < n/2; i++) {
			two = two*2;
		}
		return factorial(n)/two;
	}
	
	static int permutation(int n, int r, Vector<Integer> sam) {
		if(r==0) {
			return 1;
		}else {
			int count = 0;
			for(int i = 0;i<n;i++) {
				if(!sam.contains(i)) {
					sam.add(i);
					count = count + permutation(n,r-1,sam);
					sam.remove(sam.size()-1);
				}
			}
			return count;
		}
	}
	
	static int combination(Vector<Integer>sam,int n, int r) {
		if(r==0) {
			
			return 1;
		}else {
			int count = 0;
			int smaller;
			if(sam.size()==0) {
				smaller = 0;
			}else {
				smaller = sam.lastElement()+1;
			}
			for(int i = smaller;i<n;i++) {
				sam.add(i);
				combination(sam,n,r-1);
				sam.remove(sam.size()-1);
			}
			return count;
		}
	}
	
	static int count = 0;
	static void mux(int n,int count2) {
		if(count2==0) {
			count++;
			return;
		}else {
			for(int i = 0 ; i < n ; i++) {
				mux(n,count2-1);
			}
		}
	}
	
	

}
