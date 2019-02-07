package my;

import java.util.Scanner;
import java.util.Vector;

public class game{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int M = sc.nextInt();
		int N = sc.nextInt();
		sc.nextLine();
		char[][] board = new char[M][N];
		for(int i = 0 ; i <M ; i++){
			board[i] = sc.nextLine().toCharArray();
		}
		int fin = 0;
		int count = 0;
		while(fin==0){
			Vector<int[]> erase = new Vector<int[]>();
			fin = finderase(board,erase);
			if(fin==1){break;}
			erase2(board,erase);
			gravity(board);
		}
		for(int i = 0 ; i < M ; i++) {
			for(int j = 0 ; j < N ; j++) {
				if(board[i][j]=='#') {
					count++;
				}
			}
		}
		System.out.println(count);
	}
	
	static int finderase(char [][] board, Vector<int[]> erase){
		for(int i = 0 ; i < board.length ; i++){
			for(int j = 0 ; j < board.length ; j++){
				try{
				if(board[i][j]==board[i+1][j]&&board[i][j]==board[i][j+1]&&board[i][j]==board[i+1][j+1]&& board[i][j]!='#'){
				int[] tmp = {i,j};
				erase.add(tmp);
				int[] tmp2 = {i+1,j};
				erase.add(tmp2);
				erase.add(new int[]{i,j+1});
				erase.add(new int[]{i+1,j+1});
				}
				}catch(Exception e){}
			}
		}
		if(erase.size()==0){
			return 1;
		}else{
			return 0;
		}
	}

	static void erase2(char[][] board, Vector<int[]> erase){
		for(int i = 0 ; i < erase.size(); i++){
			board[erase.get(i)[0]][erase.get(i)[1]] = '#';
		}
	}

	static void gravity(char[][] board){
		boolean remain = true;
		while(remain){
			remain=false;
			for(int i = 0 ; i < board.length; i++){
				for(int j = 0 ; j < board[0].length ; j++){
					try{
					if(board[i][j]!='#'&&board[i+1][j]=='#'){
						board[i+1][j]=board[i][j];
						board[i][j]='#';
						remain=true;
					}}catch(Exception e){}
				}
			}
		}
	}
}

	
