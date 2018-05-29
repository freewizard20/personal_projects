package my;

import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.Vector;

public class filesystem {
	static inode root = new inode("root",-1,true);
	static inode curr = root.sibling;
	
	static public void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while(true) {
			StringTokenizer st = new StringTokenizer(sc.nextLine());
			String order = st.nextToken();
			switch(order) {
			case "ls":
				whereami();
				printcurr();
				break;
			case "cd":
				moveto(st.nextToken());
				break;
			case "mkdir":
				make(st.nextToken(),-1,true);
				break;
			case "mkfile":
				try {
				make(st.nextToken(),Integer.parseInt(st.nextToken()),false);
				}catch (Exception e){
				System.out.println("error on filesize");
				}
				break;
			case "del":
				dell(st.nextToken());
				break;
			case "curr":
				System.out.println(curr.filename);
				break;
			case "tree":
				printtree(root,0);
				break;
			}
		}
	}
	
	static void printtree(inode nd, int depth) {
		while(nd!=null) {
			if(nd.filename.equals("..")) {
				
			}else {
				for(int i = 0 ; i < depth ; i++) {
					System.out.print(" ");
				}
				if(nd.isdirectory) {
					System.out.println(nd.filename+" directory");
				}else {
				System.out.println(nd.filename + " " + nd.filesize);
				}
				if(nd.isdirectory) {
					printtree(nd.sibling,depth+1);
				}
			}
			nd = nd.nextbrother;
		}
	}
	
	static void dell(String fname) {
		if(fname.equals("..")) {
			System.out.println("error: cannot delete root subdirectory");
			return;
		}
		inode tmp = curr;
		inode tmpc = curr;
		while(tmp!=null) {
			if(tmp.filename.equals(fname)) {
				if(tmp.nextbrother==null) {
					tmpc.nextbrother = null;
					return;
				}else {
					tmpc.nextbrother = tmp.nextbrother;
					return;
				}
			}
			tmpc = tmp;
			tmp = tmp.nextbrother;
		}
		System.out.println("no such file/directory");
	}
	
	static void make(String fname, int fsize,boolean isdir) {
		inode tmp = curr;
		while(tmp.nextbrother!=null) {
			tmp = tmp.nextbrother;
		}
		inode newnode = new inode(fname,fsize,isdir);
		newnode.parent = curr.parent;
		tmp.nextbrother = newnode;
	}
	
	static void whereami() {
		inode tmp = curr;
		Vector<String> names = new Vector<String>();
		while(tmp!=root) {
			if(!tmp.filename.equals("..")) {
				names.add(tmp.filename);
			}
			tmp = tmp.parent;
		}
		StringBuffer sb = new StringBuffer();
		sb.append("/");
		for(int i = names.size()-1;i>=0;i--) {
			sb.append(names.get(i));
			sb.append("/");
		}
		System.out.println(sb.toString());
	}
	
	static void printcurr() {
		inode tmp = curr;
		tmp = tmp.parent;
		tmp = tmp.sibling;
		while(tmp!=null) {
			if(tmp.filename.equals("..")) {
				System.out.println("..");
			}else {
				if(tmp.isdirectory==true) {
					System.out.println(tmp.filename+ " directory");
				}else {
			System.out.println(tmp.filename + " " + tmp.filesize);
				}}tmp = tmp.nextbrother;
		}
	}
	
	static void moveto(String dest) {
		if(dest.equals("..")) {
			if(curr==root.sibling) {
				return;
			}else {
				curr = curr.parent.parent.sibling;
				return;
			}
		}
		
		inode tmp = curr;
		tmp = tmp.parent;
		tmp = tmp.sibling;
		while(tmp!=null) {
			if(tmp.filename.equals(dest) && tmp.isdirectory == true) {
				curr = tmp.sibling;
				return;
			}
			tmp = tmp.nextbrother;
		}
		System.out.println("no such directory");
	}
}

class inode{
	String filename;
	int filesize;
	boolean isdirectory;
	inode parent;
	inode sibling;
	inode nextbrother;
	inode() {
		this.filename = "hello.txt";
		this.filesize = 1;
		this.isdirectory = false;
	}
	inode(String filename, int filesize, boolean isdirectory) {
		this.filename = filename;
		this.filesize = filesize;
		this.isdirectory = isdirectory;
		if(isdirectory==true) {
			inode tmp = new inode("..",0,false);
			tmp.parent = this;
			this.sibling = tmp;
		}
	}
}
