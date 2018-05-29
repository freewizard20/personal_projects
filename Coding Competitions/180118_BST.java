package my;

public class BST {
	BNode root;
	
	
	void insert(int z) {
		if(this.root==null) {
			this.root = new BNode(z);
			return;
		}else {
			BNode x = this.root;
			BNode y=new BNode(0);
			while(x!=null) {
				y=x;
				if(x.key>z) {
					x = x.left;
				}else {
					x = x.right;
				}
			}
			if(y.key>z) {
				y.left = new BNode(z);
				y.left.parent = y;
				return;
			}else {
				y.right=new BNode(z);
				y.right.parent = y;
				return;
			}
		}
	}
	
	void scan(BNode x) {
		if(x!=null) {
			scan(x.left);
			System.out.print(x.key+" ");
			scan(x.right);
		}
	}
	
	BNode search(int k) {
		BNode x = this.root;
		if(x==null) {
			return null;
		}else {
			while(x!=null) {
				if(x.key==k) {
					return x;
				}else if(x.key>k) {
					x=x.left;
				}else {
					x=x.right;
				}
			}
			return null;
		}
	}
	
	int minimum() {
		if(this.root==null) {
			return -1;
		}
		BNode x = this.root;
		BNode y = this.root;
		while(x!=null) {
			y=x;
			x=x.left;
		}
		return y.key;
	}
	
	int maximum() {
		if(this.root==null) {
			return -1;
		}
		BNode x = this.root;
		BNode y = this.root;
		while(x!=null) {
			y=x;
			x=x.right;
		}
		return y.key;
	}
	
	int sucessor(int key) {
		if(search(key)==null) {
			return -1;
		}else {
			BNode x = search(key);
			BNode y = x.right;
			if(y==null) {
				return x.parent.key;
			}else {
				BNode z=y;
				while(y!=null) {
					z = y;
					y=y.left;
				}
				return z.key;
			}
		}
	}
	
	int predecessor(int key) {
		if(search(key)==null) {
			return -1;
		}else {
			BNode x = search(key);
			BNode y = x.left;
			if(y==null) {
				return x.parent.key;
			}else {
				BNode z = y;
				while(y!=null) {
					z = y;
					y = y.left;
				}
				return z.key;
			}
		}
		
	}
	
	int minimum(BNode x) {
		if(x.left==null) {
			return x.key;
		}else {
			return minimum(x.left);
		}
	}
	
	int maximum(BNode x) {
		if(x.right==null) {
			return x.key;
		}else {
			return minimum(x.right);
		}
	}
}
