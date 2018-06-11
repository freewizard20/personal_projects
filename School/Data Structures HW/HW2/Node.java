public class Node<T> {
    private T item;
    private Node<T> next;

    public Node(T obj) {
        this.item = obj;
        this.next = null;
    }
    
    public Node(T obj, Node<T> next) {
    	this.item = obj;
    	this.next = next;
    }
    
    public final T getItem() {
    	return item;
    }
    
    public final void setItem(T item) {
    	this.item = item;
    }
    
    public final void setNext(Node<T> next) {
    	this.next = next;
    }
    
    public Node<T> getNext() {
    	return this.next;
    }
    
    // insert new node with element obj next to current node
    public final void insertNext(T obj) {
      
      // node to be newly connected
      Node<T> tmp = new Node<T>(obj);
      
      // append if this is the last node
      if(this.next==null) this.next = tmp;
      
      // if next node is valid, connect new node in between
      else {
        tmp.next = this.next;
        this.next = tmp;
      }
      
    }
    
    // remove next node
    public final void removeNext() {
    
      // base case
      if(this.next==null) return;
      
      // general case : connect with next next node
      else this.next = this.next.next;
      
    }
    
    // node equality based on element equality
    public boolean equals(Node<T> t) {
    	return t.getItem().equals(this.getItem());
    }
    
}