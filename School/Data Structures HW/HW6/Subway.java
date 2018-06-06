import java.io.IOException;
import java.io.BufferedReader;
import java.util.StringTokenizer;
import java.io.InputStreamReader;
import java.util.Vector;
import java.util.*;

public class Subway{
    
    public static void main(String[] args){
        // parse data and make graph
        Vector<Vector<Vector<Integer>>> graph;
        HashMap<String,String> numtoname;
        HashMap<String,Integer> nn;
        HashMap<Integer,String> nn2;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // map nodes to graph
        while(true){
            StringTokenizer st = new StringTokenizer(br.readLine());
            // all nodes read. Break.
            int count=0;
            if(st.size()==0) break;
            String num = st.nextToken();
            String name = st.nextToken();
            numtoname.add(num,name);
            nn.add(num,count);
            nn2.add(count,num);
            count++;
            graph.add(new Vector<Vector<Integer>>());
        }

        // add edges to graph
        while(true){
            String curr = br.readLine();
            if(curr==null) break;
            StringTokenizer st = new StringTokenizer(curr);
            String from = st.nextToken();
            String to = st.nextToken();
            int dist = Integer.parseInt(st.nextToken());
            Vector<Integer> edge = new Vector<Integer>();
            edge.add(nn.get(to));
            edge.add(dist);
            graph.get(nn.get(from)).addElement(edge);
        }

        // add bridge nodes and edges

        
        // initialize graph
        db test = new db(graph,
    }
}

class db{
    
    // data structure containing subway information
    private Vector<Vector<Vector<Integer>>> graph;
    private HashMap<String,String> numtoname;
    private HashMap<String,String> nametonum;

    public graph(Vector<Vector<Vector<Integer>>> g, HashMap<String,String> n, HashMap<String,String> s){
        graph = g;
        numtoname = n;
        nametonum = s;
    }
    
    // shortest path
    public void spath(String from, String to){
        
    }

    // shortest transfers
    public void spath2(String from, String to){

    }
    
}