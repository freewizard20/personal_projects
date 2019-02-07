#include "stdafx.h"
#include <iostream>

using namespace std;

int fibonacci(int n, int *t1, int *t2);

int main() {
	int a, b;
	int *t1;
	int *t2;
	a = 0;
	b = 0;
	t1 = &a;
	t2 = &b;
	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		*t1 = 0;
		*t2 = 0;
		int N;
		cin >> N;
		fibonacci(N, t1, t2);
		cout << *t1 << " " << *t2 << endl;
	}
	return 0;
}

int fibonacci(int n, int *t1, int *t2) {
	if (n == 0) {
		*t1 = *t1 + 1;
		return 0;
	}
	else if (n == 1) {
		*t2 = *t2 + 1;
		return 1;
	}
	else {
		return fibonacci(n - 1, t1, t2) + fibonacci(n - 2, t1, t2);
	}
}
