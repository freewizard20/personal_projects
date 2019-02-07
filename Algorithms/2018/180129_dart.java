package my;
import java.util.Scanner;
import java.util.StringTokenizer;

public class dart {
	public static void main(String[] args) {
		int[] result = new int[3];
		int[][] input = new int[3][3];
		Scanner sc = new Scanner(System.in);
		String in = sc.next();
		char[] in2 = in.toCharArray();
		int sep = 0;
		for(int i = 0 ; i < in2.length ; i++){
				if(in2[i]=='T'||in2[i]=='D'||in2[i]=='S') {
					if(in2[i]=='T') {
						input[sep][1] = 3;
					}else if(in2[i]=='D') {
						input[sep][1] = 2;
					}else {
						input[sep][1] = 1;
					}
					StringBuffer sb = new StringBuffer();
					int t = i-1;
					try {
					while(t>=0&&Character.isDigit(in2[t])) {
						sb.insert(0,Character.toString(in2[t]));
						t--;
					}
					}catch(Exception e) {
						
					}
					input[sep][0] = Integer.parseInt(sb.toString());
					try {
					if(in2[i+1]=='#') {
						input[sep][2]=-1;
					}else if(in2[i+1]=='*') {
						input[sep][2]=2;
					}else {
						input[sep][2]=1;
					}
					} catch(Exception e) {
						input[sep][2]=1;
					}
					sep++;
				}
		}

		int [] ans = new int[3];
		for(int i = 0 ; i < 3; i++) {
			if(i<2&&input[i+1][2]==2) {
				
				ans[i] = (int)Math.pow(input[i][0],input[i][1])*input[i][2] * 2;
				
			}else {
				
				ans[i] = (int)Math.pow(input[i][0],input[i][1])*input[i][2];
				
			}
		}
		System.out.println(ans[0]+ans[1]+ans[2]);
	}
}
