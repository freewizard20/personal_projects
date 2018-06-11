
// 각 역간의 연결관계를 나타내는 edge
public class Edge implements Comparable<Edge>, Cloneable{
	private Station startStation;
	private	Station endStation;
    private int startStationIndex;
    private int endStationIndex;
    private int time;
    private int transferNum;
    
    // 최소환승경로를 위해 환승횟수까지 고려한 edge
    Edge(Station startStation, Station endStation, int time, int transferNum){
    	this.startStation = startStation;
        this.endStation = endStation;
        
        startStationIndex = startStation.getStationIndex();
        endStationIndex = endStation.getStationIndex();
        
        this.time = time;
        this.transferNum = transferNum;
    }
   
    public void upTransferNum() {
    	this.transferNum++;
    }

    public void downTransferNum() {
    	this.transferNum--;
    }
    
    public Station getStartStation(){
        return startStation;
    }

    public Station getEndStation(){
        return endStation;
    }
    
    public int getStartIndex() {
    	return startStationIndex;
    }
    
    public int getEndIndex() {
    	return endStationIndex;
    }

    public int getTime() {
        return time;
    }
    
    public int getTransferNum() {
    	return transferNum;
    }

    @Override
    public int compareTo(Edge another){
    	
    	// 환승횟수가 같은 경우에는 시간으로 비교를 한다.
    	// 최단경로를 구할때는 모든 edge의 환승횟수는 0으로 생각하므로  시간이 적게 걸리는 것을 우선적으로 택한다.
    	// 최소환승 경로를 구하는 경우 환승횟수가 같은 경우에는 시간이 적게 걸리는 것을 우선적으로 택한다.
    	if(this.transferNum == another.getTransferNum()) return this.time - another.getTime(); 
    	
    	// 최소환승 경로를 구하는 경우 환승횟수가 적은것을 우선적으로 택한다.
        return this.transferNum - another.getTransferNum(); 
    }
    
    @Override
    public Object clone() throws CloneNotSupportedException{
    	return super.clone();
    }
    
}
