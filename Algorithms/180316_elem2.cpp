#include "stdafx.h"
#include <cstdio>

int main() {
	int rm[3];
	for (int i = 0; i < 3; i++) {
		scanf("%d", &rm[i]);
	}
	int N;
	scanf("%d", &N);
	int ok = 0;
	for (int i = 0; i < N / rm[0]; i++) {
		for (int j = 0; j < N / rm[1]; j++) {
			for (int k = 0; k < N / rm[2]; k++) {
				int tot = i * rm[0] + j * rm[1] + k * rm[2];
				if (tot == N) {
					ok = 1;
				}
			}
		}
	}
	printf("%d", ok);
}
