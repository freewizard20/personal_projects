
import java.util.Iterator;
import java.util.NoSuchElementException;

public class MyLinkedList<T extends Comparable<T>> implements ListInterface<T> {
	// dummy head
	Node<T> head;
	int numItems;

	public MyLinkedList() {
		head = new Node<T>(null);
		numItems = 0;
	}

    /**
     * {@code Iterable<T>}를 구현하여 iterator() 메소드를 제공하는 클래스의 인스턴스는
     * 다음과 같은 자바 for-each 문법의 혜택을 볼 수 있다.
     * 
     * <pre>
     *  for (T item: iterable) {
     *  	item.someMethod();
     *  }
     * </pre>
     * 
     * @see PrintCmd#apply(MovieDB)
     * @see SearchCmd#apply(MovieDB)
     * @see java.lang.Iterable#iterator()
     */
    public final Iterator<T> iterator() {
    	return new MyLinkedListIterator<T>(this);
    }
    
    // remove internal node that has item as value
	public void remove(T item){
		
		Node<T> tmp = head;
		
		// go through list until item node is found
		while(tmp.getNext()!=null) {
			
			// if next node's value matches, remove it
			if(tmp.getNext().getItem().equals(item)) {
				tmp.removeNext();
				numItems--;
			}
			
			// shift to next
			tmp = tmp.getNext();
			
			// terminate if end
			if(tmp==null) break;
		}
	}

	public Node<T> search(T item) {
		
		Node<T> tmp = head;
		
		// go through list to find value item
		while(tmp.getNext()!=null) {
			tmp = tmp.getNext();
			
			// if found, return the node object
			if(tmp.getItem().equals(item)) {
				return tmp;
			}
		}
		
		// not found
		return null;
	}

	@Override
	public boolean isEmpty() {
		return head.getNext() == null;
	}

	@Override
	public int size() {
		return numItems;
	}

	@Override
	public T first() {
		return head.getNext().getItem();
	}

	@Override
	public void add(T item) {
		
		// base case : list is empty
		if(this.size()==0) {
			head.insertNext(item);
			numItems++;
		}
		
		// go through list
		Node<T> target = head.getNext();
		Node<T> follower = head;
		
		// shift until same, bigger, or null met
		while(target!=null&&target.getItem().compareTo(item)<0) {
			target = target.getNext();
			follower = follower.getNext();
		}
		
		if(target==null) {
			// if end of list met, the new node is biggest
			follower.insertNext(item);
			numItems++;
			
		}else if(target.getItem().equals(item)) {
			// if there is a same value node, then do nothing
			
		}else {
			// if there was a bigger element, insert before it
			follower.insertNext(item);
			numItems++;
		}
		
		return;
	
	}

	@Override
	public void removeAll() {
		head.setNext(null);
	}
}

class MyLinkedListIterator<T extends Comparable<T>> implements Iterator<T> {
	// FIXME implement this
	// Implement the iterator for MyLinkedList.
	// You have to maintain the current position of the iterator.
	private MyLinkedList<T> list;
	private Node<T> curr;
	private Node<T> prev;

	public MyLinkedListIterator(MyLinkedList<T> list) {
		this.list = list;
		this.curr = list.head;
		this.prev = null;
	}

	@Override
	public boolean hasNext() {
		return curr.getNext() != null;
	}

	@Override
	public T next() {
		if (!hasNext())
			throw new NoSuchElementException();

		prev = curr;
		curr = curr.getNext();

		return curr.getItem();
	}

	@Override
	public void remove() {
		if (prev == null)
			throw new IllegalStateException("next() should be called first");
		if (curr == null)
			throw new NoSuchElementException();
		prev.removeNext();
		list.numItems -= 1;
		curr = prev;
		prev = null;
	}
}