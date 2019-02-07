#include "stdafx.h"
#include <cstdio>
#include <cmath>

int main() {
	int M;
	scanf("%d", &M);
	for (int z = 0; z < M; z++) {
		int na;
		int a = 0;
		scanf("%d", &na);
		for (int i = 0; i < na; i++) {
			int sam;
			scanf("%d", &sam);
			a += pow(10, sam);
		}
		int nb;
		int b = 0;
		scanf("%d", &nb);
		for (int i = 0; i < nb; i++) {
			int sam2;
			scanf("%d", &sam2);
			b += pow(10, sam2);
		}
		if (a > b) {
			printf("A\n");
		}
		else if (b > a) {
			printf("B\n");
		}
		else {
			printf("D\n");
		}
	}
	while (1) {}
	return 0;
}
