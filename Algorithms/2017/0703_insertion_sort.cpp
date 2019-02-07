#include "stdafx.h"
#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;
	int i,j;
	int * listarr = (int *) malloc(sizeof(int)*N);
	for (i = 0; i < N; i++) {
		cin >> *(listarr + i);
	}
	
	for (i = 0; i < N; i++) {
		for (j = 0; j < i; j++) {
			int tmp;
			if (*(listarr + i) < *(listarr + j)) {
				tmp = *(listarr + j);
				*(listarr + j) = *(listarr + i);
				*(listarr + i) = tmp;
			}
		}
	}
	for (i = 0; i < N; i++) {
		cout << *(listarr + i) << endl;
	}
	free(listarr);
	return 0;
}
