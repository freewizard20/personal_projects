package my;


public class test {
	static public void main(String[] args) {
		int[] sam = {5,4,2,7,5,8,9,4,2,6,7,8,9};
		sam = insertsort(sam);
		for(int i = 0 ; i<sam.length;i++) {
			System.out.print(sam[i]+" ");
		}
	}
	
	static int[] insertsort(int[] sam) {
		for(int i=1;i<sam.length;i++) {
			int key = sam[i];
			int j = i-1;
			while(j>=0 && sam[j]>key) {
				sam[j+1]=sam[j];
				j--;
			}
			sam[j+1]=key;
		}
		
		
		return sam;
	}

}
