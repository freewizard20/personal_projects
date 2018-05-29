package my;
import java.util.Scanner;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.Vector;

public class caches {
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int cacheSize = Integer.parseInt(br.readLine());
		String[][] cache = new String[cacheSize][2];
		for(int i = 0 ; i < cacheSize ; i++) {
			cache[i][0]="";
			cache[i][1]="-1";
		}
		Vector<String> list = new Vector<String>();
		StringTokenizer st = new StringTokenizer(br.readLine());
		while(st.hasMoreTokens()) {
			String tmp = st.nextToken();
			String tmp2 = "";
			char[] ss = tmp.toCharArray();
			StringBuffer sb = new StringBuffer();
			for(int i = 0 ; i < ss.length ; i++) {
				if(Character.isLetter(ss[i])) {
					sb.append(Character.toString(Character.toLowerCase(ss[i])));
				}
			}
			list.add(sb.toString());
		}
		int totaltime = 0;
		for(int i = 0 ; i < list.size(); i++) {
			boolean cachehit = false;
			for(int j = 0 ; j < cacheSize ; j++) {
				if(cache[j][0].equals(list.get(i))) {
					cache[j][1] = Integer.toString(i);
					totaltime++;
					cachehit = true;
					break;
				}
			}
			if(cachehit==false) {
				int changecache = 0;
				for(int j = 0 ; j < cacheSize ; j++) {
					if(Integer.parseInt(cache[j][1])<Integer.parseInt(cache[changecache][1])) {
						changecache = j;
					}
				}
				try {
				cache[changecache][0] = list.get(i);
				cache[changecache][1] = Integer.toString(i);
				}catch(Exception e){
					
				}
				totaltime +=5;
			}
		}
		System.out.println(totaltime);
	}
}
