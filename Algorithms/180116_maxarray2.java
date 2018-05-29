package my;

public class maxarray {
	public static void main(String[] args) {
		int[] ex = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
		int[] res = new int[3];
		res = maxarray3(ex,0,ex.length-1);
		for(int i = res[0];i<=res[1];i++) {
			System.out.print(" " + ex[i]);
		}
		System.out.println();
		System.out.println("total : " + res[2]);
	}
	
	static int[] maxarray3(int[] sam, int low, int high) {
		int[] res = new int[3];
		if(high == low) {
			res[0]=low;
			res[1]=high;
			res[2]=sam[low];
			return res;
		}else {
			int[] resl = new int[3];
			int[] resr = new int[3];
			int[] resx = new int[3];
			int mid = (low+high)/2;
			resl = maxarray3(sam,low,mid);
			resr = maxarray3(sam,mid+1,high);
			resx = cross(sam,low,mid,high);
			if(resl[2]>resr[2]&&resl[2]>resx[2]) {
				return resl;
			}else if(resr[2]>resl[2]&&resr[2]>resx[2]) {
				return resr;
			}else {
				return resx;
			}
		}
	}
	
	static int[] cross(int[] sam, int low, int mid, int high) {
		int [] res = new int[3];
		int leftSum = -99989;
		int sum = 0;
		int maxLeft = 0,maxRight = 0;
		for(int i = mid; i >=low; i--) {
			sum = sum+sam[i];
			if(sum>leftSum) {
				leftSum = sum;
				maxLeft=i;
			}
		}
		int rightSum = -99989;
		sum = 0;
		for(int i = mid+1 ; i <=high;i++ ) {
			sum = sum + sam[i];
			if(sum>rightSum) {
				rightSum = sum;
				maxRight = i;
			}
		}
		res[0]=maxLeft;
		res[1] = maxRight;
		res[2] = leftSum+rightSum;
		return res;
	}
}

