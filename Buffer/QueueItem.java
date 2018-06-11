import java.util.ArrayList;

public class QueueItem implements Comparable<QueueItem>{
	int transfer;
	int time;
	MyVertexItem item;
	
	public QueueItem(int transfer, int time, MyVertexItem item) {
		// TODO Auto-generated constructor stub
		this.transfer = transfer;
		this.time = time;
		this.item = item;
	}
	
	@Override
	public int compareTo(QueueItem arg0) {
		// TODO Auto-generated method stub
		if(this.transfer>arg0.getTransfer()) return 1;
		else if(this.transfer<arg0.getTransfer()) return -1;
		else return (this.time-arg0.getTime());
	}

	public int getTime() {
		return time;
	}

	public void setTime(int time) {
		this.time = time;
	}

	public MyVertexItem getItem() {
		return item;
	}

	public void setItem(MyVertexItem item) {
		this.item = item;
	}

	public int getTransfer() {
		return transfer;
	}

	public void setTransfer(int transfer) {
		this.transfer = transfer;
	}

	
}
