import java.io.IOException;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.StringTokenizer;
import java.io.InputStreamReader;
import java.util.Vector;
import java.util.*;
import java.io.*;

public class parser{
    public static void main(String[] args)throws FileNotFoundException, IOException,UnsupportedEncodingException{
        BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(args[0]),"UTF8"));
        for(int i = 0 ; i < 10000 ; i++){
            String st = br.readLine();
            String st2 = br.readLine();
            if(Integer.parseInt(st2)==0) continue;
            else{
                System.out.println(st);
                System.out.println(st2);
            }
            
        }
    }
}