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
		for(int i = 0 ; i < sam.length; i++) {
			for(int j=i-1;j>=0;j--) {
				if(sam[j]<=sam[j+1]) {
					break;
				}else {
					int tmp;
					tmp = sam[j+1];
					sam[j+1]=sam[j];
					sam[j]=tmp;
				}
			}
		}
		
		
		return sam;
	}

}

