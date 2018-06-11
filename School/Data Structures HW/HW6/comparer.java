import java.io.IOException;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.StringTokenizer;
import java.io.InputStreamReader;
import java.util.Vector;
import java.util.*;
import java.io.*;

public class comparer{
    public static void main(String[] args)throws FileNotFoundException, IOException,UnsupportedEncodingException{
        BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(args[0]),"UTF8"));
        BufferedReader br2 = new BufferedReader(new InputStreamReader(new FileInputStream(args[1]),"UTF8"));
        int i = 0;
        while(true){
            try{
            String x = br.readLine();
            if(x==null) return;
            br2.readLine();
            int curr1 = Integer.parseInt(br.readLine());
            int curr2 = Integer.parseInt(br2.readLine());
            if(curr1!=curr2) System.out.println("Error on " + i);
            i++;
            }catch(Exception e){
                System.out.println(i);
                System.out.println(e);
                return;
            }
        }
    }
}