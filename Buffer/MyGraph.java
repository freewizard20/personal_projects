
import java.util.ArrayList;
import java.util.HashMap;
import java.util.PriorityQueue;

public class MyGraph {
	
	private int size;
	
	private HashMap<String, MyVertexItem> IdHashmap;
	private HashMap<String, MyVertexItem> NameHashmap; 
	private HashMap<Integer, MyVertexItem> KeyHashmap; 
	
	private PriorityQueue<QueueItem> myqueue; 
	
	public MyGraph() {
		// TODO Auto-generated constructor stub
		IdHashmap = new HashMap<>();
		NameHashmap = new HashMap<>();
		KeyHashmap = new HashMap<>();
		size = 0;
	}
	
	public void insert(String id, String name,String line) {
		MyVertexItem new_item = new MyVertexItem(size, id, name, line);
		if(NameHashmap.containsKey(name)) {
			MyVertexItem original_item = NameHashmap.get(name);
			MyEdgeItem new_edge = new MyEdgeItem(id, 5, true);
			for(int i=0; i<original_item.getEdges().size(); i++) {
				MyVertexItem temp=IdHashmap.get(original_item.getEdges().get(i).getNext());
				temp.insertEdges(new_edge);
				new_item.insertEdges(new MyEdgeItem(temp.getId(), 5, true));
			}
			original_item.insertEdges(new_edge);
			new_item.insertEdges(new MyEdgeItem(original_item.getId(), 5, true));
		}
		else NameHashmap.put(name, new_item);
		IdHashmap.put(id, new_item);
		KeyHashmap.put(size, new_item);
		size++;
	}
	
	public void insertEdge(String start, String stop, int time) {
		MyVertexItem start_item = IdHashmap.get(start);
		MyVertexItem stop_item = IdHashmap.get(stop);
		start_item.insertEdges(new MyEdgeItem(stop, time, false));
		stop_item.insertEdges(new MyEdgeItem(start, time, false));
	}
	
	public void path(String start, String stop, boolean isPath) {
		
		ArrayList<Integer> transfer = new ArrayList();
		ArrayList<Integer> dist = new ArrayList();
		ArrayList<Integer> prev = new ArrayList();
		ArrayList<Boolean> visited = new ArrayList();
		
		MyVertexItem start_item = NameHashmap.get(start);
		
		for(int i=0; i<size; i++) {
			transfer.add(2147483647);
			dist.add(2147483647);
			prev.add(null);
			visited.add(false);
		}
		
		transfer.set(start_item.getKey(), 0);
		dist.set(start_item.getKey(), 0);
		visited.set(start_item.getKey(), true);
		
		myqueue = new PriorityQueue();
		
		for(int i=0; i<start_item.getEdges().size(); i++) {
			 
			String temp_id = start_item.getEdges().get(i).getNext();
			MyVertexItem temp_item = IdHashmap.get(temp_id);
			if(start_item.getEdges().get(i).isTransfer()) {
				myqueue.add(new QueueItem(0, 0, temp_item));
				transfer.set(temp_item.getKey(), 0);
				dist.set(temp_item.getKey(), 0);
			}
			else {
				myqueue.add(new QueueItem(0, start_item.getEdges().get(i).getTime(), temp_item));
				transfer.set(temp_item.getKey(), 0);
				dist.set(temp_item.getKey(), start_item.getEdges().get(i).getTime());
				prev.set(temp_item.getKey(), start_item.getKey());
			}
				
		}
		
		while(true) {
			QueueItem current = myqueue.remove();
			start_item=current.getItem();
			if(start_item.getName().equals(stop)) break;
			if(visited.get(start_item.getKey())) continue;
			visited.set(start_item.getKey(), true);
			
			
			for(int i=0; i<start_item.getEdges().size(); i++) {
				String temp_id = start_item.getEdges().get(i).getNext();
				MyVertexItem temp_item = IdHashmap.get(temp_id);
				int temp_time = dist.get(start_item.getKey())+start_item.getEdges().get(i).getTime();
				int temp_transfer = transfer.get(start_item.getKey());
				if(start_item.getEdges().get(i).isTransfer()) temp_transfer++;
				if(isPath) {
					if(dist.get(temp_item.getKey())> temp_time) {
						dist.set(temp_item.getKey(),temp_time);
						prev.set(temp_item.getKey(),start_item.getKey());
						myqueue.add(new QueueItem(0, temp_time, temp_item));
					}
				}
				else {
					if(transfer.get(temp_item.getKey())> temp_transfer) {
						transfer.set(temp_item.getKey(),temp_transfer);
						dist.set(temp_item.getKey(),temp_time);
						prev.set(temp_item.getKey(),start_item.getKey());
						myqueue.add(new QueueItem(temp_transfer, temp_time, temp_item));
					}
					else if(transfer.get(temp_item.getKey())== temp_transfer && dist.get(temp_item.getKey())> temp_time) {
						dist.set(temp_item.getKey(),temp_time);
						prev.set(temp_item.getKey(),start_item.getKey());
						myqueue.add(new QueueItem(temp_transfer, temp_time, temp_item));
					}
				}
				
			}
			
		}
		int result = dist.get(start_item.getKey());
		ArrayList<String> results = new ArrayList();
		results.add(start_item.getName());

		while(dist.get(start_item.getKey())!=0){
			start_item=KeyHashmap.get(prev.get(start_item.getKey()));
			if(results.get(results.size()-1).equals(start_item.getName())) 
				results.set(results.size()-1, "["+results.get(results.size()-1)+"]");
			else results.add(start_item.getName());
		}
		System.out.print(results.get(results.size()-1));
		for(int i=results.size()-2; i>=0; i--)
			System.out.print(" "+results.get(i));
		System.out.println("");
		System.out.println(result);
		
	}
	
}
