package my;
import java.util.Scanner;
import java.util.Vector;

class news {
	public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	String st1 = sc.nextLine();
	String st2 = sc.nextLine();
	st1 = st1.toLowerCase();
	st2 = st2.toLowerCase();
	char[] stc1 = st1.toCharArray();
	char[] stc2 = st2.toCharArray();
	Vector<String> firstset = new Vector<String>();
	Vector<String> secondset = new Vector<String>();
	for(int i = 0 ; i < stc1.length-1; i++) {
		if((!Character.isLetter(stc1[i]))||(!Character.isLetter(stc1[i+1]))){
			continue;
		}
		StringBuffer sb = new StringBuffer();
		sb.append(stc1[i]);
		sb.append(stc1[i+1]);
		firstset.add(sb.toString());
	}
	for(int i = 0 ; i < stc2.length-1; i++) {
		if((!Character.isLetter(stc2[i]))||(!Character.isLetter(stc2[i+1]))){
			continue;
		}
		StringBuffer sb = new StringBuffer();
		sb.append(stc2[i]);
		sb.append(stc2[i+1]);
		secondset.add(sb.toString());
	}
	Vector<String> cup = new Vector<String>();
	Vector<String> cap = new Vector<String>();
	int fit = firstset.size();
	for(int i = 0 ; i < firstset.size(); i++) {
		if(secondset.indexOf(firstset.get(i))!=-1) {
			cap.add(firstset.get(i));
			secondset.remove(firstset.get(i));
			firstset.remove(i);
			i--;
		}
	}
	for(int i = 0 ; i < cap.size();i++) {
		cup.add(cap.get(i));
	}
	for(int i = 0 ; i < firstset.size();i++) {
		cup.add(firstset.get(i));
	}
	for(int i = 0 ; i < secondset.size();i++) {
		cup.add(secondset.get(i));
	}
	double res;
	if(cup.size()==0&&cap.size()==0) {
		res=1;
	}else {
		res = (double) cap.size() / (double) cup.size();
		
	}
	double rr = res * 65536;
	int ret2 = (int) rr;
	System.out.println(ret2);
	}
}
