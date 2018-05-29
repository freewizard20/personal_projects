#include "stdafx.h"
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

void func(vector<int> arr);
void func2(vector<int> & arr);

int refarr[100000];
int resarr[100000];
int com[1000000][2];
int N;

int main(){
	srand(time(NULL));
	printf("test case size\n");
	int M;
	int c = 0;
	scanf("%d", &M);
	for (int z = 0; z < M; z++) {
		N = (rand() * rand())%10000;
		vector<int> rr;
		for (int i = 0; i < N; i++) {
			rr.push_back(i);
		}
		for (int i = N, j = 0; i > 0; i--, j++) {
			int t = (rand()*rand()) % i;
			refarr[j] = rr.at(t);
			rr.erase(rr.begin() + t);
		}
		int count = 0;
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				if (refarr[i] > refarr[j]) {
					if (count < 1000000) {
						com[count][0] = i;
						com[count][1] = j;
					}
					count++;
				}
			}
		}
		if (count >= 1000000) {
			printf("bound exceeded\n");
			z--;
			continue;
		}
		rr.clear();
		for (int i = 0; i < N; i++) {
			rr.push_back(i);
		}
		int curr = 0;
		int index = 0;
		while (curr < N) {
			int cnt = 0;
			while (index<count && curr == com[index][0]) {
				cnt++;
				index++;
			}
			resarr[curr] = rr.at(cnt);
			rr.erase(rr.begin() + cnt);
			curr++;
		}
		/*
		int ccount = 0;
		for (int i = 0; i < count; i++) {
			if (curr < com[i][0]) {
				resarr[curr] = rr.at(ccount);
				rr.erase(rr.begin() + ccount);
				curr++;
				i--;
				ccount = 0;
				
			}
			else {
				ccount++;
			}
		}
		while (curr < N) {
			resarr[curr] = rr.back();
			rr.erase(rr.end()-1);
			curr++;
		}
		*/
		int ret = 1;
		for (int i = 0; i < N; i++) {
			if (resarr[i] != refarr[i]) {
				ret = 0;
			}
		}
		if (ret == 1) {
			//printf("match\n");
			c++;
		}
		else {
			//printf("error\n");
		}
	}
	printf("%f", (double)c / M);
	while (1) {}
	return 0;
}#include "stdafx.h"
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

void func(vector<int> arr);
void func2(vector<int> & arr);

int refarr[100000];
int resarr[100000];
int com[1000000][2];
int N;

int main(){
	srand(time(NULL));
	printf("test case size\n");
	int M;
	int c = 0;
	scanf("%d", &M);
	for (int z = 0; z < M; z++) {
		N = (rand() * rand())%10000;
		vector<int> rr;
		for (int i = 0; i < N; i++) {
			rr.push_back(i);
		}
		for (int i = N, j = 0; i > 0; i--, j++) {
			int t = (rand()*rand()) % i;
			refarr[j] = rr.at(t);
			rr.erase(rr.begin() + t);
		}
		int count = 0;
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				if (refarr[i] > refarr[j]) {
					if (count < 1000000) {
						com[count][0] = i;
						com[count][1] = j;
					}
					count++;
				}
			}
		}
		if (count >= 1000000) {
			printf("bound exceeded\n");
			z--;
			continue;
		}
		rr.clear();
		for (int i = 0; i < N; i++) {
			rr.push_back(i);
		}
		int curr = 0;
		int index = 0;
		while (curr < N) {
			int cnt = 0;
			while (index<count && curr == com[index][0]) {
				cnt++;
				index++;
			}
			resarr[curr] = rr.at(cnt);
			rr.erase(rr.begin() + cnt);
			curr++;
		}
		/*
		int ccount = 0;
		for (int i = 0; i < count; i++) {
			if (curr < com[i][0]) {
				resarr[curr] = rr.at(ccount);
				rr.erase(rr.begin() + ccount);
				curr++;
				i--;
				ccount = 0;
				
			}
			else {
				ccount++;
			}
		}
		while (curr < N) {
			resarr[curr] = rr.back();
			rr.erase(rr.end()-1);
			curr++;
		}
		*/
		int ret = 1;
		for (int i = 0; i < N; i++) {
			if (resarr[i] != refarr[i]) {
				ret = 0;
			}
		}
		if (ret == 1) {
			//printf("match\n");
			c++;
		}
		else {
			//printf("error\n");
		}
	}
	printf("%f", (double)c / M);
	while (1) {}
	return 0;
}
