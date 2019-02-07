package my;

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class password{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int M = Integer.parseInt(br.readLine());
        for(int z = 0 ; z < M ; z++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int lines = Integer.parseInt(st.nextToken());
            int numbers = Integer.parseInt(st.nextToken());
            char[] code = new char[1000];
            int flag = 0;
            for(int i = 0 ; i < lines ; i++){
                char[] tmp = br.readLine().toCharArray();
                for(int j = 0 ; j < numbers ; j++){
                    if(tmp[j]=='1'&&flag==0){
                        flag=1;
                        code=tmp;
                        break;
                    }
                }
            }
            int index=0;
            for(int i = numbers-1;i>=0;i--){
                if(code[i]=='1'){
                    index=i;
                    break;
                }
            }
            int[] ans = new int[8];
            for(int i = 8 ; i >0 ; i--){
                StringBuffer sb = new StringBuffer();
                for(int j = 0 ; j < 7 ; j++){
                    sb.append(code[index-i*7+1+j]);
                }
                ans[8-i]=decoder(sb.toString());
            }
            int test = 3*(ans[0]+ans[2]+ans[4]+ans[6])+ans[1]+ans[3]+ans[5]+ans[7];
            if(test%10==0){
                int tot = 0;
                for(int i = 0 ; i <8 ; i++){
                    tot+=ans[i];
                }
                System.out.println("#"+(z+1)+" "+tot);
            }else{
                System.out.println("#"+(z+1)+" "+0);
            }
          }
    }
    
    static int decoder(String num){
    	switch(num){
            case "0001101":
                return 0;
            case "0011001":
                return 1;
            case "0010011":
                return 2;
            case "0111101":
                return 3;
            case "0100011":
                return 4;
            case "0110001":
                return 5;
            case "0101111":
                return 6;
            case "0111011":
                return 7;
            case "0110111":
                return 8;
            case "0001011":
                return 9;
        }
        return -9999;
    }
    
    
    }

            
