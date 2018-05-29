package my;
import java.util.Vector;
import java.util.Arrays;
import java.util.Scanner;

public class clocks {
	
	static int [][] buttons = {
			{1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},//0
			{0,0,0,1,0,0,0,1,0,1,0,1,0,0,0,0},
			{0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,1},//2
			{1,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,1,1,1,0,1,0,1,0,0,0},//4
			{1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1},
			{0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,1},//6
			{0,0,0,0,1,1,0,1,0,0,0,0,0,0,1,1},
			{0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,1,1,1,0,0,0,1,0,0,0,1,0,0}
	};
	
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int M = sc.nextInt();
		for(int z = 0 ; z < M ; z++) {
			int[] clocks = new int[16];
			for(int i = 0 ; i < 16 ; i++) {
				clocks[i] = sc.nextInt();
			}
			int[] button = new int[10];
			Arrays.fill(button, 0);
			int tmp = solve(clocks,button,10);
			if(tmp==9999) {
				System.out.println(-1);
			}else {
				System.out.println(tmp);
			}
			
		}
	}
	
	
	static boolean arealligned(int[] clocks) {
		boolean ret = true;
		for(int i = 0 ; i < clocks.length ; i++) {
			if(clocks[i]!=12) {
				ret = false;
				break;
			}
		}
		return ret;
	}
	
	static int[] push2(int[] clocks, int button) {
		for(int i = 0 ; i < 16 ; i++) {
			if(buttons[button][i]==1) {
				clocks = push(clocks,i);
			}
		}
		return clocks;
	}
	
	static int[] push(int [] clocks, int button) {
		if(clocks[button]==12) {
			clocks[button]=3;
		}else {
			clocks[button] = clocks[button]+3;
		}
		return clocks;
	}
	
	static int[] unpush2(int[] clocks, int button) {
		for(int i = 0 ; i < 16 ; i++) {
			if(buttons[button][i]==1) {
				clocks = unpush(clocks,i);
			}
		}
		return clocks;
	}
	
	static int[] unpush(int [] clocks, int button) {
		if(clocks[button]==3) {
			clocks[button]=12;
		}else {
			clocks[button] = clocks[button]-3;
		}
		return clocks;
	}
	
	static int solve(int[] clocks,int[] button, int repeat) {
		if(repeat ==0) {
			/*int [] tmp = clocks.clone();
			for(int i = 0 ; i < button.length ; i++) {
				for(int j = 0 ; j < button[i]; j++) {
					tmp = push2(tmp, i);
				}
			}*/
			if(arealligned(clocks)) {
				
				int total = 0;
				for(int i : button) {
					total += i;
				}
				return total;
			}else {
				return 9999;
			}
		}
		int times = 9999;
		for(int i = 0 ; i < 4 ; i++) {
			int tmp;
			tmp = button[repeat-1];
			button[repeat-1]=i;
			for(int j = 0 ; j < i ; j++) {
				push2(clocks,repeat-1);
			}
			times = Math.min(times, solve(clocks,button,repeat-1));
			button[repeat-1]=tmp;
			for(int j = 0 ; j < i ; j++) {
			unpush2(clocks,repeat-1);
			}
			}
		return times;
		}
	}

