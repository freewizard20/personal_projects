package my;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.Arrays;

public class wildcard {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int M = Integer.parseInt(br.readLine());
		for(int z = 0 ; z < M ; z++) {
			String wildcard = br.readLine();
			int N = Integer.parseInt(br.readLine());
			for(int w = 0 ; w < N ; w++) {
				String target = br.readLine();
				if(iswildcard(wildcard,target)) {
					System.out.println(target);
				}
			}
		}
		
	}
	
	static boolean iswildcard(String wildcard,String target) {
		int pos = 0;
		char[] wc = wildcard.toCharArray();
		char[] tc = target.toCharArray();
		while(pos<tc.length && pos < wc.length && (wc[pos] == '?' || wc[pos]==tc[pos])) {
			pos++;
		}
		if(pos== wc.length) {
			return pos==tc.length;
		}
		if(wc[pos]=='*') {
			
			for(int skip = 0; pos+skip < tc.length; skip++) {
				String wt1 = "";
				String tt1 = "";
				for(int i = pos+1,j = 0;i<wc.length;i++,j++) {
					wt1+=wc[i];
				}
				for(int i = pos+skip,j=0;i<tc.length;i++,j++) {
					tt1+=tc[i];
				}
				if(iswildcard(wt1,tt1)) {
					return true;
				}
			}
		}
		return false;
	}
}
