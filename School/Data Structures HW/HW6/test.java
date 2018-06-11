import java.io.*;
import java.util.*;

public class test{
	public static void main(String[] args)throws IOException, UnsupportedEncodingException, FileNotFoundException{
		BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(args[0]),"UTF8"));
		HashMap<String,String> tmp = new HashMap<String,String>();
		while(true){
			String curr = br.readLine();
			if(curr.length()==0) break;
			StringTokenizer st = new StringTokenizer(curr);
			st.nextToken();
			String x = st.nextToken();
			tmp.put(x,"asd");
			st.nextToken();
		}
		Vector<String> tmp2 = new Vector<String>();
		Set entryset = tmp.entrySet();
		Iterator it = entryset.iterator();
		while(it.hasNext()){
			Map.Entry me = (Map.Entry) it.next();
			tmp2.addElement((String)me.getKey());
		}
		for(int i = 0 ; i < 10000 ; i++){
			int sam = ((int)(Math.random() * 123123123))%tmp2.size();
			int sam2 = ((int)(Math.random()*123123123))%tmp2.size();
			if(Math.random()>0.5)System.out.println(tmp2.get(sam)+" " +tmp2.get(sam2));
			else System.out.println(tmp2.get(sam)+" " + tmp2.get(sam2)+" !");
		}
	}
}
		
