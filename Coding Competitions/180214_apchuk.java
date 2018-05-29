package my;
import java.util.Vector;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;

public class apchuk {
	
	static Vector<String> dict;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int M = Integer.parseInt(br.readLine());
		for(int z = 0 ; z < M ; z++) {
			dict = new Vector<String>();
			for(int i = 0 ; i < 26 ; i++) {
				dict.add(Character.toString((char)(i+65)));
			}
			char[] given = br.readLine().toCharArray();
			Vector<Character> giv = new Vector<Character>();
			for(int i = 0 ; i < given.length ; i++) {
				giv.add(given[i]);
			}
			Vector<Integer> ans = new Vector<Integer>();
			while(giv.size()!=0) {
				int flag=0;
				int pans = 0;
				int currindex = 1;
				String w = Character.toString(giv.get(0));
				pans=search(w);
				while((search(w)!=-1)&&currindex<=giv.size()) {
					pans = search(w);
					if(currindex<giv.size()) {
					w = w + Character.toString(giv.get(currindex));
					}else{
						flag=1;
					}currindex++;
				}
				ans.add(pans);
				if(giv.size()!=1) {
				String c = w;
				if(search(c)==-1) {
					dict.add(c);
				}
				}
				if(w.length()==1) {
					w=w+"d";
				}
				for(int i = 0 ; i < w.length()-1; i++) {
					giv.remove(0);
				}
				if(flag==1) {
					try {
					giv.remove(0);
					}catch(Exception e) {
						
					}
				}
			}
			for(int i = 0 ; i < ans.size();i++) {
				System.out.print(ans.get(i)+" ");
			}
			System.out.println();
		}
	}
	
	static int search(String w) {
		int ret = -1;
		for(int i = 0 ; i < dict.size(); i++) {
			if(dict.get(i).equals(w)) {
				ret = i+1;
			}
		}
		return ret;
	}
}
