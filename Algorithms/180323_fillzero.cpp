#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

void fillzero(int ** arr, int rl, int cl) {
	vector<int> rows; // rl
	vector<int> columns; // cl
						 // iterate row
	for (int i = 0; i < rl; i++) {
		for (int j = 0; j < cl; j++) {
			if (arr[i][j] == 0) {
				rows.push_back(i);
				break;
			}
		}
	}
	// iterate column
	for (int j = 0; j < cl; j++) {
		for (int i = 0; i < rl; i++) {
			if (arr[i][j] == 0) {
				columns.push_back(j);
				break;
			}
		}
	}

	// fill zeroes - row
	for (int z = 0; z < rows.size(); z++) {
		for (int i = 0; i < cl; i++) {
			arr[rows.at(z)][i] = 0;
		}
	}

	// fill zeroes - column
	for (int z = 0; z < columns.size(); z++) {
		for (int i = 0; i < rl; i++) {
			arr[i][columns.at(z)] = 0;
		}
	}
}


int main() {
	int ** arr = new int *[5];
	for (int i = 0; i < 5; i++) {
		arr[i] = new int[3];
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 3; j++) {
			arr[i][j] = 10 * i + j;
		}
	}
	//arr[2][1] = 0;
	fillzero(arr,5,3);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 3; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	while (1) {}
	return 0;
}
