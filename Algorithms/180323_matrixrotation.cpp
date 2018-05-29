#include "stdafx.h"
#include <iostream>

using namespace std;

void rotatematrix(int ** arr, int size) {
	for (int i = 0; i < size / 2; i++) {
		for (int j = i; j < size - i - 1; j++) {
			int tmp = arr[i][j];
			arr[i][j] = arr[j][size - i - 1];
			arr[j][size - i - 1] = arr[size - i - 1][size - j - 1];
			arr[size - i - 1][size - j - 1] = arr[size - j - 1][i];
			arr[size - j - 1][i] = tmp;
		}
	}
}

void rotatematrix2(int ** arr, int size) {
	int ** tmp = new int*[size];
	for (int i = 0; i < size; i++) {
		tmp[i] = new int[size];
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			tmp[size - 1 - j][i] = arr[i][j];
		}
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			arr[i][j] = tmp[i][j];
		}
	}
}


struct sam {
	int a;
	int b;
};

void arrtest(sam arr[]) {
	//arr[0] = 23; 안됨
	sam h1 = { 1,2 };
	arr[0] = h1;
	cout << "fuck" << endl;
}

int main() {
	int ** arr = new int*[10];
	for (int i = 0; i < 10; i++) {
		arr[i] = new int[10];
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			arr[i][j] = 10 * i + j;
		}
	}
	int ** buff = arr;
	rotatematrix2(buff, 10);
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	sam hogu[2] = { {3,4},{5,6} };
	arrtest(hogu);
	cout << hogu[0].a << " " << hogu[0].b << endl;
 	int arr3[5][5];
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			arr3[i][j] = i + j;
		}
	}
	//int brr[5][5]; brr = arr3; 이거 안됨
	int arr4[3] = { 1,2,3 };
	int brr4[3] = { 4,5,6 };
	//arr4 = brr4; 이거도 안됨!!
	while (1) {}
	return 0;
}
