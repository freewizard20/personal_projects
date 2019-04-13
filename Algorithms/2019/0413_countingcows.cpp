#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int n;
int q;
int numbers[100000];
int c[100000][3];

int main() {

	int t;
	scanf("%d", &t);
	for (int z = 0; z < t; z++) {
		scanf("%d %d", &n, &q);
		for (int i = 0; i < n; i++) {
			int tmp;
			scanf("%d", &tmp);
			if (i == 0) {
				c[0][0] = 0;
				c[0][1] = 0;
				c[0][2] = 0;
				c[0][tmp - 1]++;
			}
			else {
				c[i][0] = c[i - 1][0];
				c[i][1] = c[i - 1][1];
				c[i][2] = c[i - 1][2];
				c[i][tmp - 1]++;
			}
		}
		printf("#%d\n", z + 1);
		for (int i = 0; i < q; i++) {
			int from, to;
			scanf("%d %d", &from, &to);
			printf("%d %d %d\n", c[to-1][0] - c[from - 2][0], c[to-1][1] - c[from - 2][1], c[to-1][2] - c[from-2][2]);
		}
		
	}

}
