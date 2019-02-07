package my;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class quadtree {
	
	static char[] given;
	static char[][] decompressed;
	static int mindepth;
	static int index;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int M = Integer.parseInt(br.readLine());
		for(int z = 0 ; z < M ; z++) {
			given = br.readLine().toCharArray();
			mindepth = 0;
			index=0;
			getdepth(0);
			int lng = (int) Math.pow(2,mindepth);
			System.out.println(lng);
			decompressed = new char[lng][lng];
			index=0;
			color(0,0,lng);
			for(int i = 0 ; i < lng ; i++) {
				for(int j = 0 ; j < lng ; j++) {
					System.out.print(decompressed[i][j]);
				}
				System.out.println();
			}
		}
	}
	
	static void color(int x, int y, int size) {
		if(given[index]=='w'||given[index]=='b') {
			for(int i = x ; i < x+size ; i++) {
				for(int j = y ; j < y+size ; j++) {
					decompressed[i][j] = given[index];
				}
			}
			index++;
		}else {
			index++;
			int nextsize = size/2;
			
			color(x,y,nextsize);
			
			color(x,y+nextsize,nextsize);
			
			color(x+nextsize,y,nextsize);
			
			color(x+nextsize,y+nextsize,nextsize);
		}
	}
	
	static void getdepth(int depth) {
		if(index>=given.length) {
			return;
		}
		if(given[index]=='w'||given[index]=='b') {
			mindepth = Math.max(depth, mindepth);
			index++;
		}else {
			index++;
			getdepth(depth+1);
		}
		if(index>=given.length) {
			return;
		}
		if(given[index]=='w'||given[index]=='b') {
			mindepth = Math.max(depth, mindepth);
			index++;
		}else {
			index++;
			getdepth(depth+1);
		}
		if(index>=given.length) {
			return;
		}
		if(given[index]=='w'||given[index]=='b') {
			mindepth = Math.max(depth, mindepth);
			index++;
		}else {
			index++;
			getdepth(depth+1);
		}
		if(index>=given.length) {
			return;
		}
		if(given[index]=='w'||given[index]=='b') {
			mindepth = Math.max(depth, mindepth);
			index++;
		}else {
			index++;
			getdepth(depth+1);
		}
	}
}
