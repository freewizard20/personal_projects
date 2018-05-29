//Three Months!!

#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

int easyfunc();
int merge(int * A, int p , int q, int r);
int mergesort(int * A, int p, int r);

int main() {
	int N;
	cout << "Mergesort! type arr size" << endl;
	cin >> N;
	int *A = (int *)malloc(sizeof(int)*N);
	for (int i = 0; i < N; i++) {
		cin >> *(A + i);
	}
	mergesort(A, 0, N-1);
	for (int i = 0; i < N; i++) {
		cout << *(A + i) << endl;
	}
	free(A);
	return 0;
}

int easyfunc() {
	cout << "Hello! from easyfunc" << endl;
	return 0;
}

int merge(int * A,int p,int q,int r) {
	cout << "merge called" << endl;
	int n1,n2;
	n1 = q - p + 1;
	n2 = r - q;
	int * L = (int *)malloc(sizeof(int)*(n1+1));
	int * R = (int *)malloc(sizeof(int)*(n2+1));
	for (int i = 0; i < n1; i++) {
		*(L + i) = *(A + p + i);
	}
	for (int j = 0; j < n2; j++) {
		*(R + j) = *(A + q + j + 1);
	}
	*(L + n1) = 9999;
	*(R + n2) = 9999;
	int i = 0;
	int j = 0;
	for (int k = p; k < r+1; k++) {
		if (*(L+i)<=*(R+j)) {
			*(A + k) = *(L + i);
			i = i + 1;
		}
		else {
			*(A + k) = *(R + j);
			j = j + 1;
		}
	}
	free(L);
	free(R);
	return 0;
}

int mergesort(int * A, int p , int r) {
	cout << "mergesort called" << endl;
	if (p < r) {
		int q;
		q = (int)floor((p+r)/2);
		mergesort(A,p,q);
		mergesort(A,q+1,r);
		merge(A,p,q,r);
	}
	return 0;
}
