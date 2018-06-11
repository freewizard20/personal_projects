import java.util.ArrayList;
import java.util.StringTokenizer;
import java.util.Set;
import java.io.*;

public class Subway {
    private static final int transferTime = 5; // 환승에 걸리는 시간은 5분으로 고정
	
	public static void main(String[] args) throws Exception{
		// 주어진 데이터를 읽어서 Initialization 진행
		// 먼저 station의 정보를 읽는다.
		
		BufferedReader dataBr = new BufferedReader(new InputStreamReader(new FileInputStream(args[0]),"UTF-8"));
	
		int stationIndex = 0;
		
		// station의 정보를 저장해나갈 ArrayList
		ArrayList<Station> stationList = new ArrayList<>();
				
		// HashMap을 사용하여 각 station의 code와 name을 station의 정보로 hashing 한다.
		DuplicateMap<String, Station> stationCodeMap = new DuplicateMap<>();
		DuplicateMap<String, Station> stationNameMap = new DuplicateMap<>();
		
		while(true) {
			String stationData = dataBr.readLine();
			if(stationData.equals("")) break; // station의 정보 읽기 완료
				
			StringTokenizer t = new StringTokenizer(stationData);
				
			String stationCode = t.nextToken();
			String stationName = t.nextToken();
			String line = t.nextToken();
				
			Station station = new Station(stationCode, stationName, line, stationIndex);
								
			stationList.add(station);
			stationCodeMap.put(stationCode, station);
			stationNameMap.put(stationName, station);
				
			stationIndex++;
				
		}
		
		// ArrayList를 Array로 변환
        Station[] stationArray = stationList.toArray(new Station[stationList.size()]);
                
        // edge의 정보를 읽는다.
        // edge들은 기본적으로 동일 line을 가지는 station들에 대하여 구성된다.
        ArrayList<Edge> edgeList = new ArrayList<>();
        
        while(dataBr.ready()) {
        	
        	String edgeData = dataBr.readLine();
	        	
        	StringTokenizer t = new StringTokenizer(edgeData);
            	
        	String startStationCode = t.nextToken();
        	String endStationCode = t.nextToken();
        	int time = Integer.parseInt(t.nextToken());
            	        
        	Station startStation = stationCodeMap.get(startStationCode, 0);
        	Station endStation = stationCodeMap.get(endStationCode, 0);
            	
        	Edge edge = new Edge(startStation, endStation, time, 0);
        	edgeList.add(edge);
        }
                
        
        // station의 name을 검사하여 동일 name을 가지는 station들은 환승역으로 처리하여 5분의 시간을 가지는 환승 edge로 구성해준다.
        
        Set<String> stationNameSet = stationNameMap.keySet();
        String[] stationNameArray = stationNameSet.toArray(new String[stationNameSet.size()]);
        
        for(String k : stationNameArray) {
        	// 주어진 stationName을 가지는 station의 list (환승역의 경우 list 내부에 여러개의 station이 존재)
        	ArrayList<Station> l = stationNameMap.get(k);
        	
        	// 환승역인 경우 각 역간의 가상의 edge를 추가한다.
        	if(l.size() > 1) {
        		Station[] s = l.toArray(new Station[l.size()]);
        		
        		for(int i=0; i<s.length-1; i++) {
        			
        			Station temp1 = s[i];
        			
        			for(int j=i+1; j<s.length; j++) {
                		Station temp2 = s[j];
                			
                		Edge transferEdge = new Edge(temp1, temp2, transferTime, 1);
                		edgeList.add(transferEdge);
                			
                		transferEdge = new Edge(temp2, temp1, transferTime, 1);
                		edgeList.add(transferEdge);
                		
                	}
        		}
        	}
        }
        
        // ArrayList를 Array로 변환
        Edge[] edgeArray = edgeList.toArray(new Edge[edgeList.size()]);
        dataBr.close();
       
        ///////////////////////////////////////////////////////////////////////////////////////////////////////
        
        // data를 읽는 것을 완료, 주어진 두 역의 정보를 읽은 뒤 최단 시간 및 경로를 출력
        // 읽어드린 data로부터 지하철 노선도 구성
        SubwayGraph subwayMap = new SubwayGraph(stationArray, edgeArray);
        
		BufferedReader inputBr = new BufferedReader(new InputStreamReader(System.in,"UTF-8"));
		while(true) {
			
			String inputData = inputBr.readLine();
				
			if(inputData.equals("QUIT")) break;
				
			StringTokenizer t = new StringTokenizer(inputData);
			
			String startStationName = t.nextToken();
			String endStationName = t.nextToken();
								
			Station startStation = stationNameMap.get(startStationName, 0);
			Station endStation = stationNameMap.get(endStationName, 0);
					
			t = new StringTokenizer(inputData);
			
			// 최단 경로를 찾아 시간과 경로를 출력한다.
			if(t.countTokens() == 2) subwayMap.Dijkstra(startStation, endStation, false);
			
			// 최소환승경로를 찾아 시간과 경로를 출력한다.
			else subwayMap.Dijkstra(startStation, endStation, true);
		}	
	}
}
