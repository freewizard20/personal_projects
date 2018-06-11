import java.util.Iterator;
import java.util.NoSuchElementException;

/**
 * Genre, Title 을 관리하는 영화 데이터베이스.
 * 
 * MyLinkedList 를 사용해 각각 Genre와 Title에 따라 내부적으로 정렬된 상태를  
 * 유지하는 데이터베이스이다. 
 */
public class MovieDB {

	// Movielist has a MyLinkedList<Genre> private object, and each <Genre> has a MyLinkedList<MovieDBItem> private object
	// making it a double layered linked list structure
	MovieList test;

    public MovieDB() {
		test = new MovieList();
    }

    public void insert(MovieDBItem item) {
		test.add(item);
    }

    public void delete(MovieDBItem item) {
    	test.remove(item);
    }

    public MyLinkedList<MovieDBItem> search(String term) {
    	
    	// list of searched elements
    	MyLinkedList<MovieDBItem> ret = new MyLinkedList<MovieDBItem>();
    	
    	// iterator of Genre
    	Node<Genre> tmp = test.data.head;    	
    	// go through MovieList private MyLinkedList<Genre>
    	for(int i = 0 ; i < test.data.size() ; i++) {
    		tmp = tmp.getNext();
    		
    		// iterator of MovieDBItem
    		Node<MovieDBItem> tmp2 = tmp.getItem().inner.head;
    		// go through every Genre's inner private MylinkedList<MovieDBItem>
    		for(int j = 0 ; j < tmp.getItem().inner.size(); j++) {
    			tmp2 = tmp2.getNext();
    			
    			// if the MovieDBItem contains term in title, add to return
    			if(tmp2.getItem().getTitle().contains(term)) {
    				ret.add(tmp2.getItem());
    			}
    		}
    	}

    	// return searched elements
        return ret;
    }
    
    // function to print every element in MovieList
    public MyLinkedList<MovieDBItem> items() {
    	
    	// returning list
    	MyLinkedList<MovieDBItem> ret = new MyLinkedList<MovieDBItem>();
    	
    	// iterator, first layer
    	Node<Genre> tmp = test.data.head;
    	for(int i = 0 ; i < test.data.size() ; i++) {
    		tmp = tmp.getNext();
    		
    		// iterator, second layer
    		Node<MovieDBItem> tmp2 = tmp.getItem().inner.head;
    		for(int j = 0 ; j < tmp.getItem().inner.size(); j++) {
    			tmp2 = tmp2.getNext();
    			
    			// add every element to list
    			ret.add(tmp2.getItem());
    		}
    	}
    	
    	// return list of all elements
    	return ret;
    }
}

class Genre extends Node<String> implements Comparable<Genre> {
	
	// inner list of genre
	public MyLinkedList<MovieDBItem> inner;

	public Genre(MovieDBItem mb) {
		// node value initialized here
		super(mb.getGenre());
		inner = new MyLinkedList<MovieDBItem>();
		inner.add(mb);
	}
	
	@Override
	public int compareTo(Genre o) {
		// using parent's members
		return this.getItem().compareTo(o.getItem());
	}

	@Override
	public int hashCode() {
		// using parent's functions
		return this.getItem().hashCode();
	}
	
	public void add(MovieDBItem mb) {
		inner.add(mb);
	}
	
	@Override
	public boolean equals(Object obj) {
		Genre ss = (Genre) obj;
		// uses node's value to check equality
		return this.getItem().equals(ss.getItem());
	}
}

class MovieList implements ListInterface<String> {	
	
	// 1st layer of linked list based on genre nodes
	public MyLinkedList<Genre> data;
	
	public MovieList() {
		this.data = new MyLinkedList<Genre>();
	}

	// deprecated
	@Override
	public Iterator<String> iterator() {
		return new MyLinkedListIterator<String>(new MyLinkedList<String>());
	}

	// deprecated
	@Override
	public boolean isEmpty() {
		return this.data.isEmpty();
	}

	// deprecated
	@Override
	public int size() {
		return this.data.size();
	}

	// deprecated
	@Override
	public void add(String item) {
		System.out.println("strange structure");
	}

	// add a new MovieDBItem to the right place
	public void add(MovieDBItem mb) {
		
		// look for the Genre if existent
		Genre tmp = new Genre(mb);
		Node<Genre> tmp2 = data.search(tmp);
		
		if(tmp2==null) {
			// if Genre is new, make new genre
			tmp.add(mb);
			data.add(tmp);
		}else {
			// if Genre is present, add new element there
			tmp2.getItem().inner.add(mb);
		}
		
	}
	
	// remove a MovieDBItem if present
	public void remove(MovieDBItem mb) {
		
		// look for the genre if existent
		Genre tmp = new Genre(mb);
		Node<Genre> tmp2 = data.search(tmp);
		
		if(tmp2==null) {
			// if not fount, do nothing
			return;
		}else {
			
			// if found, remove MovieDBItem from inner linkedlist of genre
			tmp2.getItem().inner.remove(mb);
			
			// after removing, if genre is empty, remove genre too
			if(tmp2.getItem().inner.size()==0) {
				data.remove(tmp2.getItem());
			}
		}
	}
	
	@Override
	public String first() {
		return data.first().getItem();
	}

	@Override
	public void removeAll() {
		data.removeAll();
	}
}