// ConsoleApplication1993.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <vector>
#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

int main() {
	time_t result = time(NULL);
	cout << result << endl;
	cout << asctime(localtime(&result)) << endl;
	while (1) {}
	return 0;
}


int main2()
{
	srand(time(NULL));
	vector<int> sample;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		sample.push_back(i);
	}
	vector<int> result;
	for (int i = N; i > 0; i--) {
		int target = rand() % i;
		result.push_back(sample.at(target));
		sample.erase(sample.begin() + target);
	}

	for (int i = 0; i < N; i++) {
		cout << result.at(i) << endl;
	}

	for (int i = 0; i < N; i++) {
		int flag = 0;
		for (int j = i-1; j >= 0; j--) {
			if (result.at(j) < result.at(i)) {
				cout << "swap " << i << " and " << j << endl;
				result.insert(result.begin() + j+1, result.at(i));
				result.erase(result.begin() + i + 1);
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			result.insert(result.begin(), result.at(i));
			result.erase(result.begin() + i + 1);
		}
	}

	for (int i = 0; i < N+1; i++) {
		cout << result.at(i) << endl;
	}
	while (1) {}
    return 0;
}

