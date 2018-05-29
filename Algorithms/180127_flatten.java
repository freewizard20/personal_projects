import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.Arrays;

public class Solution{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuffer sb = new StringBuffer();
        for(int z = 0 ; z < 10 ; z++){
            int times = Integer.parseInt(br.readLine());
            int[] blocks = new int[100];
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int i = 0; i < 100; i++){
                blocks[i] =Integer.parseInt(st.nextToken());
            }
            int ret = solve(blocks,times);
            sb.append("#"+(z+1)+ " " + ret + "\n");
        }
        System.out.println(sb.toString());
    }
    
    static int solve(int[] blocks, int times){
        for(int i = 0 ; i < times ; i++){
            blocks = work(blocks);
        }
        Arrays.sort(blocks);
        int max = blocks[99];
        int min = blocks[0];
        return max-min;
    }
    
    static int[] work(int[] blocks){
        int max = 0;
        for(int i = 0 ; i < blocks.length ; i++){
            if(blocks[i]>=blocks[max]){
                max = i;
            }
        }
        int min = 0;
        for(int i = 0 ; i < blocks.length ; i++){
            if(blocks[i]<=blocks[min]){
                min = i;
            }
        }
        blocks[max]--;
        blocks[min]++;
        return blocks;
    }
}
