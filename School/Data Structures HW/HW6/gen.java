import java.util.*;
import java.io.*;

public class gen{
    public static void main(String[] args) throws FileNotFoundException, IOException,UnsupportedEncodingException{
        //PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(args[0]),"UTF8"));
        HashMap<Integer,String> tmp = new HashMap<Integer,String>();
        int count=0;
        while(true){
            String curr = br.readLine();
            if(curr.length()==0) break;
            StringTokenizer st = new StringTokenizer(curr);
            st.nextToken();
            tmp.put(count,st.nextToken());
            st.nextToken();
            count++;
        }

        for(int i = 0 ; i < Integer.parseInt(args[1]) ; i++){
            int a = ((int)(Math.random()*10000))%tmp.size();
            int b = ((int)(Math.random()*10000))%tmp.size();
            String c = tmp.get(a);
            String d = tmp.get(b);
            if(Math.random()<0.8){
                System.out.println(c + " " + d);
            }else{
                System.out.println(c + " " + d + " !");
            }
        }
        System.out.println("QUIT");
    }
}
