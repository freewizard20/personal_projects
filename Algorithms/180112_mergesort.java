package my;

public class mergesort {
	static public void main(String[] args) {
		int[] sam = {2,1};//{5,2,3,5,4,7,8,3,4,12,5,86,42,12,55};
		mergesort(sam,0,sam.length-1);
		for(int i = 0 ; i < sam.length ; i++) {
			System.out.print(" " + sam[i]);
		}
	}
	
	static void mergesort(int[] sam,int low, int high) {
		if(low<high) {
		int q = (low+high)/2;
		mergesort(sam,low,q);
		mergesort(sam,q+1,high);
		merge(sam,low,q,high);
		}
	}
	
	static void merge(int[] sam, int low, int q, int high) {
		int n1 = q-low+1;
		int n2 = high-q;
		int[] L = new int[n1];
		int[] R = new int[n2];
		for(int i = 0 ; i < n1 ; i++) {
			L[i] = sam[low+i];
		}
		for(int i = 0 ; i < n2 ; i++) {
			R[i] = sam[q+i+1];
		}
		int tr = 0;
		int tl = 0;
		for(int i = 0 ; i < n1+n2; i++) {
			if(tl<n1 && tr < n2) {
				if(L[tl]>R[tr]) {
					sam[low+i]=R[tr];
					tr++;
					continue;
				}else {
					sam[low+i]=L[tl];
					tl++;
					continue;
				}
			}
			if(tl<n1) {
				sam[low+i]=L[tl];
				tl++;
				continue;
			}
			if(tr<n2) {
				sam[low+i]=R[tr];
				tr++;
			}
		}
	}
	
}
