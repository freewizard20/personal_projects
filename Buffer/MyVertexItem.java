
import java.util.ArrayList;

public class MyVertexItem {
	int key;
	String id;
	String name;
	String line;
	ArrayList<MyEdgeItem> edges;
	
	public MyVertexItem() {
		// TODO Auto-generated constructor stub
	}
	
	public MyVertexItem(int key, String id,String name,String line) {
		// TODO Auto-generated constructor stub
		this.key=key;
		this.id=id;
		this.name=name;
		this.line=line;
		edges=new ArrayList();
	}

	public String getId() {
		return id;
	}

	public void setId(String id) {
		this.id = id;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getLine() {
		return line;
	}

	public void setLine(String line) {
		this.line = line;
	}

	public ArrayList<MyEdgeItem> getEdges() {
		return edges;
	}

	public void setEdges(ArrayList<MyEdgeItem> edges) {
		this.edges = edges;
	}
	
	public void insertEdges(MyEdgeItem edge) {
		this.edges.add(edge);
	}

	public int getKey() {
		return key;
	}

	public void setKey(int key) {
		this.key = key;
	}
	
	
}
