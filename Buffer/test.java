import java.io.*;
import java.util.*;

public class test{
	public static void main(String[] args) throws UnsupportedEncodingException, IOException, FileNotFoundException{
	BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(args[0]),"MS949"));
	while(true){
		String curr = br.readLine();
		if(curr.length()==0) return;
		System.out.println(curr);
	}
	}
}
