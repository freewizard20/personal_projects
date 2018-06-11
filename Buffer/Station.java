
// 각 역이 가지고 있는 정보를 나타내는 클래스
public class Station implements Comparable<Station>{
    private String stationCode;
    private String stationName;
    private String line;
    private int stationIndex; // 데이터 파일을 읽으면서 각 역의 index를 지정한다.

    Station(String stationCode, String stationName, String line, int stationIndex){
    	this.stationCode = stationCode;
    	this.stationName = stationName;
    	this.line = line;
        this.stationIndex = stationIndex;
    }

    public String getStationCode(){
        return stationCode;
    }

    public String getStationName(){
        return stationName;
    }

    public String getLine(){
        return line;
    }

    public int getStationIndex(){
        return stationIndex;
    }

    // Name만 같으면 같은 역으로 취급한다.
    @Override
    public int compareTo(Station another){
    	return stationName.compareTo(another.stationName);
    }
}
