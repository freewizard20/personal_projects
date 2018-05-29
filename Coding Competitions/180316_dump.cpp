#include "stdafx.h"
#include <cstdio>
#include <cstring>

using namespace std;

int main() {
	int * arr = new int[10];
	memset(arr, 2, sizeof(int));
	for (int i = 0; i < 10; i++) {
		printf("%d\n", arr[i]);
	}
	while (1) {}
	return 0;
}

int main3() {
	char sam[10][20];
	for (int i = 0; i < 10; i++) {
		scanf("%s", sam[i]);
	}
	for (int i = 0; i < 10; i++) {
		printf("%s\n", sam[i]);
	}
	while (1) {}
	return 0;
}

/*int main2() {
	int M;
	scanf("%d", &M);
	for (int z = 0; z < M; z++) {
		int N, W;
		scanf("%d %d", &N, &W);
		char * namearr[] = new char[N][];
		int * weightarr = new int[N];
		int * pointarr = new int[N];
		for (int i = 0; i < N; i++) {
			scanf("%s %d %d", &namearr[i], &weightarr[i], &pointarr[i]);
		}
		for (int i = 0; i < N; i++) {
			printf("%s %d %d\n", namearr[i], weightarr[i], pointarr[i]);
		}
	}
	while (1) {}
	return 0;
}*/
