// ConsoleApplication3.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//
#include "stdafx.h"
#include <iostream>

using namespace std;

int plength = 0;

int twoleft(int* p);

int main()
{	
	int M;
	cin >> M;
	for (int z = 0; z < M; z++) {
		int N, K;
		cin >> N >> K;
		int *p = new int[N];
		for (int i = 0; i < N; i++) {
			p[i] = 0;
		}
		p[0] = 1;
		plength = N;
		int sam = N;
		int curr = 1;
		while (sam != 3) {
			int tmp = K;
			while (tmp > 0) {
				if (p[curr] == 0) {
					tmp--;
					if (tmp == 0) {
						break;
					}
				}
				curr++;
				if (curr == N) {
					curr = 0;
				}
			}
			p[curr] = 1;
			sam--;
		}
		for (int i = 0; i < N; i++) {
			if (p[i] == 0) {
				cout << i+1 << " ";
			}
		}
		cout << endl;
	}
	while (1) {}
    return 0;
}

int twoleft(int * p) {
	int count = 0;
	for (int i = 0; i < plength; i++) {
		if (p[i] == 0) {
			count++;
		}
	}
	if (count == 2) {
		return 0;
	}
	else {
		return 1;
	}
}
