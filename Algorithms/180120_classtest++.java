package my;

import java.time.*;

public class classtest{
	public static void main(String[] args) {
		func1();
		func3(4,100);
		func4(4,100);
		//System.out.println(factorial(100));
	}
	
	static void func1() {
		int count = 0;
		for(int i = 0 ; i < 10 ; i++) {
			for(int j = 0 ; j < 10 ; j ++) {
				for(int k = 0 ; k < 10 ; k ++) {
					for(int l = 0 ; l < 10 ; l++) {
						if(i!=j && j!=k && k!=l && i!=k && i!=l && j!=l) {
							//System.out.println(i + " " + j + " " + k + " " +l);
							count++;
						}
					}
				}
			}
		}
		System.out.println("total : " + count);
	}
	
	static void func2() {
		int count = 0;
		for(int i = 0 ; i < 10 ; i++) {
			for(int j = 0 ; j < 10 ; j++) {
				if(j!=i) {
					for(int k = 0 ; k < 10 ; k++) {
						if(k!=j && k!=i) {
							for(int l = 0 ; l < 10 ; l++) {
								if(l!=k && l!=j && l!=i) {
									//System.out.println(i + " " + j + " " + k + " " + l);
									count++;
								}
							}
						}
					}
				}
			}
		}
		System.out.println("total : " + count);
	}
	
	static void func3(int pick, int total) {
		int[] su = new int[pick];
		long count = 0;
		for(int i = 0 ; i < su.length; i++) {
			su[i]=0;
		}
		while(haslast(su,total)!=true) {
			su[su.length-1]++;
			for(int i = su.length-1 ; i >=0 ; i--){
				if(su[i]==total) {
					su[i]=0;
					su[i-1]++;
				}
			}
			if(hassame(su)==false) {
				count++;
			}
			}
		System.out.println(count);
			
	}
	
	static boolean haslast(int[] su, int total) {
		for(int i = total-1, j = 0; i > total-su.length-1; i--,j++) {
			if(su[j]!=i) {
				return false;
			}
		}
		return true;
	}
	
	static boolean hassame(int[] su) {
		for(int i = 0 ; i < su.length;i++) {
			for(int j = 0 ; j < su.length;j++) {
				if(i!=j && su[i]==su[j]) {
					return true;
				}
			}
		}
		return false;
	}
	
	static void func4(int pick, int total) {
		long tot = 1;
		for(int i = total;i>total-pick;i--) {
			tot = tot * i;
		}
		System.out.println(tot);
	}
	

}
