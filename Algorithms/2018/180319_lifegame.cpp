#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int board[100][100];
int tmpboard[100][100];

int check(int x, int y) {
	if (x == 0 || y == 0 || x == 99 || y == 99) {
		return 0;
	}
	int count = 0;
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if (!(x==0&&y==0) && board[x + i][y + j] == 1) {
				count++;
			}
		}
	}
	if (count == 2) {
		return -1;
	}
	else if (count == 3) {
		return 1;
	}
	else {
		return 0;
	}
}

void reconstruct() {
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			int M = check(i, j);
			if (M == 0) {
				tmpboard[i][j] = 0;
			}
			else if(M==1) {
				tmpboard[i][j] = 1;
			}
			else {
				tmpboard[i][j] = (board[i][j] == 1) ? 0 : 1;
			}
		}
	}
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			board[i][j] = tmpboard[i][j];
		}
	}
}

int main() {
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			board[i][j] = 0;
		}
	}
	board[50][50] = 1;
	board[49][50] = 1;
	board[51][50] = 1;
	board[50][49] = 1;
	board[50][51] = 1;
	for (int k = 0; k < 100; k++) {
		reconstruct();
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				printf("%d", board[i][j]);
			}
			printf("\n");
		}
		printf("----\n");
	}
}
