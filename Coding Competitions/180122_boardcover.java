package my;
import java.util.Scanner;

public class jan223 {
	
	static int[][][] coverType = {
			{{0,0},{0,1},{1,0}},
			{{0,0},{0,1},{1,1}},
			{{0,0},{1,0},{1,1}},
			{{0,0},{1,0},{1,-1}}
	};
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int M = sc.nextInt();
		for(int z = 0 ; z < M ; z++) {
			int height = sc.nextInt();
			int width = sc.nextInt();
			int[][] board = new int[height][width];
			for(int i = 0 ; i < height ; i++) {
				
				char[] tmp = sc.next().toCharArray();
				for(int j = 0 ; j < width ; j++) {
					if(tmp[j]=='#') {
						board[i][j]=1;
					}else {
						board[i][j]=0;
					}
				}
			}
			
		System.out.println(cover(board));	
		}
		
		
	}
	
	static int cover(int[][] board) {
		int x = -1;
		int y = -1;
		boolean flag = false;
		for(int i = 0 ; i < board.length;i++) {
			for(int j = 0 ; j < board[0].length;j++) {
				if(board[i][j]==0) {
					
					x= i;
					y = j;
					//System.out.println("Search : " + x + " " + y);
					flag = true;
					break;
				}
			}
			if(flag==true) {
				break;
			}
		}
		if(x==-1) {
			return 1;
		}
		int ret = 0;
		
		//검증 부분
		for(int i = 0 ; i < 4 ; i++) {
			boolean ok = true;
			int[] nx = new int[3];
			int[] ny = new int[3];
			for(int j = 0 ; j < 3 ; j++) {
				nx[j] = x + coverType[i][j][0];
				ny[j] = y + coverType[i][j][1];
				if(!(nx[j]>=0&&ny[j]>=0&&nx[j]<board.length&&ny[j]<board[0].length&&board[nx[j]][ny[j]]==0)) {
					ok=false;
					break;
				}
			}
			if(ok==true) {
				/*(System.out.println("oktrue");
				for(int q = 0 ; q < 3 ; q++) {
					System.out.println("add " + nx[q] + " " + ny[q]);
				}*/
				//System.out.println("Fill");
				for(int k = 0 ; k < 3 ; k++) {
					board[nx[k]][ny[k]] = 1;
				}
				/*for(int q = 0 ; q < board.length;q++) {
					for(int w = 0 ; w < board[0].length;w++) {
						System.out.print(board[q][w]);
					}
					System.out.println();
				}
				System.out.println("-----------------");*/
				ret += cover(board);
				//System.out.println("Remove");
				for(int k = 0 ; k < 3 ; k++) {
					board[nx[k]][ny[k]] = 0;
				}
			}
			
		}
		return ret;
}
}
