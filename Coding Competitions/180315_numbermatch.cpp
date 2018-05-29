#include "stdafx.h"
#include <cstdio>
#include <vector>

using namespace std;

int main2() {
	for (int i = 0; i < 10; i++) {
		vector<int> pave;
		pave.push_back(i);
		printf("%d\n", pave.size());
	}
	while (1) {}
}

int main() {
	int M;
	scanf("%d", &M);
	for (int z = 0; z < M; z++) {
		int N;
		scanf("%d", &N);
		int * arr = new int[N];
		for (int i = 0; i < N; i++) {
			scanf("%d", &arr[i]);
		}
		int find = 0;
		while (1) {
			vector<int> pave;
			int tmp = find;
			if (tmp == 0) {
				pave.push_back(0);
			}
			while (tmp != 0) {
				pave.insert(pave.begin(), tmp % 10);
				tmp = tmp / 10;
			}
			bool found = false;
			for (int i = 0; i < N; i++) {
				if (pave.at(0) == arr[i]&& pave.size()+i<=N) {
					found = true;
					for (int j = 0; j < pave.size(); j++) {
						if (pave.at(j) != arr[i + j]) {
							found = false;
							break;
						}
					}
					if (found == true) {
						break;
					}
				}
			}
			if (found == false) {
				break;
			}
			find++;
		}
		printf("#%d %d\n", z + 1, find);
	}
	while (1) {}
}
