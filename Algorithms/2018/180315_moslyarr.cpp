#include "stdafx.h"
#include <iostream>

using namespace std;

int * func(int tmp[]);
int * func(int * tmp, int N);
int * tob(long long given);
void fill();

int test = 3232;

int main6() {
	int test = 11;
	cout << test << endl;
	while (1) {}
	return 0;
}

int main5() {
	int * ret = new int[10];
	for (int i = 0; i < 10; i++) {
		ret[i] = i;
	}
	for (int i = 0; i < 10; i++) {
		cout << ret[i] << endl;
	}
	while (1) {}
	return 0;
}

long long pivot[65];

int main() {
	int M;
	cin >> M;
	for (int z = 0; z < M; z++) {
		fill();
		long long sam;
		cin >> sam;
		int ret = 0;
		if (sam == 1) {

		}else if (sam == 2 || sam == 3) {
			ret = 1;
		}
		else {
			int k = 0;
			while (sam >= pivot[k]) {
				k++;
			}
			if (k % 2 == 0) {
				ret = 1;
			}else {
				ret = 0;
			}
		}
		if (ret == 1) {
			cout << "#" << (z + 1) << " " << "Alice" << endl;
		}
		else {
			cout << "#" << (z + 1) << " " << "Bob" << endl;
		}
	}
	while (1) {}
	return 0;
}

void fill() {
	int i = 0;
	while (1) {
		long long target = 1;
		if (i % 2 != 0) {
			for (int j = 0; j < i; j++) {
				if (j % 2 != 0) {
					target = 2 * target + 1;
				}
				else {
					target = 2 * target;
				}
			}
		}
		else {
			for (int j = 0; j < i; j++) {
				if (j % 2 != 0) {
					target = 2 * target;
				}
				else {
					target = 2 * target+1;
				}
			}
		}
		if (target > 1000000000000000000) {
			break;
		}
		pivot[i] = target;
		i++;
	}
}

int * tob(long long given) {
	long long tmp = given;
	int * ret = new int[50];
	int i = 0;
	while (tmp != 0) {
		if (tmp % 2 == 0) {
			ret[i] = 0;
		}
		else {
			ret[i] = 1;
			tmp--;
		}
		tmp = tmp / 2;
		i++;
	}
	ret[i] = 9999;
	return ret;
}

int main2() {
	int N;
	cin >> N;
	for (int z = 0; z < N; z++) {
		char given[20];
		scanf("%s", given);
		char given2[100];
	}
	return 0;
}

int main3() {
	int N;
	cin >> N;
	int * sam = new int[N];
	for (int i = 0; i < N; i++) {
		sam[i] = i;
	}
	sam = func(sam,N);
	for (int i = 0; i < 2 * N; i++) {
		cout << sam[i] << endl;
	}
	while (1) {}
	return 0;
}

int * func(int tmp[]) {
	int * a;
	return a;
}

int * func(int * tmp, int N) {
	int * ret = new int[2 * N];
	for (int i = 0; i < 2 * N; i++) {
		ret[i] = tmp[i%N];
	}
	return ret;
}
