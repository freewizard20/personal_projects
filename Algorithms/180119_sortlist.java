package my;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Collections;
import java.util.Random;
import java.util.Scanner;
import java.io.FileOutputStream;
import java.io.IOException;


public class classtest {
	public static void main(String[] args) throws IOException {
	Scanner sc = new Scanner(System.in);
	List<Hero> sam = new ArrayList();
	for(int i = 0 ; i < 100000; i++) {
		sam.add(randomHero());
	}
	System.out.println("done");
	String st="sam";
	int copy = 0;
	while(st!="9999") {
	System.out.println("정렬 방법?(9999 exit)");
	st = sc.nextLine();
	System.out.println(st);
	for(int i = 0 ; i < 100000; i++) {
		sam.get(i).key = st;
	}
	System.out.println("sort");
	Collections.sort(sam);
	System.out.println("sort end");
	int tat = 0;
	for(int i = 0 ; i < 99999; i++) {
		if(sam.get(i).attack>sam.get(i+1).attack) {
			tat++;
		}
	}
	System.out.println(tat + " errors found");
	StringBuffer sb = new StringBuffer();
	sb.append("C:\\Users\\okjin\\Desktop\\out");
	sb.append(new Integer(copy).toString());
	sb.append(".txt");
	FileOutputStream output = new FileOutputStream(sb.toString());
	String data = "이름 별 레벨 공격력 체력 마나 가격\n";
	output.write(data.getBytes());
	for(int i = 0 ; i < 100000; i++) {
		data = sam.get(i).name + " " + sam.get(i).stars + " " + sam.get(i).level + " " + sam.get(i).attack + " " + sam.get(i).hp + " " + sam.get(i).mana + " " + sam.get(i).price + "\n";
		output.write(data.getBytes());
	}
	output.close();
	copy++;
	}
	
	}
	
	
	
	static Hero randomHero() {
		Hero ret = new Hero();
		StringBuffer temp = new StringBuffer();
		Random rnd = new Random();
		for (int i = 0; i < 20; i++) {
		    int rIndex = rnd.nextInt(3);
		    switch (rIndex) {
		    case 0:
		        // a-z
		        temp.append((char) ((int) (rnd.nextInt(26)) + 97));
		        break;
		    case 1:
		        // A-Z
		        temp.append((char) ((int) (rnd.nextInt(26)) + 65));
		        break;
		    case 2:
		        // 0-9
		        temp.append((rnd.nextInt(10)));
		        break;
		    }
		}
		ret.name = temp.toString();
		ret.hp = randomInt(10000);
		ret.level = randomInt(60);
		ret.mana = randomInt(2000);
		ret.price = randomInt(500);
		ret.stars = randomInt(6);
		ret.attack = randomInt(50000);
		
		return ret;
		//name, hp, mana, level, attack, stars,price
	}
	
	static int randomInt(int scale) {
		return (int) Math.ceil(Math.random()*scale);
	}
}
