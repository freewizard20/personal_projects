import java.io.*;
import java.util.*;

public class Matching
{
	
	static DB<String> database;
	
	public static void main(String args[])
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		while (true)
		{
			try
			{
				String input = br.readLine();
				if (input.compareTo("QUIT") == 0)
					break;

				command(input);
			}
			catch (IOException e)
			{
				System.out.println("입력이 잘못되었습니다. 오류 : " + e.toString());
			}
		}
	}
	
	private static void command(String input) throws IOException
	{	
		// parse input data
		String route = input.substring(2, input.length());
		
		if(input.charAt(0)=='<') {
			database = new DB<String>(100);
			BufferedReader xr = new BufferedReader(new FileReader(route));
			int lines = 0;
			while(true) {
				String curr = xr.readLine();
				if(curr==null) break;
				database.raw.add(curr);
			}
			xr.close();
			database.fill();
		}else if(input.charAt(0)=='@') {
			database.print(route);
		}else if(input.charAt(0)=='?'){
			database.find(route);
		}else {
			throw new IOException();
		}
	}

}

// highest abstraction of data structure
class DB<T>{
	
	public ArrayList<T> raw;
	public myhash<T> table;
	
	// initialize database with hash table size t
	public DB(int t) {
		table = new myhash<T>(t);
		raw = new ArrayList<T>();
	}
	
	// fill the avl tree with the raw input
	public void fill() {
		
		// go through raw input, does STRING SPECIFIC operations from here
		for(int i = 0 ; i < raw.size(); i++) {
			String tmp = (String) raw.get(i);
			for(int j = 0 ; j < tmp.length()-5;j++) {
				ArrayList<Integer> z = new ArrayList<Integer>();
				z.add(i);
				z.add(j);
				table.insert((T) tmp.substring(j, j+6),z);
			}
		}
		//table.printall();
	}
	
	// database print api slot at
	public void print(T obj) throws IOException {
		try{
		String tmp = (String) obj;
		table.print(Integer.parseInt(tmp));
		}catch(Exception e){
			throw new IOException();
		}
	}
	
	// database find api, specific for string
	public void find(T obj) throws IOException {
		String target = (String) obj;
		mylist<ArrayList<Integer>> candidates;
		// get candidates from DB
		try{
			candidates = table.find((T) target.substring(0, 6));
		} catch (Exception e){
			throw new IOException();
		}
		// get result from candidates
		mylist<ArrayList<Integer>> result = new mylist<ArrayList<Integer>>();
		listnode<ArrayList<Integer>> curr;
		if(candidates==null) curr = null;
		else curr = candidates.getroot();

		while(curr!=null) {
			//match and check if right
			int num = curr.getData().get(0);
			int at = curr.getData().get(1);
			int flag = 1;
			for(int i = 0 ; i < target.length(); i++,at++) {
				if(at>=((String)raw.get(num)).length()) {
					flag=0;
					break;
				}
				if(target.charAt(i)!=((String)raw.get(num)).charAt(at)) {
					flag = 0;
					break;
				}
			}
			if(flag!=0) result.insert(curr.getData());
			curr = curr.getNext();
		}

		// print results
		if(result.getroot()==null) {
			System.out.println("(0, 0)");
		}else {
			curr = result.getroot();
			while(curr!=result.getlast()) {
				System.out.print("("+(curr.getData().get(0)+1)+", "+(curr.getData().get(1)+1)+") ");
				curr = curr.getNext();
			}
			System.out.println("("+(curr.getData().get(0)+1)+", "+(curr.getData().get(1)+1)+")");
		}	
	}
}

// hash table class
class myhash<T>{
	
	private ArrayList<avl<T>> trees;
	
	public myhash(int t){
		trees = new ArrayList<avl<T>>(t);
		for(int i = 0 ; i < t;i++) {
			trees.add(new avl<T>());
		}
	}
	
	// insert api
	public void insert(T obj, ArrayList<Integer> target) {
		// doing string specific operations here
		String curr = (String) obj;
		int pos=0;
		for(int i = 0 ; i < 6 ; i++) {
			pos += curr.charAt(i);
		}
		System.out.println(pos%100 + " " + curr);
		trees.get(pos%100).insert((T)curr, target);
	}
	
	// print all for debugging
	public void printall() {
		for(int i = 0 ; i < trees.size(); i++) {
			if(trees.get(i).getroot()!=null) {
				System.out.print(i + " ");
				print(i);
			}
		}
	}
	
	// preorder print api
	public void print(int at) {
		node<T> curr = trees.get(at).getroot();
		
		if(curr==null) {
			System.out.println("EMPTY");
			return;
		}
		
		Stack<node<T>> buffer = new Stack<node<T>>();
		buffer.push(curr);
		T printer = (T) new Object();
		int flag = 0;
		while(buffer.size()!=0) {
			
			// print one step delayed
			if(flag!=0) System.out.print(printer+" ");
			flag++;
			node<T> rot = buffer.pop();
			printer = rot.data;
			if(rot.right!=null) buffer.push(rot.right);
			if(rot.left!=null) buffer.push(rot.left);
		}
		System.out.println(printer);
	}
	
	// TODO
	public mylist<ArrayList<Integer>> find(T obj) {
		String curr = (String) obj;
		int pos=0;
		for(int i = 0 ; i < 6 ; i++) {
			pos += curr.charAt(i);
		}
		return trees.get(pos%100).find(obj);
	};
	
}

// avl tree class
class avl<T>{
	private node<T> root;
	avl(){
		root = null;
	}
	public node<T> getroot(){
		return root;
	}
	
	
	// find matching string in avl tree and return the list with it; STRING SPECIFIC OPERATIONS
	public mylist<ArrayList<Integer>> find(T obj){
		node<T> runner = root;
		while(runner!=null) {
			int cmp = ((String)runner.data).compareTo((String)obj);
			if(cmp==0) {
				return runner.list;
			}else if(cmp>0) {
				runner = runner.left;
			}else {
				runner = runner.right;
			}
		}
		return null;
	}
	
	private int height(node<T> y) {
		if(y==null) return 0;
		else return y.height;
	}
	
	// right rotate with axis node y
	private node<T> rightrotate(node<T> y){
		
		// rearrange pointers
		node<T> x = y.left;
		node<T> tmp = x.right;
		x.right = y;
		x.parent = y.parent;
		if(y.parent!=null && y.parent.left==y) {
			y.parent.left=x;
		}
		if(y.parent!=null && y.parent.right==y) {
			y.parent.right = x;
		}
		y.left = tmp;
		if(tmp!=null) tmp.parent = y;
		y.parent = x;
		
		// recalculate height
		y.height = Math.max(height(y.right), height(y.left))+1;
		x.height = Math.max(height(x.right), height(x.left))+1;
		
		return x;
	}
	
	// left rotate with axis node y
	private node<T> leftrotate(node<T> y){
		
		// rearrange pointers
		node<T> x = y.right;
		node<T> tmp = x.left;
		x.left = y;
		x.parent = y.parent;
		if(y.parent!=null && y.parent.right==y) {
			y.parent.right=x;
		}
		if(y.parent!=null && y.parent.left==y) {
			y.parent.left = x;
		}
		y.right = tmp;
		if(tmp!=null) tmp.parent = y;
		y.parent = x;
		
		// recalculate height
		y.height = Math.max(height(y.right), height(y.left))+1;
		x.height = Math.max(height(x.right), height(x.left))+1;
		
		return x;
	}
	
	public int checkheight(node<T> curr){
		if(curr==null) return 0;
		int height = Math.max(checkheight(curr.left),checkheight(curr.right))+1;
		if(curr.height!=height) System.out.println("fucked");
		return height;
	}

	public void insert(T obj,ArrayList<Integer> z) {
		checkheight(root);
		// base empty tree case
		if(root==null) {
			root = new node<T>(obj,z);
			return;
		}
		// matches root
		if(root.data.equals(obj)) {
			root.insert(z);
			return;
		}
		// find correct insert position
		node<T> walker = root;
		node<T> runner = (((String)root.data).compareTo((String)obj))>0?root.left:root.right;
		while(true) {
			
			// if runner reached null, insert a new avl node there
			if(runner==null) {
				if((((String)walker.data).compareTo((String)obj))<0) {
					walker.right = new node<T>(obj,z);
					walker.right.parent = walker;
					runner = walker.right;
				}else {
					walker.left = new node<T>(obj,z);
					walker.left.parent = walker;
					runner = walker.left;
				}

				// rearrange height
				node<T> arranger = walker;
				while(arranger!=null){
					arranger.height = Math.max(height(arranger.left),height(arranger.right))+1;
					arranger = arranger.parent;
				}

				// rearrange balance factor when new avl node inserted
				node<T> writer = walker;
				while(writer!=null && writer.parent!=null) {
					int bf = height(writer.parent.left)-height(writer.parent.right);
					if(writer.parent.left==writer) {
						if(bf>1&&runner==writer.left) {
							writer = rightrotate(writer.parent);
						}else if(bf>1&&runner==writer.right) {
							runner = writer;
							writer = leftrotate(writer);
							rightrotate(writer.parent);
						}
					}else {
						if(bf<-1&&runner==writer.right) {
							writer = leftrotate(writer.parent);
						}else if(bf<-1&&runner==writer.left) {
							runner = writer;
							writer = rightrotate(writer);
							leftrotate(writer.parent);
						}
					}
					writer = writer.parent;
				}
							
				return;
			}
			
			// go down the tree
			walker = runner;
			if(runner.data.equals(obj)) {
				// if same string met, append on existing tree
				runner.insert(z);
				return;
			}else if(((String)runner.data).compareTo((String)obj)<0) {
				runner = runner.right;
			}else {
				runner = runner.left;
			}
		}
	}
}

class node<T>{
	public T data;
	public mylist<ArrayList<Integer>> list;
	int height;
	
	public node<T> parent;
	public node<T> left;
	public node<T> right;
	
	public node(T obj, ArrayList<Integer> d){
		height = 1;
		data = obj;
		list = new mylist<ArrayList<Integer>>();
		list.insert(d);
		parent = null;
		left = null;
		right = null;
	}
	
	public void insert(ArrayList<Integer> obj) {
		list.insert(obj);
	}
}

// linked list class
class mylist<T>{
	private listnode<T> root;
	private listnode<T> last;
	public mylist(){
		root = null;
		last = null;
	}
	public Boolean isEmpty() {
		if(root==null) {
			return true;
		}else {
			return false;
		}
	}
	
	public void printlist() {
		listnode<ArrayList<Integer>> tmp = (listnode<ArrayList<Integer>>) root;
		while(tmp!=null) {
			System.out.print(tmp.getData().get(0)+" " + tmp.getData().get(1) + "/ ");
			tmp = tmp.getNext();
		}
	}
	
	public listnode<T> getroot(){
		return root;
	}
	public listnode<T> getlast(){
		return last;
	}
	public void insert(T obj) {
		if(root==null) {
			root = new listnode<T>(obj);
			last = root;
			return;
		}
		last.setNext(new listnode<T>(obj));
		last = last.getNext();
	}
}

class listnode<T>{
	private T data;
	private listnode<T> next;
	public listnode(T d){
		this.data = d;
		next = null;
	}
	public T getData() {
		return data;
	}
	public listnode<T> getNext() {
		return next;
	}
	public void setNext(listnode<T> xx) {
		next = xx;
	}
}
