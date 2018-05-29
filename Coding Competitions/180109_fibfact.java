package my;


public class test {

		public static void main(String[] args) {
				System.out.println(fact(5));
				System.out.println(fib(25));
		}
		
		static int fact(int n) {
			if(n==0) return 1;
			else return n*fact(n-1);
		}
		
		static int fib(int n) {
			if(n<=2)return 1;
			else return fib(n-1)+fib(n-2);
		}
}
