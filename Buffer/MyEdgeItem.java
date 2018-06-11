

public class MyEdgeItem {
	String next;
	int time;
	boolean transfer;
	
	public MyEdgeItem(String next, int time, boolean transfer) {
		// TODO Auto-generated constructor stub
		this.next=next;
		this.time=time;
		this.transfer=transfer;
	}
	
	public String getNext() {
		return next;
	}
	public void setNext(String next) {
		this.next = next;
	}
	public int getTime() {
		return time;
	}
	public void setTime(int time) {
		this.time = time;
	}

	public boolean isTransfer() {
		return transfer;
	}

	public void setTransfer(boolean transfer) {
		this.transfer = transfer;
	}
	
	
}
