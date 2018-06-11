import java.util.Arrays;
import java.util.ArrayList;
import java.util.PriorityQueue;

public class SubwayGraph {
    private static final int INF = Integer.MAX_VALUE; // 연결되어 있지 않은 station 사이의 가상의 시간
    private int stationNum;
    private int edgeNum;

    private Station[] stationArray; // 지하철 노선도가 가지는 모든 station의 배열
    private Edge[] edgeArray; // 지하철 노선도가 가지는 모든 edge의 배열
    private ArrayList<Edge>[] edgesOfEach; // 각 station에 대하여 그 station에서 출발하는 edge의 ArrayList 를 원소로 가지는 배열

	@SuppressWarnings("unchecked")
	SubwayGraph(Station[] stationArray, Edge[] edgeArray) {
        this.stationArray = stationArray;
        this.edgeArray = edgeArray;
        
        edgesOfEach = (ArrayList<Edge>[]) new ArrayList[stationArray.length];
                 
        for (int i = 0; i < stationArray.length; i++) {
        	edgesOfEach[i] = new ArrayList<>();
        }
        
        for (int i = 0; i < edgeArray.length; i++) {

            int startIndex = edgeArray[i].getStartIndex();

            edgesOfEach[startIndex].add(0, edgeArray[i]);
        }

        stationNum = stationArray.length;
        edgeNum = edgeArray.length;
    }

    public int getStationNum() {
        return stationNum;
    }

    public int getEdgeNum() {
        return edgeNum;
    }    
    
    public Station[] getStationArray() {
    	return stationArray;
    }
    
    public Edge[] getEdgeArray() {
    	return edgeArray;
    }
    
    // Dijkstra algorithm을 이용하여 시작역, 도착역을 변수로 하여 최단 시간 및 최단 경로를 출력하는 메쏘드
    // t가 false일 경우 (최소 환승x) 최단 시간 경로를, t가 true일 경우 최소환승 경로를 출력한다.
    // Modification from http://jaesungbong.tistory.com/26 [improving my programming skills]    
    public void Dijkstra(Station startStation, Station endStation, boolean t) throws CloneNotSupportedException{
    	    	
    	if(t == false) {
    		
    		int[] time;
    		boolean[] visit;
    		Edge[] prev; // 최단 경로를 추적하기 위한 Array

    		int V = stationArray.length;
    		int startIndex = startStation.getStationIndex(); // 시작하는 역이 가지는 고유 index

    		time = new int[V];
    		visit = new boolean[V];
    		prev = new Edge[V]; // 최단경로를 역추적하기 위하여 사용하는 배열

    		Arrays.fill(time, INF); // 초기에 모든 역사이의 시간은 INF 로 설정
    		Arrays.fill(visit, false); // 초기에 모든 역은 방문하지 않았음
    	        
    		time[startIndex] = 0; // 시작 역은 걸리는 시간이 0이다.

    		PriorityQueue<Edge> pq = new PriorityQueue<Edge>(); // 우선순위 큐를 활용하여 효율적으로 구현
    		pq.offer(new Edge(startStation, startStation, 0, 0)); //시작 정점을 우선순위 큐에 넣음.
    		prev[0] = new Edge(startStation, startStation, 0, 0);

    		// 우선순위 큐가 비어있지 않고 도착
    		while (!pq.isEmpty()) {
    			Edge e = pq.poll(); // 큐에 들어있는 edge중 가장 시간이 적게 걸리는 것을 찾음.
    	            
    			// 이미 방문한 역은 처리할 필요가 없다.
    			if (visit[e.getEndIndex()] == true) {
    				continue;
    			}
    	            
    			// 방문되지 않은 역을 방문!
    			visit[e.getEndIndex()] = true;
    	            
    			// 만약 방문한 역이 목적지라면(역의 이름이 같기만 하면 된다!! - 도착역이 환승역인 경우를 고려하여) 최단 경로와 최단 시간을 출력하고 알고리즘을 종료한다.
    			if( e.getEndStation().compareTo(endStation) == 0 ) {
    	            	
    				String shortestPath = shortestPath(startStation, e.getEndStation(), prev);
    	            	    	            	
    				System.out.println(shortestPath);
    				System.out.println(time[e.getEndIndex()]);
    				return;
    			}
    	            
    			// 기준 역에서 방문하지 않은 모든 경로를 탐색한다.
    			for (Edge k : edgesOfEach[e.getEndIndex()]) {
    				    				
    				if (visit[k.getEndIndex()] == false) {
    					// startStation이 환승역인 경우 이 과정을 거친다.
    					if(e.getEndStation().compareTo(startStation) == 0 && e.getEndStation().compareTo(k.getEndStation()) == 0 ) {
    						time[k.getEndIndex()] = 0;
    						prev[k.getEndIndex()] = k;
    					}
    	                	
    					// 모든 경로를 탐색하여 각 경로의 도착역이 출발역으로부터 걸리는 시간을 업데이트 한다. (기존 시간과 비교하여 최소값으로 업데이트)
    					if( time[k.getEndIndex()] > time[e.getEndIndex()] + k.getTime()) {
    						time[k.getEndIndex()] = time[e.getEndIndex()] + k.getTime();
    						prev[k.getEndIndex()] = k; // 바로 전의 edge를 업데이트하여 최단 경로를 역으로 추적한다.
    					}
    					
    					// 단순 최단 경로이므로 환승횟수는 0으로 생각한다.
    					pq.offer(new Edge(startStation, k.getEndStation(), time[k.getEndIndex()], 0));
    				}
    			}
    		}
    	}
     
    	if(t == true) {
    		
    		int[] time;
    		int[] transfer;
    		boolean[] visit;
    		Edge[] prev; // 최단 경로를 추적하기 위한 Array

    		int V = stationArray.length;
    		int startIndex = startStation.getStationIndex(); // 시작하는 역이 가지는 고유 index

    		time = new int[V];
    		transfer = new int[V];
    		visit = new boolean[V];
    		prev = new Edge[V]; // 최단경로를 역추적하기 위하여 사용하는 배열

    		Arrays.fill(time, INF); // 초기에 모든 역사이의 시간은 INF 로 설정
    		Arrays.fill(transfer, INF);
    		Arrays.fill(visit, false); // 초기에 모든 역은 방문하지 않았음
    	        
    		time[startIndex] = 0; // 시작 역은 걸리는 시간이 0이다.
    		transfer[startIndex] = 0;

    		PriorityQueue<Edge> pq = new PriorityQueue<>(); // 우선순위 큐를 활용하여 효율적으로 구현
    		pq.offer(new Edge(startStation, startStation, 0, 0)); //시작 정점을 우선순위 큐에 넣음.
    		prev[0] = new Edge(startStation, startStation, 0, 0);

    		// 우선순위 큐가 비어있지 않고 도착
    		while (!pq.isEmpty()) {
    			Edge e = pq.poll(); // 큐에 들어있는 edge중 가장 시간이 적게 걸리는 것을 찾음.
    	            
    			// 이미 방문한 역은 처리할 필요가 없다.
    			if (visit[e.getEndIndex()] == true) {
    				continue;
    			}
    	            
    			// 방문되지 않은 역을 방문!
    			visit[e.getEndIndex()] = true;
    	            
    			// 만약 방문한 역이 목적지라면(역의 이름이 같기만 하면 된다!! - 도착역이 환승역인 경우를 고려하여) 최단 경로와 최단 시간을 출력하고 알고리즘을 종료한다.
    			if( e.getEndStation().compareTo(endStation) == 0 ) {
    	            	
    				String shortestPath = shortestPath(startStation, e.getEndStation(), prev);
    	            	
    				System.out.println(shortestPath);
    				System.out.println(time[e.getEndIndex()]);
    				
    				return;
    			}
    	            
    			// 기준 역에서 방문하지 않은 모든 경로를 탐색한다.
    			for (Edge kOriginal : edgesOfEach[e.getEndIndex()]) {
    				
    				Edge k = (Edge)kOriginal.clone(); // 기존 Edge의 정보를 보호하기 위하여 사용
    				
    				if (visit[k.getEndIndex()] == false) {
    					
    					// startStation이 환승역인 경우에는 환승이 의미가 없다.
    					if(e.getEndStation().compareTo(startStation) == 0 && e.getEndStation().compareTo(k.getEndStation()) == 0 ) {
    						k.downTransferNum();
    						time[k.getEndIndex()] = 0;
    						prev[k.getEndIndex()] = k;
    						transfer[k.getEndIndex()] = transfer[e.getEndIndex()];
    					}
    	                	
    					// 환승횟수가 적은것을 기준으로 탐색한다.
    					if( transfer[k.getEndIndex()] > transfer[e.getEndIndex()] + k.getTransferNum()) {
    						transfer[k.getEndIndex()] = transfer[e.getEndIndex()] + k.getTransferNum();
    						time[k.getEndIndex()] = time[e.getEndIndex()] + k.getTime();
    						prev[k.getEndIndex()] = k;
    					}
    					
    					// 환승횟수가 같을 경우 최단 시간을 탐색한다.
    					else if(transfer[k.getEndIndex()] == transfer[e.getEndIndex()] + k.getTransferNum()) {
    						if( time[k.getEndIndex()] > time[e.getEndIndex()] + k.getTime() ) {
        						time[k.getEndIndex()] = time[e.getEndIndex()] + k.getTime();
        						prev[k.getEndIndex()] = k; // 바로 전의 edge를 업데이트하여 최단 경로를 역으로 추적한다.
        					}
    					}
    					 
    					// 환승횟수도 업데이트 한다!
    					pq.offer(new Edge(startStation, k.getEndStation(), time[k.getEndIndex()] , transfer[k.getEndIndex()]));
    				}
    			}
    		}
    	}
    	       
    }
    
    // 최단경로를 역으로 추적해나가는 방법 ( prev는 최단경로에 이르는 각 edge의 정보를 저장하고 있다)
    // 최종적으로 최단 경로와 환승 횟수를 출력한다.
    private String shortestPath(Station startStation, Station endStation, Edge[] prev) {
    	String shortestPath ="";
    	
    	String result;
    	
    	shortestPath += endStation.getStationName();
    	
    	Station temp = endStation;
    	
    	// 도착역이 시작역과 같아지면 반복을 종료한다.
    	while(temp.compareTo(startStation) != 0) {
    		Station nextStation = temp; 
    		
    		temp = prev[temp.getStationIndex()].getStartStation(); // 바로 전 역으로 이동!
    		
    		// temp가 startStation이면 환승이 의미가 없으므로 주의한다.
    		if(temp.compareTo(startStation) != 0) {
    			Station prevStation = prev[temp.getStationIndex()].getStartStation();
    			
        		// 위 과정을 거치면 prevStation - temp - nextStation으로 구성이 된다.
        		// prevStation과 temp의 line이 같고 temp와 nextStatin의 line이  다르면 환승역
        		
        		if(temp.compareTo(nextStation) == 0) {
        			shortestPath = "[" + temp.getStationName() + "]" + " " + shortestPath;
        		}
        		
        		else if(temp.compareTo(prevStation) == 0) continue;
         		
        		// 환승역이 아닌 경우 그대로 더한다.
        		else {
            		shortestPath = temp.getStationName() + " " + shortestPath;
        		}
    		}
    	}
    	
		shortestPath = temp.getStationName() + " " + shortestPath; // startStation을 더해줌으로서 최단경로 완성!  
		
		result = shortestPath;
		
		return result;
    }
    
}




