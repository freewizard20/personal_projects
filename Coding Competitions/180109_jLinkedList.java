package my;

public class jLinkedList {
	jNode root;
	int length;
	
	jLinkedList(){
		this.length = 0;
	}
	void printlist() {
		jNode tmp = root;
		do{
		if(tmp!=null) {
			System.out.println(tmp.value);
		}
		if(tmp.next!=null) {
			tmp = tmp.next;
		}else {
			break;
		}
			
		}while(true);
		System.out.println("--------------------");
	}
	
	void addlist(int value) {
		jNode tmp = root;
		while(true) {
			if(tmp==null) {
				root = new jNode(value);
				this.length++;
				break;
			}
			if(tmp.next!=null) {
				tmp = tmp.next;
			}else {
				tmp.next = new jNode(value);
				this.length++;
				break;
			}
		}
	}
	
	int getlist(int index) {
		jNode tmp = root;
		if(index<0) {
			return 999;
		}
		if(index>=length) {
			return 9999;
		}
		for(int i = 0 ; i < index ; i++) {
			tmp = tmp.next;
		}
		return tmp.value;
	}
	
	void addlist(int value, int index) {
		if(index<0 || index>=length) {
			System.out.println("error while adding");
			return;
		}
		jNode tmp = root;
		for(int i = 0 ; i < index ; i++) {
			tmp = tmp.next;
		}
		jNode ins = new jNode(value);
		ins.next = tmp.next;
		tmp.next = ins;
		length++;
		
	}
	
	void deletelist() {
		if(root==null) {
			System.out.println("error");
			return;
		}
		jNode tmp =root;
		jNode tmp2=null;;
		while(true) {
			if(tmp.next==null) {
				break;
			}
			tmp2 = tmp;
			tmp = tmp.next;
		}
		tmp2.next = null;
		length--;
	}
	
	void deletelist(int index) {
		if(index<0||index>=length) {
			System.out.println("error index while deleting");
			return;
		}
		jNode tmp = root;
		for(int i = 0 ; i < index-1 ; i++) {
			tmp = tmp.next;
		}
		tmp.next = tmp.next.next;
		length--;
	}
}
