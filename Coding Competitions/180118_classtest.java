package my;

public class classtest {
	public static void main(String[] args) {
		BST sam = new BST();
		sam.insert(5);
		sam.insert(4);
		sam.insert(7);
		sam.insert(12);
		sam.insert(15);
		sam.scan(sam.root);
		BNode ret = sam.search(15);
		if(ret == null) {
			System.out.println("not found");
		}else {
			System.out.println("found");
		}
		System.out.println(sam.minimum());
		System.out.println(sam.maximum());
		System.out.println(sam.sucessor(4));
		sam.insert(6);
		System.out.println(sam.predecessor(7));
		System.out.println(sam.minimum());
		System.out.println(sam.maximum());
	}
}
