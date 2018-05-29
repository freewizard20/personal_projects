package my;

public class testbench{
	public static void main(String[] args) {
		int target = 78;
		System.out.println(Integer.toBinaryString(target));
		System.out.println(tobinary(target));
	}
	
	static String tobinary(int i) {
		StringBuffer sb = new StringBuffer();
		while(i!=1) {
			if(i%2==1) {
				sb.insert(0, 1);
			}else {
				sb.insert(0,0);
			}
			i=i/2;
			if(i==1) {
				sb.insert(0, 1);
			}
		}
		return sb.toString();
	}
}
