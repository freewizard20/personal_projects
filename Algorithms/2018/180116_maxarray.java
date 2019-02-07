package my;

public class maxarray {
	public static void main(String[] args) {
		int[] ex = {13,7,12,4,3,8,12,3,11,19,8,3,12,13};
		int[] res = new int[2];
		res = maxarray2(ex);
		for(int i = res[0]; i <= res[1];i++) {
			System.out.print(" "+ex[i]);
		}
	}
	
	static int[] maxarray2(int[] ex) {
		int[] res = new int[2];
		int tot = 0;
		for(int i = 0 ; i < ex.length;i++) {
			for(int j = 0;j<i;j++) {
				if(ex[i]-ex[j]>tot) {
					tot=ex[i]-ex[j];
					res[0]=j;
					res[1]=i;
				}
			}
		}
		
		
		
		return res;
	}
}
