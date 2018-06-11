import java.io.IOException;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.StringTokenizer;
import java.io.InputStreamReader;
import java.util.Vector;
import java.util.*;
import java.io.*;

public class Subway{
    
    public static void main(String[] args) throws FileNotFoundException, IOException,UnsupportedEncodingException {
        // parse data and make graph
        Vector<Vector<Vector<Integer>>> graph = new Vector<Vector<Vector<Integer>>>();
        HashMap<String,String> numtoname = new HashMap<String,String>();
        HashMap<String,Integer> nametograph = new HashMap<String,Integer>();
        HashMap<String,Integer> numtograph = new HashMap<String,Integer>();
        HashMap<Integer,String> graphtonum = new HashMap<Integer,String>();
        HashMap<Integer,String> graphtoname = new HashMap<Integer,String>();
        HashMap<String, Vector<String>> transfer = new HashMap<String,Vector<String>>();
        HashMap<String, Integer> transfernode = new HashMap<String,Integer>();
        HashMap<String, String> names = new HashMap<String,String>();
        BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(args[0]),"UTF8"));
        int count=0;
        // map nodes to graph
        while(true){

            StringTokenizer st = new StringTokenizer(br.readLine());

            // all nodes read. Break.
            if(!st.hasMoreTokens()) break;

            // add new node
            String num = st.nextToken();
            String name = st.nextToken();

            numtoname.put(num,name);
            numtograph.put(num,count);
            nametograph.put(name,count);
            graphtonum.put(count,num);
            graphtoname.put(count,name);
            count++;
            graph.add(new Vector<Vector<Integer>>());

            // if same name found, mark as transfer
            if(names.get(name)!=null){
                if(transfer.get(name)==null){
                    transfer.put(name,new Vector<String>());
                    transfer.get(name).addElement(names.get(name));
                    transfer.get(name).addElement(num);
                }else{
                    transfer.get(name).addElement(num);
                }
            }else{
                names.put(name,num);
            }

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
            edge.add(numtograph.get(to));
            edge.add(dist);
            graph.get(numtograph.get(from)).addElement(edge);
        }

        // add bridge nodes and edges
        Set entrySet = transfer.entrySet();
        Iterator it = entrySet.iterator();
        while(it.hasNext()){
            Map.Entry me = (Map.Entry) it.next();
            Vector<String> come = (Vector<String>) me.getValue();
            graphtoname.put(count,(String)me.getKey());
            transfernode.put((String) me.getKey(),count);
            
            // make new transfer bridge node
            graph.addElement(new Vector<Vector<Integer>>());

            // add edges with transfer bridge node
            for(int i = 0 ; i < come.size() ; i++){
                Vector<Integer> tmp = new Vector<Integer>();
                tmp.addElement(numtograph.get(come.get(i)));
                tmp.addElement(2);
                graph.get(count).addElement(tmp);
                tmp = new Vector<Integer>();
                tmp.addElement(count);
                tmp.addElement(3);
                graph.get(numtograph.get(come.get(i))).addElement(tmp);
            }
            count++;
        }
        
        // initialize graph
        db test = new db(graph,graphtoname, transfernode,nametograph);

        // Do console work
        br = new BufferedReader(new InputStreamReader(System.in));

        while(true){
            String curr = br.readLine();
            if(curr.equals("QUIT")) break;
            StringTokenizer st = new StringTokenizer(curr);
            String f = st.nextToken();
            String t = st.nextToken();
            if(!st.hasMoreTokens()){
                test.spath(f,t);
            }else{
                st.nextToken();
                test.spath2(f,t);
            }
        }
    }
}

class db{
    
    // data structure containing subway information
    private Vector<Vector<Vector<Integer>>> graph;
    private HashMap<Integer,String> graphtoname;
    private HashMap<String,Integer> transfernode;
    private HashMap<String,Integer> nametograph;

    public db(Vector<Vector<Vector<Integer>>> g, HashMap<Integer,String> t, HashMap<String,Integer> m, HashMap<String,Integer> n){
        graph = g;
        graphtoname = t;
        transfernode = m;
        nametograph = n;
    }
    
    // shortest path
    public void spath(String from, String to) throws UnsupportedEncodingException{
        if(from.equals(to)){
            System.out.println(from);
            System.out.println(0);
            return;
        }
        // initialize dist array
        int[] dist = new int[graph.size()];
        int[] prev = new int[graph.size()];
        for(int i = 0 ; i < dist.length ; i++) {
            dist[i] = 999999999;
            prev[i] = 999999999;
        }

        // check if start or end is transfer station
        int tsflag = 0;
        int tfflag = 0;
        int start,end;
        if(transfernode.get(from)!=null){
            tsflag = 1;
            start = transfernode.get(from);
        }else{
            start = nametograph.get(from);
        }
        if(transfernode.get(to)!=null){
            tfflag = 1;
            end = transfernode.get(to);
        }else{
            end = nametograph.get(to);
        }

        // do dijkstra
        dist[start] = 0;
        Queue<Vector<Integer>> pq = new PriorityQueue<Vector<Integer>>(mycomp);
        Vector<Integer> curr = new Vector<Integer>();
        curr.add(0);
        curr.add(start);
        pq.add(curr);
        while(pq.size()!=0){
            curr = pq.poll();
            int at = curr.get(1);
            if(dist[at] < curr.get(0)) continue;
            for(int i = 0 ; i < graph.get(at).size() ; i++){
                Vector<Integer> tmp = graph.get(at).get(i);
                if(dist[tmp.get(0)]>dist[at]+tmp.get(1)){
                    dist[tmp.get(0)] = dist[at]+tmp.get(1);
                    prev[tmp.get(0)] = at;
                    curr = new Vector<Integer>();
                    curr.addElement(dist[tmp.get(0)]);
                    curr.addElement(tmp.get(0));
                    pq.add(curr);
                }
            }
        }

        // calculate min time and route
        if(dist[end]==99999999){
            System.out.println("ROUTE NOT FOUND");
            return;
        }

        int time = dist[end];
        if(tfflag==1) time-=3;
        if(tsflag==1) time-=2;

        // check if transfer, add flag then remove. reconstuct print string then print it.
        int flag = 0;
        String c="";
        int x = end;
        String res = "";
        if(tfflag==1){
            x = prev[x];
            res = to;
        }
        Vector<String> quark = new Vector<String>();
        while(true){

            if(!c.equals(graphtoname.get(x))){
                flag = 0;
            }
            if(flag==1){
                x = prev[x];
                continue;
            }
            if(tsflag==1&&graphtoname.get(x).equals(from)){
                quark.addElement(graphtoname.get(x));
                break;
            }
            if(transfernode.get(graphtoname.get(x))!=null&&graphtoname.get(x).equals(graphtoname.get(prev[x]))){
                if(flag==0){
                    quark.addElement("["+graphtoname.get(x)+"]");
                    flag=1;
                    c = graphtoname.get(x);
                }
            }else{
                quark.addElement(graphtoname.get(x));
            }
            if(graphtoname.get(x).equals(from)) break;
            x = prev[x];
        }

        // print result
        for(int i = quark.size()-1 ; i>=0 ; i--){
            if(i!=0) System.out.print(quark.get(i)+" ");
            else System.out.println(quark.get(0));
        }
        System.out.println(time);

    }


    // Distance comparitor function for priority queue
    public static Comparator<Vector<Integer>> mycomp = new Comparator<Vector<Integer>>(){
        @Override
        public int compare(Vector<Integer> a1, Vector<Integer> a2){
            if(a1.get(0)<a2.get(0)){
                return -1;
            }else if(a1.get(0)>a2.get(0)){
                return 1;
            }else{
                if(a1.get(1)<a2.get(1)){
                    return -1;
                }else{
                    return 1;
                }
            }
        }
    };

    // shortest transfers
    public void spath2(String from, String to) throws UnsupportedEncodingException{
        if(from.equals(to)){
            System.out.println(from);
            System.out.println(0);
            return;
        }
        // initialize dist array
        int[][] dist = new int[graph.size()][2];
        int[] prev = new int[graph.size()];
        for(int i = 0 ; i < dist.length ; i++) {
            dist[i][0] = 999999999;
            dist[i][1] = 999999999;
            prev[i] = 999999999;
        }

        // check if start or end is transfer station
        int tsflag = 0;
        int tfflag = 0;
        int start,end;
        if(transfernode.get(from)!=null){
            tsflag = 1;
            start = transfernode.get(from);
        }else{
            start = nametograph.get(from);
        }
        if(transfernode.get(to)!=null){
            tfflag = 1;
            end = transfernode.get(to);
        }else{
            end = nametograph.get(to);
        }

        // do dijkstra
        dist[start][0] = 0;
        dist[start][1] = 0;
        Queue<Vector<Integer>> pq = new PriorityQueue<Vector<Integer>>(mycomp);
        Vector<Integer> curr = new Vector<Integer>();
        curr.add(0);
        curr.add(0);
        curr.add(start);
        pq.add(curr);
        HashMap<Integer,Integer> tmp = new HashMap<Integer,Integer>();
        while(pq.size()!=0){
            curr = pq.poll();
            int at = curr.get(2);
            //System.out.println("curr : " + graphtoname.get(curr.get(2)) + " " + curr.get(2) + " " + curr.get(0) + " " + curr.get(1));
            if(dist[at][0]<curr.get(0)||(dist[at][0]==curr.get(0) && dist[at][1]<curr.get(1))) {
                continue;
            }
            for(int i = 0 ; i < graph.get(at).size() ; i++){
                Vector<Integer> zet = graph.get(at).get(i);
                //System.out.println("looking at : " + graphtoname.get(zet.get(0))+ " " + zet.get(0)  + " " + dist[zet.get(0)][0] + " " + dist[zet.get(0)][1]);
                if((dist[zet.get(0)][0]>curr.get(0))||((dist[zet.get(0)][0]==curr.get(0))&&(dist[zet.get(0)][1]>dist[at][1]+zet.get(1)))){
                    if((transfernode.get(graphtoname.get(zet.get(0)))!=null)&&(transfernode.get(graphtoname.get(at))!=null)&&(transfernode.get(graphtoname.get(at)).equals(new Integer(at)))){
                        dist[zet.get(0)][0] = dist[at][0]+1;
                        // add all adj nodes of this once again to queue.
                        for(int j = 0 ; j < graph.get(zet.get(0)).size();j++){
                            if(graph.get(zet.get(0)).get(j).get(0)!=at){
                                curr = new Vector<Integer>();
                                curr.addElement(dist[graph.get(zet.get(0)).get(j).get(0)][0]);
                                curr.addElement(dist[graph.get(zet.get(0)).get(j).get(0)][1]);
                                curr.addElement(graph.get(zet.get(0)).get(j).get(0));
                                pq.add(curr);
                            }
                        }
                    }else{
                        dist[zet.get(0)][0] = dist[at][0];
                    }
                    dist[zet.get(0)][1] = dist[at][1]+zet.get(1);
                    prev[zet.get(0)] = at;
                    curr = new Vector<Integer>();
                    curr.addElement(dist[zet.get(0)][0]);
                    curr.addElement(dist[zet.get(0)][1]);
                    curr.addElement(zet.get(0));
                    pq.add(curr);
                    //System.out.println("updated this to : " + graphtoname.get(zet.get(0))+ " " + zet.get(0)  + " " + dist[zet.get(0)][0] + " " + dist[zet.get(0)][1]);
                }else{
                    //System.out.println("just passing : " + graphtoname.get(zet.get(0))+ " " + zet.get(0)  + " " + dist[zet.get(0)][0] + " " + dist[zet.get(0)][1]);
                }
            }
        }

        // calculate min time and route
        if(dist[end][1]==999999999){
            System.out.println("ROUTE NOT FOUND");
            return;
        }

        int time = dist[end][1];
        if(tfflag==1) time-=3;
        if(tsflag==1) time-=2;
        // check if transfer, add flag then remove. reconstuct print string then print it.
        int flag = 0;
        String c="";
        int x = end;
        String res = "";
        if(tfflag==1){
            x = prev[x];
            res = to;
        }
        Vector<String> quark = new Vector<String>();
        while(true){
            if(!c.equals(graphtoname.get(x))){
                flag = 0;
            }
            if(flag==1){
                x = prev[x];
                continue;
            }
            if(tsflag==1&&graphtoname.get(x).equals(from)){
                quark.addElement(graphtoname.get(x));
                break;
            }
            if(transfernode.get(graphtoname.get(x))!=null&&graphtoname.get(x).equals(graphtoname.get(prev[x]))){
                if(flag==0){
                    quark.addElement("["+graphtoname.get(x)+"]");
                    flag=1;
                    c = graphtoname.get(x);
                }
            }else{
                quark.addElement(graphtoname.get(x));
            }
            //System.out.println(x + " " + graphtoname.get(x));
            if(graphtoname.get(x).equals(from)) break;
            x = prev[x];

        }

        // print result
        for(int i = quark.size()-1 ; i>=0 ; i--){
            if(i!=0) System.out.print(quark.get(i)+" ");
            else System.out.println(quark.get(0));
        }
        System.out.println(time);

    }
    
}