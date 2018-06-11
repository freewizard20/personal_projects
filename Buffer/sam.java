import java.util.*;
import java.io.*;

public class sam{
	public static void main(String[] args)throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		for(int i = 0 ; i < 10000 ; i++){
			String tmp = br.readLine();
			StringTokenizer st = new StringTokenizer(tmp);
			String c1 = st.nextToken();
			String c2 = st.nextToken();
			if(st.hasMoreTokens()) st.nextToken();
			if(c1.equals(c2)) continue;
			else System.out.println(tmp);
		}
		System.out.println("QUIT");
	}
}
